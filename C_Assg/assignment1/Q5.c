#include<stdio.h>

int main()
{
	int n;
	printf("Enter Your Year : ");
	scanf("%d",&n);
	if(((n % 4 == 0) && (n%100!=0)) || (n%400==0))
	{
		printf("Yes It's A Leap Year\n");
	}

	else
	{
		printf("It's not a leap year\n");
	}
	return 0;
}
