#include<stdio.h>
#include<stdlib.h>
int* fun();

int (*fun2())[5];
int main ()
{
	int *p;
	int (*p1)[5]; // p1 is an array
	// p1 is a pointer
	p=fun();
	p1=fun2();
	printf("Your Array : \n");
	for(int i=0;i<5;i++)
	{
		printf("%d\t",(*p1)[i]); //* (*p1+i)
	}

	printf("\n");
	for(int i=0;i<5;i++)
	{
		printf("%d\t",*(p+i)); //* (*p1+i)
	}
	printf("\n");

	free(p);
	free(p1);
	return 0;
}

//[A]  BASE ADDRESS

int* fun()
{
	int a[5]={1,2,3,4,5};
	int *q=(int *)malloc(5*sizeof(int));
	for(int i=0;i<5;i++)
	{
		q[i]=a[i];
	}
	return q;
}

//[B]  WHOLE ARRAY
	
int (*fun2())[5]
{
	int *p;
	p = (int *)malloc(20);
	int (*ap)[5];
	ap=(int (*)[5])malloc(5*sizeof(int));
	for(int i=0;i<5;i++)
	
		scanf("%d",(*ap+i));

	return ap;
}
