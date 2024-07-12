/*Q1. Write a C/C++ program to implement below mentioned Searching and
Sorting Techniques.
(a) Merge Sort
(b) Quick Sort
(c) Heap Sort*/

#include<stdio.h>
#define SIZE 7

void qsort(int [],int,int);
int split(int [],int ,int);
void swap(int *,int *);

int main()
{
	int i,j,n;
	int low=0;
	int high=SIZE-1;

	int a[7]={10,15,3,2,5,20,12};
	printf("Before Sort :");
	for(i=0;i<7;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	qsort(a,low,high);

	printf("After Sort :");
	for(i=0;i<7;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}

void qsort(int a[],int low,int high)
{
	int pivot;
	if(low>=high)
	{
		return;
	}
		pivot=split(a,low,high);
		qsort(a,low,pivot-1);
		qsort(a,pivot+1,high);

	
}

int split(int a[],int low,int high)
{
	int i,j,pivot;
	i=low+1;
	j=high;
	pivot=low;

	while(i<=j)
	{
		while(a[pivot]<a[j] &&(i <= j))
		{
			j--;
		}
		if(i>j)
		{
			break;
		}
		while(a[pivot]>a[i] && (i<=j))
		{
			i++;
		}
		if(i>j)
		{
			break;
		}
		
		swap(&a[i],&a[j]);
		//swap(&a[i],&a[j]);
		
	}
	swap(&a[pivot],&a[j]);
	return j;
}

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;

}
