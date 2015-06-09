/* This is a test of syscalls, particularly with the tricky sockaddr structure. */

/* Some example code was copied from http://www.gnu.org/software/libc/manual/ */

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

const unsigned int PORT = 8086;

// The shared memory is used for a semaphore and a general buffer to test read
// and write speed.

const unsigned int SHM_SIZE = 4096;
const unsigned int SEMAPHORE_SIZE = sizeof(sem_t);

void run_server(unsigned char* sharedmem)
{
  int socket_server;
  struct sockaddr_in name;

  /* Create the socket. */
  socket_server = socket (PF_INET, SOCK_STREAM, 0);
  if (socket_server < 0) {
    perror ("socket");
    exit (EXIT_FAILURE);
  }
  int iSetOption = 1;
  setsockopt(socket_server, SOL_SOCKET, SO_REUSEADDR, (char*)&iSetOption,
    sizeof(iSetOption));

  /* Give the socket a name. */
  name.sin_family = AF_INET;
  name.sin_port = htons (PORT);
  printf("Stored port, converted to network order, as 0x%4.4X\n",name.sin_port);
  name.sin_addr.s_addr = htonl (INADDR_ANY);
  unsigned char* port_memory = (unsigned char*) &name.sin_port;
  printf("Layout of port number in memory: %2.2X %2.2X\n", port_memory[0], port_memory[1]);

  if (bind (socket_server, (struct sockaddr *) &name, sizeof (name)) < 0) {
    perror ("bind");
    exit (EXIT_FAILURE);
  }
  
  if (listen (socket_server, 1) < 0) {
    perror ("listen");
    exit (EXIT_FAILURE);
  }

  int socket;
  struct sockaddr_in clientname;
  socklen_t size;
  unsigned int tempValue;
  int i,j;

  sem_post( (sem_t*) sharedmem);
  size = sizeof(struct sockaddr_in);
  socket = accept (socket_server, (struct sockaddr *) &clientname, &size);
  if (socket < 0) {
    perror ("accept");
    exit (EXIT_FAILURE);
  }
  printf ("Server: connect from address %s\n", inet_ntoa(clientname.sin_addr));

  // Read from the socket and write the value into shared memory
  unsigned int* intSharedMem = (unsigned int*) sharedmem;
  read(socket, &tempValue, 4);
  
  for(j=0;j < 1000000000; j++) {
    for(i=0; i<((SHM_SIZE-SEMAPHORE_SIZE)/sizeof(unsigned int)); i++) {
      intSharedMem[(SEMAPHORE_SIZE/sizeof(unsigned int))+i] = j;
    }
  }
  intSharedMem[0] = tempValue;
  
  fflush(stdout); // Do not print anything further
  sem_post( (sem_t*) sharedmem);
  close(socket);
}

void run_client(unsigned char* sharedmem)
{
  struct sockaddr_in serv_addr;
  const unsigned int test_value = 0xDEADBEEF;

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(0x7F000001);
  serv_addr.sin_port = htons(PORT);

  sem_wait( (sem_t*) sharedmem);

  if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Write a test value to the socket. The client should store this into the shared memory.
  write(sockfd, (unsigned char*) &test_value, 4);

  sem_wait( (sem_t*) sharedmem);
  // Do not print anything until the server has finished (otherwise output will be nondeterministic)
  printf("Data in shared memory: %2.2X %2.2X %2.2X %2.2X\n",sharedmem[0], sharedmem[1], sharedmem[2], sharedmem[3]);
}

int main()
{
  int sharedmemorykey = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0777);
  if(sharedmemorykey == -1) {
    perror("shmget");
    exit(EXIT_FAILURE);
  }

  // Attach shared memory.
  void* shmaddr = shmat(sharedmemorykey, NULL, 0);
  if(shmaddr == (void*) -1) {
    perror("shmat");
    exit(EXIT_FAILURE);
  }

  if(sem_init( (sem_t*) shmaddr + 4, 1, 0)) {
    perror("sem_init");
    exit(EXIT_FAILURE);
  }

  int pid = fork();
  if(pid==-1) {
    perror ("fork");
    exit (EXIT_FAILURE);
  }

  if(pid==0) {
    run_client((unsigned char*) shmaddr);
  } else {
    run_server((unsigned char*) shmaddr);
    waitpid(pid, NULL, 0);
  }

  // Detach shared memory.
  shmdt(shmaddr);

  return 0;
}
