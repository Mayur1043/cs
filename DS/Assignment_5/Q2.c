/*Q2. Write a C/C++ program to implement doubly linked list with below
metioned functions functionality.
a) insertAtEnd b) insertAtBeg c) insertAtPos
d) display e) listNodeCount f) deleteFromEnd
g) deleteFromBeg h) deleteFromPos*/
#include<stdio.h>
#include<stdlib.h>						// for malloc


struct node {							// declare Structure
    struct node *pre;
	int data;
	struct node *next;
};
void insert_e(struct node **,int);
void insert_b(struct node **,int);
void display(struct node *);
void reverse_d(struct node **);
void reverse(struct node **);					// Function Declaration
void ipos(struct node **,int,int);
void dpos(struct node **,int );
void count_node(struct node *);

int main()
{
	struct node *head=NULL;			// use head node for address
	int ele;
	
	int choice,pos,count;
	int a[count];
	while(1)
	{
	printf("\n0.EXIT\n1.Insert End\n2.Inset Begin\n3.Display\n4.Reverse Display\n5.Insert at Position\n6.Reverse\n7.Delete At Position\n8.Count Nodes\n");
	scanf("%d",&choice);					// user input

	switch(choice)
	{	
		case 0:
			exit(0);
		case 1:
			printf("Enter Ele : ");
			scanf("%d",&ele);
			printf("\n");
			insert_e(&head,ele);			// Insert End Function Call
			break;
		case 2:
		    printf("Enter Ele : ");
			scanf("%d",&ele);
			printf("\n");
			insert_b(&head,ele);			// Insert Begin function Call
			break;
		case 3:
			display(head);				// Display function Call
			break;
		case 4:
			reverse_d(&head);			// Reverse Function Call
			break;
		case 5:
			printf("Enter Ele : ");
			scanf("%d",&ele);
			printf("Enter Position : ");
			scanf("%d",&pos);
			ipos(&head,ele,pos);			// Insert At Position Function Call
			break;
		case 6:
			reverse(&head);			// Reverse Function Call
			break;
		case 7:
			printf("Enter Position : ");
			scanf("%d",&pos);
			dpos(&head,pos);			// Delete At Position function Call
			break;
		case 8:
		    count_node(head);				// Count Node Function Call
		    break;
		
		default: 
				printf("Invalid Option\n");	// For Wrong Input
				break;
			
	}
	}
	return 0;
}

void insert_e(struct node **p,int ele)		// function Defination
{
	struct node *new;
	struct node *t1=*p;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=ele;					// storing data in node
	new->next=NULL;			
	new->pre=NULL;
	
	if(*p == NULL)  				// checking if head is NULL then update by new node address
        {  
            *p = new;  
            new -> next = NULL;    
        }
    else						// for head is not NULL
    {
    	while(t1->next!=NULL)
    	{
    	    t1=t1->next;				// traversing in linked list
    	}
    	new->pre=t1;
    	t1->next=new;
    }
}

void insert_b(struct node **p,int ele)		// Function Defination
{
    struct node *new;
    struct node *t1=*p;
    new=(struct node *)malloc(sizeof(struct node));		// Malloc
    new->next=NULL;
    new->pre=NULL;
    new->data=ele;					// storing Data
    
    new->next=*p;
    *p=new;
}
void reverse_d(struct node **p)			// Fucntion Defination
{
	if(*p==NULL)
	{
		return;
	}
	reverse_d(&((*p)->next));
	printf("->%d",(*p)->data);
	
}

void display(struct node *p)				// display function Defination
{
	struct node *t1=p;
	while(t1!=NULL)
	{
		printf("->%d",t1->data);		// Display Data
		t1=t1->next;
	}
}

void count_node(struct node *p)		// count node Funciton Defination
{
    int count=0;
    struct node *t1=p;
    while(t1!=NULL)				// traversing Till End
    {
        count++;
        t1=t1->next;
    }
    printf("Total Node : %d",count);		// Print the Count
}

void ipos(struct node **p,int ele,int pos)	// Funcion Defination
{
	int count=1;
	struct node *t1=*p;
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node)); // Malloc
	new->data=ele;
	new->next=NULL;
	new->pre=NULL;
	while(t1->next!=NULL)			// for travesing till last to second node
	{
		count++;
		if(pos==count)			// for exact position
		{
		    new->pre=t1;
			new->next=t1->next;
			t1->next->pre=new;
			t1->next=new;
			
		}
		t1=t1->next;
	}
}

void reverse(struct node **p)				// Function Defination
{
	struct node *pre=NULL;
	struct node *curr=*p;
	struct node *next;
	
	while(curr!=NULL)
	{
		next=curr->next;			// For Reverse Linked list
		curr->next=pre;
		pre=curr;
		curr=next;
	}
	(*p)=pre;
}

void dpos(struct node **p,int pos)			// Function Defination
{
      	int count=1;
	struct node *t1=*p;
	struct node *t2;
	while((t1)!=NULL)
	{
		t2=t1;
		t1=t1->next;
		
		if(count==(pos-1))			// for finding entered position
		{
			t2->next=t1->next;
			t1->next=NULL;
		}
		count++;
		
	}
	free(t1);
	
}
