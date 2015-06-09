/*

expected on be: 16777216
expected on le: 1

*/

#include <stdio.h>

int main()
{
  unsigned int a = 0, b;
  __asm__ ("nop;"
           "movb $1, (%1);"
	   "movl (%1), %%eax;"
	   "movl %%eax, %0;"
       :"=r"(b)
       :"r"(&a)
       :"%eax"
       );
  printf("b = %d\n",b);
  return 0;
}
