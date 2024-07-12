/*Q3. Write a C/C++ program to implement doubly circular linked list
with below metioned functionality.
a) insertAtEnd b) insertAtBeg c) insertAtPos
d) display e) listNodeCount f) deleteFromEnd
g) deleteFromBeg h) deleteFromPos*/

#include<stdio.h>
#include<stdlib.h>				// for malloc
typedef struct node{				// declare structure
struct node *prev;
int data;
struct node *next;
}node;

void insertAtEnd(node **ptr,int data);
void insertAtBeg(node **ptr,int data);
void insertAtPos(node **ptr,int data,int pos);
void display(node *ptr);
void listnodecount(node *ptr);				// Declaration of Functions
void deleteFromEnd(node **ptr);
void deleteFromBeg(node **ptr);
void deleteFrompos(node **ptr,int pos);

int main()
{
int choise,data,pos;
struct node *head=NULL;		     			// head node for addressing	
while (1)
{
printf("enter your choise:\n" );
printf("\n1. insertAtEnd\n2. insertAtBeg\n3. insertAtPos\n4. display\n5. listNodeCount\n6. deleteFromEnd\n7. deleteFromBeg\n8.deleteFrompos\n");
scanf("%d",&choise);						// for user input
switch (choise)
{
	case 1:
		printf("enter the data\n");
		scanf("%d",&data);
		insertAtEnd(&head,data);			// Insert End Function Call
		break;
	case 2:
		printf("enter the data\n");
		scanf("%d",&data);
		insertAtBeg(&head,data);			// Insert Begin Function Call
		break;
	case 3:
		printf("enter the data\n");
		scanf("%d",&data);
		printf("enter the pos\n");
		scanf("%d",&pos);
		insertAtPos(&head,data,pos);			// Insert at position Function Call
		break;
	case 4:
		display(head);					// Dispaly Function Call
		break;
	case 5:
		listnodecount(head);				// Count Node Function Call
		break;
	case 6:
		deleteFromEnd(&head);				// Delete End Function Call
		break;
	case 7:
		deleteFromBeg(&head);				// Delete Begin Function Call
		break;
	case 8:
		printf("enter the pos\n");
		scanf("%d",&pos);
		deleteFrompos(&head,pos);			// Delete at postion Function Call
		break;
	default:
		printf("invalid choise:\n");			// For Wrong Input
		break;
}
}
}
void insertAtEnd(node **ptr,int data)			// Function Defination
{
node *newnode=(node*)malloc(sizeof(node));		// Malloc
newnode->prev=NULL;
newnode->data=data;
newnode->next=NULL;
	if(*ptr==NULL)
	{
		*ptr=newnode;
		newnode->prev=newnode;
		newnode->next=newnode;
	}
	else
	{
		node *p1=*ptr;
		while(p1->next!=*ptr)			
		{
			p1=p1->next;				// for Traversing
		}
			p1->next=newnode;
			newnode->prev=p1;
			newnode->next=*ptr;
			(*ptr)->prev=newnode;
	}
}
void insertAtBeg(node **ptr,int data)				// Insert Function Defination
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->prev=NULL;
	newnode->data=data;
	newnode->next=NULL;
	if(*ptr==NULL)
	{
		*ptr=newnode;
		newnode->prev=newnode;
		newnode->next=newnode;
	}
		node *p1=*ptr;
		while (p1->next!=*ptr)
		{
			p1=p1->next;
		}
		newnode->next=*ptr;
		newnode->prev=p1;
		p1->next=newnode;
		(*ptr)->prev=newnode;
		*ptr=newnode;
}
void insertAtPos(node **ptr,int data,int pos)				// function Defination
{
	node *newnode=(node*)malloc(sizeof(node));				// malloc
	newnode->prev=NULL;
	newnode->data=data;
	if(*ptr==NULL)								// for ptr is NULL
	{
		newnode->next=newnode;
		newnode->prev=newnode;
		*ptr=newnode;
	}
	else									// for ptr is not NULL
	{
			node *p1=*ptr;
			int i=1;
			while(i<pos-1)
			{
			p1=p1->next;
			i++;
		}
		newnode->next=p1->next;
		newnode->prev=p1;
		p1->next=newnode;
		newnode->next->prev=newnode;
	}
}
void display(node *ptr)						// display Function Defination
{
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		node *p1=ptr;
	do
	{
		printf("%d\n",p1->data);
		p1=p1->next;
	}
	while(p1!=ptr);
	}
}
void listnodecount(node *ptr)					// list node Fucntion Defination
{
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		int count=0;
		node *p1=ptr;
	do
	{
		count++;
		p1=p1->next;						// for traversing
	}
	while(p1!=ptr);
	printf("the number of nodes in the list is %d\n",count);
	}

}
void deleteFromEnd(node **ptr)			// delete Function Defination
{
	if (*ptr==NULL)
	{
		printf("list is empty \n");
		return;
	}
		node *p=*ptr;
	while (p->next!=*ptr)
	{
		p=p->next;
	}
	p->prev->next=*ptr;
	free(p);

}
void deleteFromBeg(node **ptr) 		
{		
	if (*ptr==NULL)				// for ptr is NULL
	{	
		printf("list is empty \n");
		return;
	}
	if (*ptr==(*ptr)->next)
	{
		free(*ptr);				// deleting ptr
		*ptr=NULL;
		return;
	}
		node *p=*ptr;
		*ptr=(*ptr)->next;
		(*ptr)->prev=p->prev;
		p->prev->next=*ptr;
		free(p);
}
void deleteFrompos(node **ptr,int pos)			// delete Function Defination
{
	if (*ptr==NULL)
	{
		printf("list is empty \n");
		return;
	}
	if (pos==1)
	{
		deleteFromBeg(ptr);
		return;
	}
	node *p=*ptr;
	int i=1;
	while (i<pos-1)
	{
	p=p->next;
	i++;
	}
	p->next->prev=p->prev;
	p->prev->next=p->next;
	free(p);
}
