#include<stdio.h>

int main()
{

	int a=0x11223344;
	char*c;
	c=(char *)&a;
	printf("the value of little endian %x\n",*c);

	printf("the value of little endian %x\n",*(c+0));
	printf("the value of little endian %x\n",*(c+1));
	printf("the value of little endian %x\n",*(c+2));

	printf("the value of little endian %x\n",*(c+3));

	printf("the value of little endian %x\n",a);

	int temp;

	temp=c[0];
	c[0]=c[3];
	c[3]=temp;
	
	int temp2;
	temp2=c[1];
	c[1]=c[2];
	c[2]=temp2;
	printf("Swap value of little endian %x\n",a);

	return 0;
}
