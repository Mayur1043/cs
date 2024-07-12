#include<stdio.h>

int main()
{
	int n,i;
	printf("Enter Your Number : ");
	scanf("%d",&n);
	
	int count=0;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		
			count++;
		
	}
	if(count==0)
	{
		printf("Yes It's a Prime Number\n");
	}
	else
	{
		printf("No,It's Not a Prime Number\n ");
	}
	return 0;
}
