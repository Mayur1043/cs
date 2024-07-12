/*
Q4. Write a program to find factorial of n.
*/
#include<stdio.h>

int fact(int);

int main(){

	int num;
	printf("enter the number\n");
	scanf("%d",&num);
	num=fact(num);
	printf("factorial is %d",num);
	return 0;
}
int fact(int num){
	if (num==0)
		return 1;
	return (num*fact(num-1));
}





