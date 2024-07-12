#include<stdio.h>
void bubble(int [],int);
int main()
{
	
	int a[5]={10,30,50,20,40};
	int i;
	printf("Before Bubble Sort\n");
	for(i=0;i<5;i++)
	{
		printf(" %d",a[i]);
	}
	printf("\n");

	bubble(a,5);

	printf("After Bubble Sort\n");
	for(i=0;i<5;i++)
	{
		printf(" %d",a[i]);
	}
	printf("\n");

	
	return 0;
}

void bubble(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
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
