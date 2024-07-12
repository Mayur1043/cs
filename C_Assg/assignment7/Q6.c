#include<stdio.h>
#include<stdlib.h>
int* test(int);
int main()
{
	int x=5;
	int *p=test(x);
	printf("%d\n",*p);
	free(p);
	return 0;
}

int* test(int x)
{
	int *p=(int *)malloc(sizeof(int));
	*p=x*x;
//	int p=&y;
	return p;
}
