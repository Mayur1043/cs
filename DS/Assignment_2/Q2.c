/*Q2. Write a C/C++ program to implement Binary Search. We need to check for duplicate element
inputs, if found any should not insert into the input array. The array should manage in sorted order.
Apply a duplicacy check on the element while inserting the element, if found duplicate then discards
the input. The input element should insert in the array at the right position( index). Appropriate
shifting can be applied in the array in order to insert the input element at the right position. An
appropriate condition check needs to apply for element not found scenario.
(a) Binary Search ( iterative approach)
(b) Binary Search ( recursion approach )*/

#include<stdio.h>
int binary(int [],int,int);
int binary_r(int [],int,int,int);

int main()
{	
	int a[5];
	int i,n,ele,num,num2,choice;
	int low=0;	
	printf("Enter number of elements : ");
	scanf("%d",&n);
	int high=n;
	printf("\n");
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	for(int j=0;j<i;j++)
	{
		if(a[i]==a[j])
		{
		printf("already exist");
		n=n+1;
		}
	}
	}
    while(1)
    {
	printf("\n1.Binary Search(Iterative)\n2.Binary Search(Recursion)\n3.EXIT\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter the ele you want : ");
			scanf("%d",&ele);
			num=binary(a,ele,n);
			if(num==-1)
			{
			printf("Not Element Found\n");
			}
			else
			{
			printf("Found = %d\n",num);
			}
			break;
			
		case 2:
			printf("Enter the ele you want : ");
			scanf("%d",&ele);
			num2=binary_r(a,ele,low,high);
			if(num2==-1)
			{
			printf("Not Element Found\n");
			}
			else
			{
			printf("Found = %d\n",num2);
			}
			break;
			
	}
   }
	
	
	
	return 0;
}

int binary(int a[],int ele,int n)
{
	int low=0,high=n;
	
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(ele==a[mid])
		{
		return ele;
		}
		else if(ele>a[mid])
		{
		low =mid+1;
		}
		else if(ele<a[mid])
		{
		high=mid-1;
		}
	}
	return -1;
}


int binary_r(int a[],int ele,int low,int high)
{
	int mid;
	if(low<=high)
	{
		mid=(low+high)/2;
		if(ele==a[mid])
		{
			return ele;
		}	
		else if(ele>a[mid])
		{
			low=mid+1;
		}
		else if(ele<a[mid])
		{
			high=mid-1;
		}
		int x=binary_r(a,ele,low,high);
		return x;
	}
	else
	{
	    return -1;
	}
	
}
