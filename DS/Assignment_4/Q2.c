#include<stdio.h>
#include<stdlib.h>
 
#define SIZE 10

void push(int *,int *,int);
int pop(int *,int *);
void display(int *);

int main()
{	
	int t=-1;
	int a[SIZE],choice,ret,ele;
	for(int i=0;i<SIZE;i++)
	{
	 	a[i]=-99;
	}
	while(1)
	{
	printf("\n1->push\n2->pop\n3->display\n4.exit\n");
	
	printf("Enter the choice\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			printf("Enter the ele\n");
			scanf("%d",&ele);
			push(a,&t,ele);
			break;
		
		case 2:
		       ret=pop(a,&t);
			if(ret!=-1)
			{
			printf("popped ele=%d\n",ret);
			}
			break;
			
		case 3 :
			display(a);
			break;
			
		case 4:
			exit(0);
	
	 }
	 }
	return 0;
}

void push(int *a,int *r,int ele)
{
	if(*r==SIZE-1)
	{	printf("stack is full\n");
		return;
	}
	
	*r=*r+1;
	a[*r]=ele;
}

int pop(int *a,int *r)
{
	if(*r==-1)
	{	
	printf("Stack is Empty\n");
	return -1;
	}
	
	int temp=a[*r];
	a[*r]=-99;
	*r=*r-1;
	return temp;
}

void display(int *a)
{	
	for(int i=0;i<SIZE;i++)
	{
		printf("stack = %d\n",a[i]);
	}
	printf("\n");
}	

