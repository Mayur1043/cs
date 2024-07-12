#include<stdio.h>
#include<stdlib.h>

void mergesort(int [],int,int);
void merge(int [],int,int,int);

void main()
{
	int a[5]={6,8,2,4,3};

	printf("Before Merge : ");
	for(int i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	mergesort(a,0,4);

	printf("After Merge : ");
	for(int i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	//return 0;
}

void mergesort(int a[],int low,int high)
{
	printf("\nCalling for :low : %d\t High : %d\t" ,low,high);
	if(low >= high)
	{
		return;
	}

	int mid;
	mid=(low+high)/2;
	mergesort(a,low,mid);
	//printf("\nCalling for :low : %d\t High : %d\t ",low,high);
	mergesort(a,mid+1,high);
	printf("\nMerging for :low : %d\n High : %d\n Mid : %d\n",low,high,mid);
	merge(a,low,mid,high);

}

void merge(int a[],int low,int mid,int high)
{
	int second=mid+1;
	int *b,k=0;
	b=(int *)malloc(sizeof(int)*5);
	while(low<=mid && second <= high)
	{	
	//	printf("Low : %d\t High = %d\t Mid = %d\t",low,high,mid);	
		if(a[low]<a[second])
		{
			b[k]=a[low];
			printf("Copying : %d",a[low]);
			low++;
			k++;
		}
		else
		{
			b[k]=a[second];
			printf("Copying : %d",a[second]);
			second++;
			k++;
		}
	}

	while(low < mid)
	{	
		b[k]=a[low];
		low++;
		k++;
	}

	while(second < high)
	{
		b[k]=a[second];
		second++;
		k++;
	}
	
	for(int j=0;j<k;j++)
	{
		printf("Here");
		printf("%d\t",b[j]);
	}
	printf("\n");

		k = 0;
	for(int i=0;i<=high;i++)
	{
		a[i]=b[k];
		k++;
	}
	free(b);
}
