#include<stdio.h>

int main()
{

        short int a=0x1122;
        char*c;
        c=(char *)&a;

        printf("the value of little endian %x\n",*(c+0));
        printf("the value of little endian %x\n",*(c+1));
        printf("the value of little endian %x\n",a);

        int temp;

        temp=c[0];
        c[0]=c[1];
        c[1]=temp;

        printf("Swap value of little endian %x\n",a);

        return 0;
}

