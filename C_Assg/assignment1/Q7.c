#include<stdio.h>

int main()
{
	int i,n,fact=1;
	printf("Enter Your Number : ");
	scanf("%d",&n);
	if(n<0)
	{
		printf("Enter Valid Number\n");
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			fact=fact*i;
		}
		printf("Factorial of %d is %d\n",n,fact);
	}
	return 0;
}
