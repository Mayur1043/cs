#include<stdio.h>
//register int var2=0;
int main()
{	register int var1=0;
       int x=10;
	printf("&x=%u\n",&x);

//	printf("&var1=%p\n",&var1);

	printf("&y=%u\n",&x);
	return 0;
}

