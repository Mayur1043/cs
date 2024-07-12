#include<stdio.h>
#include<stdlib.h> 						// library for malloc
#define max 10
int a[max];							// initialize array
int front=-1;
int rear=-1;
void insert_frontend(int item);
void insert_rearend(int item);				// Declaration of Function
int delete_frontend();
int delete_rearend();
void display();
int isfull();
int isempty();


int main()
{
	int choice,element;
	while(1)						// For Infinite Time						
	{
		printf("\n\t1-insertat front end\n\t2-insertat rear end\n\t3-deleteat front end\n\t4-deleteat rear end\n\t5-display\n\t6-exit\t\n");
		printf("enetr the choice\n");
		scanf("%d",&choice);				// Input From User

		switch(choice)									
		{
			case 1:
				printf("\n\tenetr the element\n\t");
				scanf("%d",&element);
				insert_frontend(element);	// Function Call
				break;

			case 2:
				 printf("\n\tenetr the element\n\t");
                                scanf("%d",&element);
                                insert_rearend(element);
                                break;
                                
			case 3:
				printf("\n\tdelete the element:%d\n\t",delete_frontend());
				break;

			case 4:
				printf("\n\tdelete the element:%d\n\t",delete_rearend());
                                break;

			case 5:
				display();			// Display Function Call
				break;
			case 6:
				exit(0);

			default:
				printf("\n\twrong choice\n\t");
		}

		
	}
	return 0;
}

void insert_frontend(int element)				// Declaration of function
{	
	if(isfull())
	{
		printf("\n\tqueue is overflow\n\t");		// Checking Full Condition
		return;
	}
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else if(front==0)
	{
		front=max-1;
	}
	else
	
		front=front-1;
	
	a[front]=element;					// String The Value
}



void insert_rearend(int element)
{
	if(isfull())						// Checking Full Condition
	{
		printf("\n\tqueue is overflow\n\t");
		return;
	}
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else if(rear==max-1)					
	{
		rear=0;
	}
	else
	
		rear=rear+1;
	

	a[rear]=element;
}


int  delete_frontend()						// Defination of Delete Function
{
	int element;
	if(isempty())
	{
		printf("\n\tqueue is underflow\n\t");
		exit(0);
	}
	element=a[front];
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		if(front==max-1)
		
			front=0;
		
		else
		
			front=front+1;
		
	}

	return element;
}


int delete_rearend()
{
	int element;
	if(isempty())
		{
			printf("\n\tqueue is underflow\n\t");
			exit(0);
		}
	element=a[rear];
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(rear==0)
	
	
		rear=max-1;
	
	else
	
		rear=rear-1;
	

	return element;
}

int isfull()
{
	if((front==0 && rear==max-1)||(front==rear+1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int isempty()
{
	if(front==-1)
	
		return 1;
	
	else
	
		return 0;
	
}

void display()
{
	int i;
	if(isempty())
	{
		printf("\n\tqueue is empty\n\t");
		return;
	}

	printf("\n\tqueue element\n\t");
	i=front;

	if(front<=rear)
	{
		while(i<=rear)
			printf("\n\t%d\n\t",a[i++]);
	}
	else
	{
		while(i<=max-1)
		
			printf("\n\t%d\n\t",a[i++]);
			i=0;

                        while(i<=rear)
			
				printf("\n\t%d\n\t",a[i++]);
			
	}
}





