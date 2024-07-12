#include<stdio.h>
int main()
{
	int a=10,b=20,c=30,d;

	printf("enter the value is =%d\n",d=++a,++b,++c,a+5);//11 over 15


	a=10,b=20,c=30,d=0;
	printf("enter the value is =%d\n",d=(++a,++b,++c,a+5));//16  
	return 0;
}
