typedef struct _teststruct0_t {
    int field0:8;
    int field1:11;
    int field2:15;
    int field3:1;
} teststruct0_t;
typedef struct _teststruct1_t {
    int field0:20;
    int field1:12;
    int field2:15;
    int field3:12;
} teststruct1_t;
typedef struct _teststruct2_t {
    int field0:7;
    int field1:20;
    int field2:23;
    int field3:32;
} teststruct2_t;
typedef struct _teststruct3_t {
    int field0:30;
    int field1:20;
    int field2:13;
    int field3:5;
} teststruct3_t;
typedef struct _teststruct4_t {
    int field0:26;
    int field1:11;
    int field2:2;
    int field3:21;
} teststruct4_t;
typedef struct _teststruct5_t {
    int field0:32;
    int field1:5;
    int field2:17;
    int field3:22;
} teststruct5_t;
typedef struct _teststruct6_t {
    int field0:14;
    int field1:13;
    int field2:25;
    int field3:32;
} teststruct6_t;
typedef struct _teststruct7_t {
    int field0:5;
    int field1:31;
    int field2:13;
    int field3:1;
} teststruct7_t;
typedef struct _teststruct8_t {
    int field0:13;
    int field1:6;
    int field2:25;
    int field3:6;
} teststruct8_t;
typedef struct _teststruct9_t {
    int field0:14;
    int field1:9;
    int field2:30;
    int field3:26;
} teststruct9_t;
int main()
{
    teststruct0_t teststruct0;
    bzero(&teststruct0, sizeof(teststruct0_t));
    teststruct0.field0 = 0x87F863B6;
    teststruct0.field1 = 0x05FBCD04;
    teststruct0.field2 = 0xB0004ADC;
    teststruct0.field3 = 0x54804661;
    printf("size of structure %d == %d\n",0,sizeof(teststruct0_t));
    unsigned char* byteaccess0 = (unsigned char*) &teststruct0;
    printf("byte samples: %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X \n",byteaccess0[515 % sizeof(teststruct0_t)],byteaccess0[741 % sizeof(teststruct0_t)],byteaccess0[165 % sizeof(teststruct0_t)],byteaccess0[1004 % sizeof(teststruct0_t)],byteaccess0[960 % sizeof(teststruct0_t)],byteaccess0[768 % sizeof(teststruct0_t)],byteaccess0[412 % sizeof(teststruct0_t)],byteaccess0[543 % sizeof(teststruct0_t)],byteaccess0[1008 % sizeof(teststruct0_t)],byteaccess0[482 % sizeof(teststruct0_t)]);
    teststruct1_t teststruct1;
    bzero(&teststruct1, sizeof(teststruct1_t));
    teststruct1.field0 = 0xD1874CE1;
    teststruct1.field1 = 0x81419BCD;
    teststruct1.field2 = 0x671545DB;
    teststruct1.field3 = 0x117DF449;
    printf("size of structure %d == %d\n",1,sizeof(teststruct1_t));
    unsigned char* byteaccess1 = (unsigned char*) &teststruct1;
    printf("byte samples: %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X \n",byteaccess1[186 % sizeof(teststruct1_t)],byteaccess1[924 % sizeof(teststruct1_t)],byteaccess1[446 % sizeof(teststruct1_t)],byteaccess1[638 % sizeof(teststruct1_t)],byteaccess1[97 % sizeof(teststruct1_t)],byteaccess1[419 % sizeof(teststruct1_t)],byteaccess1[160 % sizeof(teststruct1_t)],byteaccess1[808 % sizeof(teststruct1_t)],byteaccess1[156 % sizeof(teststruct1_t)],byteaccess1[483 % sizeof(teststruct1_t)]);
    teststruct2_t teststruct2;
    bzero(&teststruct2, sizeof(teststruct2_t));
    teststruct2.field0 = 0x6576B6A1;
    teststruct2.field1 = 0xC411A587;
    teststruct2.field2 = 0xD3826E69;
    teststruct2.field3 = 0x32502825;
    printf("size of structure %d == %d\n",2,sizeof(teststruct2_t));
    unsigned char* byteaccess2 = (unsigned char*) &teststruct2;
    printf("byte samples: %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X \n",byteaccess2[562 % sizeof(teststruct2_t)],byteaccess2[581 % sizeof(teststruct2_t)],byteaccess2[609 % sizeof(teststruct2_t)],byteaccess2[4 % sizeof(teststruct2_t)],byteaccess2[631 % sizeof(teststruct2_t)],byteaccess2[826 % sizeof(teststruct2_t)],byteaccess2[327 % sizeof(teststruct2_t)],byteaccess2[226 % sizeof(teststruct2_t)],byteaccess2[854 % sizeof(teststruct2_t)],byteaccess2[482 % sizeof(teststruct2_t)]);
    teststruct3_t teststruct3;
    bzero(&teststruct3, sizeof(teststruct3_t));
    teststruct3.field0 = 0x6BA79174;
    teststruct3.field1 = 0xF6F2B8D9;
    teststruct3.field2 = 0x86936D59;
    teststruct3.field3 = 0x1B347A43;
    printf("size of structure %d == %d\n",3,sizeof(teststruct3_t));
    unsigned char* byteaccess3 = (unsigned char*) &teststruct3;
    printf("byte samples: %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X \n",byteaccess3[61 % sizeof(teststruct3_t)],byteaccess3[729 % sizeof(teststruct3_t)],byteaccess3[800 % sizeof(teststruct3_t)],byteaccess3[804 % sizeof(teststruct3_t)],byteaccess3[229 % sizeof(teststruct3_t)],byteaccess3[461 % sizeof(teststruct3_t)],byteaccess3[300 % sizeof(teststruct3_t)],byteaccess3[78 % sizeof(teststruct3_t)],byteaccess3[438 % sizeof(teststruct3_t)],byteaccess3[58 % sizeof(teststruct3_t)]);
    teststruct4_t teststruct4;
    bzero(&teststruct4, sizeof(teststruct4_t));
    teststruct4.field0 = 0x15EC2007;
    teststruct4.field1 = 0xA093AFFE;
    teststruct4.field2 = 0x09EA9991;
    teststruct4.field3 = 0x3D040AF9;
    printf("size of structure %d == %d\n",4,sizeof(teststruct4_t));
    unsigned char* byteaccess4 = (unsigned char*) &teststruct4;
    printf("byte samples: %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X \n",byteaccess4[215 % sizeof(teststruct4_t)],byteaccess4[748 % sizeof(teststruct4_t)],byteaccess4[784 % sizeof(teststruct4_t)],byteaccess4[535 % sizeof(teststruct4_t)],byteaccess4[313 % sizeof(teststruct4_t)],byteaccess4[133 % sizeof(teststruct4_t)],byteaccess4[971 % sizeof(teststruct4_t)],byteaccess4[233 % sizeof(teststruct4_t)],byteaccess4[977 % sizeof(teststruct4_t)],byteaccess4[126 % sizeof(teststruct4_t)]);
    teststruct5_t teststruct5;
    bzero(&teststruct5, sizeof(teststruct5_t));
    teststruct5.field0 = 0xB1F94803;
    teststruct5.field1 = 0xFFB7DBA1;
    teststruct5.field2 = 0xF79A4AFE;
    teststruct5.field3 = 0xFA787439;
    printf("size of structure %d == %d\n",5,sizeof(teststruct5_t));
    unsigned char* byteaccess5 = (unsigned char*) &teststruct5;
    printf("byte samples: %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X \n",byteaccess5[34 % sizeof(teststruct5_t)],byteaccess5[573 % sizeof(teststruct5_t)],byteaccess5[475 % sizeof(teststruct5_t)],byteaccess5[552 % sizeof(teststruct5_t)],byteaccess5[740 % sizeof(teststruct5_t)],byteaccess5[57 % sizeof(teststruct5_t)],byteaccess5[277 % sizeof(teststruct5_t)],byteaccess5[659 % sizeof(teststruct5_t)],byteaccess5[639 % sizeof(teststruct5_t)],byteaccess5[78 % sizeof(teststruct5_t)]);
    teststruct6_t teststruct6;
    bzero(&teststruct6, sizeof(teststruct6_t));
    teststruct6.field0 = 0xEE45C758;
    teststruct6.field1 = 0xC9C6FE84;
    teststruct6.field2 = 0x5BCFFE3E;
    teststruct6.field3 = 0xB3985968;
    printf("size of structure %d == %d\n",6,sizeof(teststruct6_t));
    unsigned char* byteaccess6 = (unsigned char*) &teststruct6;
    printf("byte samples: %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X \n",byteaccess6[306 % sizeof(teststruct6_t)],byteaccess6[775 % sizeof(teststruct6_t)],byteaccess6[665 % sizeof(teststruct6_t)],byteaccess6[892 % sizeof(teststruct6_t)],byteaccess6[908 % sizeof(teststruct6_t)],byteaccess6[387 % sizeof(teststruct6_t)],byteaccess6[462 % sizeof(teststruct6_t)],byteaccess6[725 % sizeof(teststruct6_t)],byteaccess6[495 % sizeof(teststruct6_t)],byteaccess6[479 % sizeof(teststruct6_t)]);
    teststruct7_t teststruct7;
    bzero(&teststruct7, sizeof(teststruct7_t));
    teststruct7.field0 = 0x0A9A9871;
    teststruct7.field1 = 0x7A2F86A4;
    teststruct7.field2 = 0x83C61039;
    teststruct7.field3 = 0x3A5C01C3;
    printf("size of structure %d == %d\n",7,sizeof(teststruct7_t));
    unsigned char* byteaccess7 = (unsigned char*) &teststruct7;
    printf("byte samples: %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X \n",byteaccess7[418 % sizeof(teststruct7_t)],byteaccess7[228 % sizeof(teststruct7_t)],byteaccess7[997 % sizeof(teststruct7_t)],byteaccess7[690 % sizeof(teststruct7_t)],byteaccess7[570 % sizeof(teststruct7_t)],byteaccess7[373 % sizeof(teststruct7_t)],byteaccess7[787 % sizeof(teststruct7_t)],byteaccess7[848 % sizeof(teststruct7_t)],byteaccess7[124 % sizeof(teststruct7_t)],byteaccess7[767 % sizeof(teststruct7_t)]);
    teststruct8_t teststruct8;
    bzero(&teststruct8, sizeof(teststruct8_t));
    teststruct8.field0 = 0x5029D756;
    teststruct8.field1 = 0x88834812;
    teststruct8.field2 = 0xD98BE26B;
    teststruct8.field3 = 0xEFE63400;
    printf("size of structure %d == %d\n",8,sizeof(teststruct8_t));
    unsigned char* byteaccess8 = (unsigned char*) &teststruct8;
    printf("byte samples: %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X \n",byteaccess8[804 % sizeof(teststruct8_t)],byteaccess8[241 % sizeof(teststruct8_t)],byteaccess8[820 % sizeof(teststruct8_t)],byteaccess8[862 % sizeof(teststruct8_t)],byteaccess8[402 % sizeof(teststruct8_t)],byteaccess8[96 % sizeof(teststruct8_t)],byteaccess8[235 % sizeof(teststruct8_t)],byteaccess8[302 % sizeof(teststruct8_t)],byteaccess8[313 % sizeof(teststruct8_t)],byteaccess8[820 % sizeof(teststruct8_t)]);
    teststruct9_t teststruct9;
    bzero(&teststruct9, sizeof(teststruct9_t));
    teststruct9.field0 = 0x059FB3A3;
    teststruct9.field1 = 0xBF776E23;
    teststruct9.field2 = 0x1EE0EF72;
    teststruct9.field3 = 0x4F208EC9;
    printf("size of structure %d == %d\n",9,sizeof(teststruct9_t));
    unsigned char* byteaccess9 = (unsigned char*) &teststruct9;
    printf("byte samples: %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X %2.2X \n",byteaccess9[192 % sizeof(teststruct9_t)],byteaccess9[952 % sizeof(teststruct9_t)],byteaccess9[229 % sizeof(teststruct9_t)],byteaccess9[536 % sizeof(teststruct9_t)],byteaccess9[337 % sizeof(teststruct9_t)],byteaccess9[421 % sizeof(teststruct9_t)],byteaccess9[947 % sizeof(teststruct9_t)],byteaccess9[367 % sizeof(teststruct9_t)],byteaccess9[515 % sizeof(teststruct9_t)],byteaccess9[493 % sizeof(teststruct9_t)]);
    return 0;
}
