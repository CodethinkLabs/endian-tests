#include <assert.h>
#include <stdio.h>
#include <strings.h>

int main()
{
  long double *d;
  unsigned int x[4];
  assert(sizeof(long double) == 4*sizeof(unsigned int));

  d = (long double*) x;
  bzero(x, sizeof(long double));
  *d = 3.14159;

  printf("long double data: %8.8X %8.8X %8.8X %8.8X\n", x[0], x[1], x[2], x[3]);

  return 0;
}
