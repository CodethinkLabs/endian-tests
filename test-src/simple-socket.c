/* This is a simple test of syscalls, particularly with the tricky sockaddr structure. */

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

const unsigned int PORT = 8086;
const unsigned int STDOUT = 1;

void writeHex(unsigned int x)
{
  int i;
  write(STDOUT, "0x", 2);
  for(i=7;i>=0;i--) {
    int digit = ((x >> i*4) & 0xF);
    write(STDOUT,  "0123456789ABCDEF"+digit, 1);
  }
}

void run_server()
{
  int socket_server;
  struct sockaddr_in name;

  /* Create the socket. */
  socket_server = socket (PF_INET, SOCK_STREAM, 0);
  if (socket_server < 0) {
    perror ("socket");
    exit (EXIT_FAILURE);
  }

  /* Give the socket a name. */
  name.sin_family = AF_INET;
  name.sin_port = htons (PORT);
  writeHex(name.sin_port);

  name.sin_addr.s_addr = htonl (INADDR_ANY);

  unsigned char* port_memory = (unsigned char*) &name.sin_port;

  write(STDOUT, "\n",1);
  writeHex(port_memory[0]);
  write(STDOUT, " ",1);
  writeHex(port_memory[1]);
  
  if (bind (socket_server, (struct sockaddr *) &name, sizeof (name)) < 0) {
    perror ("bind");
    exit (EXIT_FAILURE);
  }
  
  if (listen (socket_server, 1) < 0) {
    perror ("listen");
    exit (EXIT_FAILURE);
  }

  struct sockaddr_in serv_addr;
  const unsigned int test_value = 0xDEADBEEF;
  int clientfd = socket(AF_INET, SOCK_STREAM, 0);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(0x7F000001);
  serv_addr.sin_port = htons(PORT);

  if (connect(clientfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Write a test value to the socket. The client should print this.
  write(clientfd, (unsigned char*) &test_value, 4);
  close(clientfd);


  int socket;
  struct sockaddr_in clientname;
  socklen_t size;
  unsigned int tempValue;
  int i,j;

  size = sizeof(struct sockaddr_in);
  socket = accept (socket_server, (struct sockaddr *) &clientname, &size);
  if (socket < 0) {
    perror ("accept");
    exit (EXIT_FAILURE);
  }

  // Read from the socket and dump the result  
  read(socket, &tempValue, 4);
  write(STDOUT,  "\n", 1);
  writeHex(tempValue);
  write(STDOUT,  "\n", 1);
  close(socket);
}

int main()
{
  run_server();
  return 0;
}
