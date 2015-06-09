#include <stdio.h>

/*
expected on le: 78 12345600
expected on be: 12 00345678
*/

int main()
{
  unsigned int intval = 0x12345678;
  unsigned char *charptr = (unsigned char*) &intval;
  
  printf("%2.2X ", *charptr);
  
  *charptr = 0;

  printf("%8.8X\n", intval);

  return 0;
}
