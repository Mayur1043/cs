#include<stdio.h>

int main()
{
	char g;
	int n,a,new;
	float tax;
        printf("Enter Your Income : \n");
	scanf("%d",&n);
	printf("Enter Your Age :\n ");
	scanf("%d",&a);
	if(n<=250000)
	{
		printf("Your have no Tax\n");
	}	

	else if(n>250000 && n<=500000)
	{
		new=n-250000;
		tax=new*0.05;
		printf("Your Tax IS : %f",tax);
	}

	else if(n>500000 && n<=750000)
	{
		tax=0+12500+(n-500000)*0.20;
		printf("Your Tax is : %f",tax);
	}

	else if(n>750000 && n<=1000000)
	{
		tax=0+12500+50000+(n-750000)*0.20;
		printf("Your Tax : %f",tax);
	}

	else if(n>1000000 && n<=1250000)
	{
		tax=0+12500+50000+50000+(n-1000000)*0.30;
		printf("Your Tax : %f",tax);
	}

	else if(n>1250000 && n<=1500000)
	{
		tax=0+12500+50000+50000+75000+(n-1250000)*0.30;
		printf("tax : %f",tax);
	}

	else if(n>1500000)
	{
		tax=12500+50000+50000+75000+75000+(n-1500000)*0.30;
		printf("Tax : %f",tax);
	}
	return 0;
}

