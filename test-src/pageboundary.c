#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>

int main()
{
  unsigned int pagesize = getpagesize();
  unsigned short int *p, *p1, *p3, *eop2;
  // allocate mem for 3 pages no matter where p falls in a page
  p = (unsigned short int *) malloc(4*pagesize);
  if(!p)
  {
    printf("malloc returned null pointer\n");
    return 0;
  }
  // start of first page, code from mprotect man page
  p1 = (unsigned short int *)(((int) p + pagesize-1) & ~(pagesize-1));
  // start of third page
  p3 = (unsigned short int *)((int) p1 + 2*pagesize);
  if(  mprotect( p1, pagesize, PROT_NONE) < 0
    || mprotect( p3, pagesize, PROT_NONE) < 0 )
  {
    printf("mprotect failed. errno = %d\n", errno);
    return 0;
  }
  // end of second page
  eop2 = p3-1;
  *eop2 = 0x1234;
  printf("%X\n",*eop2);
  return 0;
}
