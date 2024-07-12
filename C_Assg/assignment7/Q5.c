#include<stdio.h>
#include<stdlib.h>
int* fun(int,int);
int main()
{
	int a=10,b=20;
	int *ap=fun(a,b);
	printf("%d\n",*(ap+0));

	printf("%d\n",*(ap+1));
	return 0;
}

int* fun (int a,int b){
	int sum = a+b;
	int prod = a*b;
	int *p =(int *)malloc(2*sizeof(int));
	*(p+0)=sum;
	*(p+1)=prod;
	return p;
}

