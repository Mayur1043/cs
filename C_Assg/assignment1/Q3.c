#include<stdio.h>

int main()
{
	int a,b,c;
	printf("Enter First No : ");
	scanf("%d",&a);
	printf("Enter Second No : ");
	scanf("%d",&b);
	printf("Enter Third No : ");
	scanf("%d",&c);
	
	if(a>b && a>c)
	{
		printf("First No. is Greatest\n");
		
	}
	if(b>a && b>c)
	{
		printf("Second No. is Greatest\n");
	}
	if(c>a && c>b)
	{
		printf("Third No. is Greatest\n");
	}

	return 0;
}
