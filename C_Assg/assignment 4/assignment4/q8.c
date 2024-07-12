/*
Q8. Write a program to count no. of 1s or no. of 0's in a binary code.
*/

#include<stdio.h>

void fun(int);

int count0,count1;
int main(){
	int n;
	printf("enter the number\n");
	scanf("%d",&n);
	fun(n);
	printf("count zero = %d\n",count0);
	printf("count one = %d\n",count1);
	
	return 0;
}

void fun(int n)
{
	if (n==0)
		return ;
	int a=n%10;
	if (a==0)
		count0++;
	else 
		count1++;
	fun(n/10);
}
