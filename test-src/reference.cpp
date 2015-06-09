#include <stdio.h>



int main()
{
  unsigned int __attribute__((bigendian)) raw_int_1;
  unsigned int __attribute__((littleendian)) raw_int_2;

  unsigned int raw_int_3;
  unsigned int raw_int_4;

  unsigned int &int_ref_1 = raw_int_1;
  unsigned int &int_ref_2 = raw_int_2;
  unsigned int __attribute__((bigendian)) &int_ref_3 = raw_int_3;
  unsigned int __attribute__((littleendian)) &int_ref_4 = raw_int_4;
  
  int_ref_1 = 0xDEADBEEF;
  int_ref_2 = 0xDEADBEEF;
  int_ref_3 = 0xDEADBEEF;
  int_ref_4 = 0xDEADBEEF;

  unsigned char* charAccess1 = (unsigned char*) &raw_int_1;
  unsigned char* charAccess2 = (unsigned char*) &raw_int_2;
  unsigned char* charAccess3 = (unsigned char*) &raw_int_3;
  unsigned char* charAccess4 = (unsigned char*) &raw_int_4;
  
  printf("1: %2.2X 1: %2.2X\n", charAccess1[0], charAccess2[0]);
  printf("3: %2.2X 4: %2.2X\n", charAccess3[0], charAccess4[0]);
}
