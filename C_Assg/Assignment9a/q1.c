/*Write a C program to create a structure named “addition”, with 3 data members, num1,
num2 and sum of type int.
Taking user input, initialize the num1 and num2 and then store the result of num1+ num2 in
the sum data member;*/
#include<stdio.h>
struct addition
{
	int a;
	int b;
	int c;
};
int main()

{	 
	struct addition add;
	printf("enter two number\n");
	scanf("%d%d",&add.a,&add.b);
	add.c= add.a+add.b;
	printf("addition of two number is %d\n",add.c);

}
