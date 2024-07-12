#include<stdio.h>
#define SWAP(type,a,b) {type t;t=a;a=b;b=t;}
int main()
	{	int x =10,y=20;
		SWAP(int, x,y);
		printf("x=%d y=%d",x,y);
	}


/*#define SWAP(type, a, b) {type t ; t=a; a=b ; b=t ;}
Int main()
{
int x=10, y=20;
SWAP(int, x,y);
printf(“x=%d y=%d”, x,y);
}*/
