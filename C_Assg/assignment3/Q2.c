/*Q2. Swapping of two no.s (with, without temporary, one line code with
xor operator)*/

#include<stdio.h>
  int main()
{
	int x,y;
	printf("Enter the value of x : ");
	scanf("%d",&x);
	printf("Enter the value of y : ");
	scanf("%d",&y);
	x=x^y;
	y=x^y;
	x=x^y;
	printf("x=%d,y=%d",x,y);
	return 0;
}
