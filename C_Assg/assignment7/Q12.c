/*Q 12. Passing function names as parameters
void test(int x, int y, int (*fp) (int,int))
{
int z = fp(x,y);
----
}
test(10,20,sum);?*/
#include<stdio.h>
void test(int a,int b,int(*op)(int,int));
int (*op)(int,int);
int sum(int a,int b);
int sub(int a,int b);
int mul(int a,int b);
int div(int a,int b);

int main()
{
	int x=30;
	int y=30;
	int (*type1[4])(int ,int)={sum,sub,mul,div};
	test(x,y,type1[0]);
	test(x,y,type1[1]);
	test(x,y,type1[2]);
	test(x,y,type1[3]);
	return 0;
}
void test(int a,int b,int(*op)(int,int))
{
	int c=(*op)(a,b);
	printf("%d\n",c);
}
int sum(int a,int b)
{
 	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int div(int a,int b)
{
	return a/b;
}
