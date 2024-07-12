#include<stdio.h>
#define SIZE 100

void add(int a[],int b[]);

int main()
{
	int a[SIZE],b[SIZE];
	int i;
	printf("Enter Your Element :");
	for(int i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Your array : ");
	for(int i=0;i<5;i++)
	{	
	printf("%d",a[i]);
	}
	
	printf("\n");

	printf("Enter Your Element :");
	for(int i=0;i<5;i++)
	{
		scanf("%d",&b[i]);
	}
	printf("Your array : ");
	for(int i=0;i<5;i++)
	{	
	printf("%d",b[i]);
	}

	printf("\n");
	add(a,b);
	
	return 0;
}


void add(int a[],int b[])
{
	int c[SIZE];
	printf("Output : ");
	for(int i=0;i<5;i++)
	{
		c[i]=a[i]+b[i];
		printf(" %d",c[i]);
	}
}
