/*Q7. Write a C program to calculate the factorial of given number*/

#include<stdio.h>

int main()
{	
	int fact=1,a,b;
	printf("Enter the number\n");
	scanf("%d",&a);
	for(b=1;b<=a;b++)
	{

	fact=fact*b;
	}
	printf("factorial =%d\n",fact);

	
	return 0;
}

