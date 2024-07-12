#include<stdio.h>

int main()
{
	int i=10,k,a;
	k=i++;
	printf("%d\n",k); //10
	k=++i;
	printf("%d\n",k); //12

	a=i++*10;
	printf("%d\n",a); //120

	a=++i*10;
	printf("%d\n",a); //140

	float p=10,q;
	q=p--/3;
	printf("%f\n",q); //3.3
	q=--p/3;
	printf("%f\n",q); //2.6
	return 0;
}
