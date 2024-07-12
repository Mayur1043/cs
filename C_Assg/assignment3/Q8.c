#include<stdio.h>
#define size 100
int main()
{	int n,avg;
        int arr[size];
	printf("enter the element of array upto 100 \n");
	scanf("%d",&n);
	printf("enter the elements : \n");
	for(int i=0;i<n;i++)
	{ 	
	
		scanf("%d",&arr[i]);
	}
printf("Array : ");
	int sum=0,a=10,b=20,c=30,d;
	for(int i=0;i<n;i++)
	{
	printf(" %d",arr[i]);
	}

	for(int i=0;i<n;i++)
	{

	 sum=sum+arr[i];
	}
	printf("\n");

	printf("sum = %d\n",sum);

	avg = sum/n;
	printf("avg of given element is = %d\n",avg);
 
		int max=arr[0];
		
	for(int i=1;i<n;i++)
	{
        	if(max<arr[i])
		{
		max=arr[i];
		}
	}


	printf("Your Biggest Number Is =%d\n",max);
	int min=arr[0];

	for(int i=1;i<n;i++)
	{
		if(min>arr[i])
		{
		min=arr[i];
		}

	}

		printf("Your Smallest Number = %d\n",min);


	return 0;
}





