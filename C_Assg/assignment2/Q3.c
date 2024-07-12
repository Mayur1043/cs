#include<stdio.h>
int main()
{
	int a,b,c,d,e,sum;
	float per;
	printf("Enter the value a,b :");
 	scanf("%d%d",&a,&b);
	printf("Enter the value c,d :");
 	scanf("%d%d",&c,&d);
	printf("Enter the value e :");
 	scanf("%d",&e);
	sum =(a+b+c+d+e);
		printf("sum%d",sum);
		per = sum/5;

		printf("per%f",per);
		return 0;
}
