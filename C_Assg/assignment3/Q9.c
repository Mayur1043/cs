#include<stdio.h>
#define size 100
int main()
{
	int arr[size];
	int n,r,i,count=1;
	printf("Enter Number : ");
	scanf("%d",&n);
	for(i=1;;i++)
	{ 
		r=n%2;
		n=n/2;
		count++;
		//printf("%d ",r);
	if(n<=0)
	{
		break;
	}


	//printf("%d ",count);
	arr[count];
	for(int j=0;j<count;j++)
	{	arr[j]=r;
	}
	
	}
	//printf("1 ");	
	for (int k=count-1;k>0;k--)
	{
		printf("%d",arr[k]);
	}

	return 0;
}
