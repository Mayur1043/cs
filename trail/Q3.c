#include<stdio.h>
int main()
{	int a,b,c;
	printf("Enter the 1st number");
	scanf("%d",&a);
	printf("Enter the 2nd number");
	scanf("%d",&b);
	printf("Enter the 3rd number");
	scanf("%d",&c);
	if(a>b && a>c)
	{
		printf("a is greatest number is %d\n:",a);
	}
	else if(b>a && b>c)
	{
		printf("b is greatest number is %d\n:",b);
	}
	else if(c>a && c>b) 
	{
	printf("c is the greatest number : %d\n",c);
	}
	return 0;
}

