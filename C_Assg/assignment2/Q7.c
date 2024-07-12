#include<stdio.h>

int main()
{
	int n,n1,x,n2,n3;
	printf("Enter Number : ");
	scanf("%d",&n);
	if(n>0)
	{
		n1=n/100;
		x=n%100;
		n2=x/10;
		n3=n%10;

		int sum=(n1*n1*n1)+(n2*n2*n2)+(n3*n3*n3);

		if(sum==n)
		{
			printf("Yes");
		}
		else
		{
			printf("No");
		}

	}

	else
	{
		printf("Enter Valid No");
	}
	return 0;
}
