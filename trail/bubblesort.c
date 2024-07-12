#include<stdio.h>

#define MAX 15

void bubble(int [],int);

int main()
{	
	int a[MAX],i,n;
	printf("Enter your array\n");
	scanf("%d",&n);

	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	bubble(a,n);

	
	printf("After sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	return 0;
}

void bubble(int a[],int n)
{
	int i,j,temp;

for(i=0;i<n-1;i++)
{
	for(j=0;j<n-i-1;j++)
	{
		if(a[j]>a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
}
}

