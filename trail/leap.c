#include<stdio.h>
int main()
{	
	int n;
	printf("Enter the year:\n");
	scanf("%d",&n);
	if(((n%4==0) && (n%100!=0)) || (n%400==0))
	{
		printf("its is leap year :\n",n);
	}
	else
	{	
	printf("its  is not a leap year :\n",n);
	}


	return 0;
}

