#include<stdio.h>

int main()
{
	int n1,n2,i,a=1;
	printf("Enter N1 Number : ");
	scanf("%d",&n1);
	printf("\n");
	printf("Enter N2 Number : ");
	scanf("%d",&n2);
	printf("\n");
	for(i=2; i<=n1 && i<=n2 ;i++)
	{
		if(n1%i==0 && n2%i==0)
		{
			a=i;
		}
		
	}

		printf("Your HCF is =  %d\n",a);
		int	l=(n1*n2)/a;
		printf("Your LCM is = %d\n",l);

	return 0;
}
