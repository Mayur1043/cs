#include<stdio.h>

int main()
{
	int a,b;
	printf("Enter First No : ");
	scanf("%d",&a);
	printf("Enter Second No : ");
	scanf("%d",&b);
	printf("Before Swap : a=%d b=%d\n",a,b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("After Swap : a=%d b=%d\n",a,b);
	return 0;
}
