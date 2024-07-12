#include<stdio.h>

/*int add(int,int);
int main()
{
	int a=5,b=10,result;
	int (*fp)(int ,int);
	fp=&add;
	result=fp(a,b);
	printf("result is :%d\n",result);


	return 0;
}

int add(int a,int b)
{
	int c = a+b;
	return c;
}*/
typedef  int a[5];

int main()
{
	a arr={10,20,30,40,50};
	for(int i=0;i<5;i++)
	{
	printf("%d",arr[i]);
	}
	printf("\n");
	return 0;

}



