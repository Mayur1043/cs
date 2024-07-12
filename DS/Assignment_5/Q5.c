#include<stdio.h>
#include<stdlib.h> 			// for malloc
#define N 5

void enqueue_r(int [],int *,int *,int );
void enqueue_f(int [],int *,int *,int );
void display(int a[],int *f,int *r);				// declartion Functions
void dequeue_f(int a[],int *f,int *r);
void dequeue_r(int a[],int *f,int *r);
	
int main()
{
	int a[N];
	int f=-1,r=-1;
	int choice,ele;
	while(1)
	{
	printf("\n\tEnter Your Choice \n");
	printf("\n\t0.EXIT\n\t1.Enqueue_Front\n\t2.Enqueue_Rear\n\t3.Dequeue-Front\n\t4.Dequeue_Rear\n\t5.Display\n");
	scanf("%d",&choice);					// user input
	
	switch(choice)
	{
		case 0:
			exit(0);
		case 1:
			printf("Enter Ele : ");
			scanf("%d",&ele);
			printf("\n");
			enqueue_f(a,&f,&r,ele);		// Function call
			break;
		case 2:
			printf("Enter Ele : ");
			scanf("%d",&ele);
			printf("\n");
			enqueue_r(a,&f,&r,ele);		// enqueue function call
			break;
		case 3:
			dequeue_f(a,&f,&r);
			break;
		case 4: 
			dequeue_r(a,&f,&r);
			break;
		case 5:
			display(a,&f,&r);			// display function call
			break;
		default:
			printf("Invalid Input \n");
			break;
	}
	}
	return 0;
}

void enqueue_f(int a[],int *f,int *r,int x)			// function Defination
{
	if((*f==*r+1) || (*f==0 && *r==N-1))			// checking Full condition
	{
		printf("Queue Is Full\n");
	}
	else if(*f==-1 && *r==-1)
	{
		*f=0;
		*r=0;						// reset value of f and r
		a[*f]=x;
	}
	else if(*f==0)
	{
		*f=N-1;
		a[*f]=x;				// stroing value in array
	}
	else
	{
		*f=*f-1;
		a[*f]=x;
	}
}

void enqueue_r(int a[],int *f,int *r,int x)		// function dfiantion
{
	if((*f==*r+1) || (*r==N-1) && (*f==0))		// check full condition
	{	
	printf("Queue is full\n");
	}
	else if(*f==-1 && *r==-1)
	{
		*f=0;
		*r=0;
		a[*r]=x;
	}
	else if(*r==N-1)
	{
		*r=0;
		a[*r]=x;
	}
	else
	{
		*r=*r+1;					// incease r value
		a[*r]=x;
	}
}

void display(int a[],int *f,int *r)					// display function defination
{
	int i=*f;
	while(i!=*r)
	{
	printf("-> %d",a[i]);						// for printing
	i=(i+1)%N;
	}
	if(i==*r)							// one is remain for print
	{
	printf("-> %d",a[i]);
	}
}

void dequeue_f(int a[],int *f,int *r)				// dequeue_r Function Defiantion
{
	if(*f==-1 && *r==-1)
	{
		printf("Queue is Empty \n");
	}
	else if(*f==*r)
	{
		*f=-1;
		*r=-1;						// reset the both value
	}
	else if(*f==N-1)
	{
		printf("%d",a[*f]);
		*f=0;
	}
	else 
	{
	printf("%d",a[*f]);
	*f=*f+1;
	}
}

void dequeue_r(int a[],int *f,int *r)			// function defination
{
	if(*f==-1 && *r==-1)
	{
		printf("Queue id Empty\n");
	}
	else if(*f==*r)
	{
		*f=-1;
		*r=-1;
	}
	else if(*r==0)
	{
		printf("%d",a[*r]);
		*r=N-1;
	}
	else
	{
		printf("%d",a[*r]);
		*r=*r-1;
	}
}


