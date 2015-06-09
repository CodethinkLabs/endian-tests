#include <stdio.h>

/* Passes lots of integers to a library function, to test that
   varargs are passed correctly to a function compiled for LE */

int main()
{
  int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  printf("Values are %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n",
	 a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
  return 0;
}
