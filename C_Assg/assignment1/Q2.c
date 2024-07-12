#include<stdio.h>
int main()
{
	int a,b,c,n;
	printf("Enter 3 Digit No : ");
	scanf("%d",&n);
	a=n/100;
	b=(n%100)/10;
	c=n%10;
	printf("Your No is : %d%d%d\n",c,b,a);
	return 0;

}



