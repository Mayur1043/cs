#include<stdio.h>
int add(int,int);
int sub(int,int);
int code();

int n,x,y;
int main()
{
	code();
	return 0;
}

int code()
{

	do
	{

	printf("which operation has to perform 1-add,2-sub,3-exit\n");
	scanf("%d",&n);

	
		switch(n)
         	{
			case 1: 
			add(x,y);
			break;

			case 2:
			sub(x,y);
			break;

			case 3:
			//printf("invalid\n");
			return -1;

			default :
			printf("enter valid number\n");
			break;
	    	 }

	  
	}

while(n!=0);
}
int add(int x, int y)
	{

	printf("enter two values \n");
	scanf("%d%d",&x,&y);
	int s;
	s=x+y;
	printf("SUM : %d\n",s);
	return s;
	}


int sub(int x, int y)
{

	printf("enter two values \n");
	scanf("%d%d",&x,&y);
	int t=x-y;
	printf("SUB : %d\n",t);
	return t;
	
}


