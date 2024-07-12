/*
Q9. Differentiate between
const int * p;
int const * p
int * const p = &x;
const int * const p = &x;
Try p=20, p++, (*p)++, p=&y in each case*/

#include<stdio.h>

int main()
{
	int x=10;
	const int y=20;

	//int *const p=&x;
	//printf("p++=%u \n",p++);	//not possible 
	//printf("(*p)++=%u \n",(*p)++);
	//*p=20;
	
	int const *p=&x;
	printf("p++=%u \n",p++);           //
	//printf("(*p)++=%u \n",(*p)++);     //error
	printf("*p=%u \n",*p);           //10
	//*p=20;                   	//error
	return 0;
}
