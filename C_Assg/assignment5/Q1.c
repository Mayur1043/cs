#include<stdio.h>
#define SIZE 100

void fun1(int arr[],int n);//array notation
//void fun2(int *,int);   pointer notation
//void fun3(int (*)[n]); // pointer to  an array

	int n;
int main()
{
	int arr[SIZE];
//	int (*p)[n];
//	p=&arr;
	printf("Enter no. of element : ");
	scanf("%d",&n);

	printf("Enter array element : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}


	for(int i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}

	fun1(arr,n);
	printf("\n");
	for(int i=0;i<n;i++)
	{
	printf("%d",arr[i]);
	}
	return 0;
}


void fun1(int arr[],int n)
{
	for(int i=0;i<n/2;i++)
	{
	int temp;
	temp=arr[i];
	arr[i]=arr[n-1-i];
	arr[n-1-i]=temp;
	}
}
