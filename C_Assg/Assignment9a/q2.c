/*Q2: Using structure, write a C program to find the area of a given rectangle. Store the
dimensions of rectangle and calculated area in the structure itself. (User Input);*/
#include<stdio.h>

typedef struct area{

	int l,b,ans;
	
} rec ;

int main()
{
	rec s;
	printf("enter legth and width resp. \n");
	scanf("%d%d",&s.l,&s.b);

	s.ans = s.l*s.b;
	printf("answer is %d\n",s.ans);
}
