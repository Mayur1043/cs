#include<stdio.h>
#include<stdlib.h>

# define SIZE 5

void enque(int *,int *,int *,int );
int deque(int *,int *,int *);
void display(int *);

int main()
{	
	int f=-1;
	int r=-1;
	int a[SIZE],choice,ele,ret;
	for(int i=0;i<SIZE;i++)
	{
		a[i]=-99;
	}
	while(1)
	{
	printf("\n1->enque\n2->deque\n3->display\n4->exit\n");
	printf("Enter the choice\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			printf("Enter the ele\n");
			scanf("%d",&ele);
			enque(a,&f,&r,ele);
			break;
			
		case 2:
			ret=deque(a,&f,&r);
			if(ret!=-9)
			{
			printf("pop ele =%d",ret);
			}
			
			break;
		case 3:
		 	display(a);
		 	break;
		 
		case 4:
			exit(0);
		}
	}					
	return 0;
}

void enque(int *a,int *f,int *r,int ele)
{
	if(((*f==0)&&(*r==SIZE-1))||((*f==*r+1)))
	{
		printf("queue is full\n");
		return;
	}
	if(*r==SIZE-1 && f!=0)
	{
		*r=0;
	}
	else
	{
		*r=*r+1;
	}
	a[*r]=ele;
	if(*f==-1)
	{
		*f=0;
	}
}


int deque(int *a,int *f,int *r)
{
	if(*f==-1)
	{
		printf("que is empty\n");
		return -9;
	}
	
	int temp=a[*f];
	a[*f]=-99;
	
	if(*f==SIZE-1 && *r!=SIZE-1)
	{
		*f=0;
	}
	else
	{
		if(*f==*r)
		{
			*f=-1,*r=-1;
		}
		else
		{
			*f=*f+1;
		}
	}
	return temp;
	
}


void display(int *a)
{
	for(int i=0;i<SIZE;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("\n");
}		
		
		
