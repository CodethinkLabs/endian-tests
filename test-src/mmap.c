#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


int main()
{
  const long pagesize = sysconf(_SC_PAGESIZE);
  const long maplength = pagesize;
  printf("Page size on this system is %ld bytes\n", pagesize);

  int fd = open("mmapped-file", O_RDWR | O_CREAT, 0777);
  if (fd == -1) {
    fprintf(stderr, "Can't open or create mmapped-file\n");
    exit(1);
  }

  if (ftruncate(fd, maplength) == -1) {
    fprintf(stderr, "Failed to set file size to correct length: %s\n", strerror(errno));
    exit(2);
  }

  void* m = mmap(0, maplength, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (m == MAP_FAILED) {
    fprintf(stderr, "Can't mmap the requested file\n");
    close(fd);
    exit(3);
  }

  unsigned int *i = (unsigned int*) m;
  i[0] = 0xDEADBEEF;

  syncfs(fd);
  
  munmap(m, maplength);
  syncfs(fd);

  // Manually read and modify that file
  lseek(fd, 0, SEEK_SET);
  unsigned char readbuffer[4];
  read(fd, readbuffer, 1);
  printf("First byte in file: %2.2X\n", (int) readbuffer[0]); // Expect EF (LE), DE (BE)
  write(fd, "\x47", 1);

  // Now remap that at a different location
  m = mmap(0, maplength, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (m == MAP_FAILED) {
    fprintf(stderr, "Can't mmap the requested file: %s\n", strerror(errno));
    close(fd);
    exit(4);
  }

  i = (unsigned int* __attribute__((litteendian))) m;
  printf("Value at address 0: %8.8X\n", i[0]); // Expect DEAD47EF (LE) DE47BEEF (BE)


  // Continuously read that file
  int total = 0;
  int c;
  for(c = 0;c < 100000000; c++) {
    total += i[c % (maplength/sizeof(unsigned int))];
  }
  printf("Total: %d\n", total);
  munmap(m, maplength);
  close(fd);
}
