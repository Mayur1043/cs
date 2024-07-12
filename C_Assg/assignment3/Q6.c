#include<stdio.h>

int main()
{

	int x=10;
	float y=10.123456;
	printf("%d\n",x);

	printf("%5d\n",x);

	printf("%05d\n",x);

	printf("%-5d\n",x);

	printf("%8.4f\n",y);


	printf("%0.4f\n",y);
	return 0;
}
