#include <stdio.h>

/*

expected: 1 2 4 8 8 4 8 16

*/

int main()
{
  printf("%ld %ld %ld %ld %ld %ld %ld %ld\n", sizeof(char), sizeof(short int), sizeof(int), sizeof(long int), 
	 sizeof(long long int), sizeof(float), sizeof(double), sizeof(long double));
  return 0;
}
