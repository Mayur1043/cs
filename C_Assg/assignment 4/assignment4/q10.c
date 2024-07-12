/*
Q10. Write a program to count digits of a number.
*/

#include<stdio.h>

void fun(int);
int count=0;
int main(){
	int n;
	printf("enter the number\n");
	scanf("%d",&n);
	fun(n);
	printf("number of digits in number =%d\n",count);
	return 0;
}
void fun(int n)
{
	if(n<10)
	{
		count++;
		return;
	}
	count++;
	fun(n/10);
}

