#include<stdio.h>

int main()
{
	int i,avg,sum=0,n;
	printf("Enter how many no you want : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
{
	sum = sum + i;
	avg=sum/n;
}
	printf("Sum = %d\n",sum);
	printf("AVG = %d\n",avg);

	return 0;
}
