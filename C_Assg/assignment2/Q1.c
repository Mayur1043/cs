#include<stdio.h>

float add(float a,float b);

float sub(float a,float b);

float mul(float a,float b);

float div(float a,float b);

int main()
{
	float ans,a,b;
	int n;
	printf("Choose Your Option : \n");
	printf("1. ADD\n");
	printf("2. SUB\n");
	printf("3. MUl\n");
	printf("4. DIV\n");
	printf("Enter the value a :");
	scanf("%f",&a);
	printf("Enter the value b : ");
	scanf("%f",&b);
	printf("Enter your choice : ");
	scanf("%d",&n);
	printf("\n");
	switch(n)
	{
		case 1:
			ans=add(a,b);
			printf("Sum = %.2f",ans);
			break;

		case 2:
			ans = sub(a,b);
			printf("Sub = %f",ans);
			break;

		case 3:
			 ans = mul(a,b);
			printf("mul = %f",ans);
			break;

		case 4:
			ans =div(a,b);
			printf("Div = %f",ans);
			break;

	default:
			printf("Enter invalid Option\n");

	}
	return 0;	
}

float add(float a,float b)
{
	return a + b;
}
float sub(float a,float b)
{
return  a-b;
}
float mul(float a,float b)
{
return  a * b;
}
float div(float a,float b)
{
	return a/b;
}

