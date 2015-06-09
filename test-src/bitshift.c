#include <stdio.h>

void printBinary( void *hex, int numBytes);

int main()
{
  unsigned long long int x = 0xFF000000000000FF;
  unsigned int y = 0xFF0000FF;
  unsigned short int z = 0xFF00;
  unsigned char w = 'A';
  int xBytes = sizeof(x);
  int yBytes = sizeof(y);
  int zBytes = sizeof(z);
  int wBytes = sizeof(w);

  printBinary(&x,xBytes);

  // shift long int left
  x = x << 1; printBinary(&x,xBytes);
  x = x << 7; printBinary(&x,xBytes); // shift 8 from initial x
  x = x << 55; printBinary(&x,xBytes); // shift 63 from initial x

  // shift long int right
  x = 0xFF000000000000FF;
  x = x >> 1; printBinary(&x,xBytes);
  x = x >> 7; printBinary(&x,xBytes); // shift 8 from initial x
  x = x >> 55; printBinary(&x,xBytes); // shift 63 from initial x

  printBinary(&y,yBytes);

  // shift int left
  y = y << 1; printBinary(&y,yBytes);
  y = y << 7; printBinary(&y,yBytes); // shift 8 from initial y
  y = y << 23; printBinary(&y,yBytes); // shift 31 from initial y

  // shift int right
  y = 0xFF0000FF;
  y = y >> 1; printBinary(&y,yBytes);
  y = y >> 7; printBinary(&y,yBytes); // shift 8 from initial y
  y = y >> 23; printBinary(&y,yBytes); // shift 31 from initial y

  printBinary(&z,zBytes);

  // shift short int left
  z = z << 1; printBinary(&z,zBytes);
  z = z << 7; printBinary(&z,zBytes); // shift 8 from initial z

  // shift short int right
  z = 0xFF00;
  z = z >> 1; printBinary(&z,zBytes);
  z = z >> 7; printBinary(&z,zBytes); // shift 8 from initial z
  z = z >> 8; printBinary(&z,zBytes); // shift 15 from initial z

  printBinary(&w,1);

  // shift short int left
  w = w << 1; printBinary(&w,wBytes);
  w = w << 7; printBinary(&w,wBytes); // shift 8 from initial w

  // shift short int right
  w = 'A';
  w = w >> 1; printBinary(&w,wBytes);
  w = w >> 7; printBinary(&w,wBytes); // shift 8 from initial w

  return 0;
}

void printBinary( void *hex, int numBytes)
{
  char hexaDecimal[16];
  int i;

  if(numBytes == 8)
  {
    unsigned long long int *hex2 = hex;
    sprintf(hexaDecimal,"%16.16LX",*hex2);
  }
  else if(numBytes == 4)
  {
    unsigned int *hex2 = hex;
    sprintf(hexaDecimal,"%8.8X",*hex2);
  }
  else if(numBytes == 2)
  {
    unsigned short int *hex2 = hex;
    sprintf(hexaDecimal,"%4.4X",*hex2);
  }
  else if(numBytes == 1)
  {
    unsigned char *hex2 = hex;
    sprintf(hexaDecimal,"%2.2X",*hex2);
  }
  else
  {
      return;
  }

  for(i=0;i<2*numBytes;i++)
  {
    switch(hexaDecimal[i])
    {
      case '0': printf("0000"); break;
      case '1': printf("0001"); break;
      case '2': printf("0010"); break;
      case '3': printf("0011"); break;
      case '4': printf("0100"); break;
      case '5': printf("0101"); break;
      case '6': printf("0110"); break;
      case '7': printf("0111"); break;
      case '8': printf("1000"); break;
      case '9': printf("1001"); break;
      case 'A': printf("1010"); break;
      case 'B': printf("1011"); break;
      case 'C': printf("1100"); break;
      case 'D': printf("1101"); break;
      case 'E': printf("1110"); break;
      case 'F': printf("1111"); break;
    }
  }
  printf("\n");
}
