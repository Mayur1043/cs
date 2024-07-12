/*Q2. Write a C/C++ program to implement single linked list.
Implement below metioned functions. Apply all required condition
check & validation like list empty or not, while inserting/deleting by
position validate the position.
a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
e)listNodeCount f) deleteFromEnd g) deleteFromBeg
h)deleteFromPos i) deleteByElement j) reverseDisplay
k)freeAllNode l) reverseList m)sortedList9+*/

#include<stdio.h>
#include<stdlib.h>

struct node                       //declare a structure node
{
	int data;
	struct node *next;
};
							//declaration of all functions 
void insert_at_beg(struct node **,int);
void insert_at_end(struct node **,int ele);
void del_at_beg(struct node **);
void display(struct node *);
void insert_mid(struct node **,int,int);
void del_mid(struct node **,int);
void del_ele(struct node **,int);
void del_end(struct node **);
int count(struct node **);
void rev_display(struct node **);
void rev_list(struct node **);
void freeallnodes(struct node **);
void sort(struct node **,int);

int main()
{	
	struct node *head;			//take head as a ptr 
	head=NULL;
	
	int choice,ele,pos;
	while(1){				
	printf("\n1.insert_at_beg\n2.delete_at_beg\n3.display\n4.insert_at_end\n5.del_end\n6.insert _mid\n7.Count Nodes\n8.Reverse Display\n9.reverse_list\n10.del_mid\n11.del_ele\n12.freeallnodes\n13.sort\n14.EXIT\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);

	switch(choice){    				// loop for menu driven

		case 1:
			printf("Enter the ele\n");
			scanf("%d",&ele);
			insert_at_beg(&head,ele);   // call insert at beginning
			break;
		case 2:
	 		
			del_at_beg(&head);		// call delete at beginning
			break;
		case 3:
			display(head);             // call display
			break;
		
		case 4:
			printf("Enter the ele\n");
			scanf("%d",&ele);
			insert_at_end(&head,ele);        // call at insert at end 
			break;

		case 5:
			del_end(&head);		// call delete at end 
			break;

		case 6:
			printf("Enter the ele\n");
			scanf("%d",&ele);
			printf("Enter the position of index\n");				
			scanf("%d",&pos);
			insert_mid(&head,ele,pos);     // call insert at position
			break;
		case 7:
			count(&head);     		// call count of all nodes
			break;
		case 8:            
			rev_display(&head);		// call reverse display
			break;
			
		case 9:
			rev_list(&head);        	// call reverselist display 
			break;
		case 10:
			printf("Enter the pos you want to delete\n");
			scanf("%d",&pos);
			del_mid(&head,pos);     	// call delete at position
			break;
			
		case 11:
			printf("Enter the ele\n");
			scanf("%d",&ele);		
			del_ele(&head,ele);		// call delete by element
			break;
			
		case 12:
			freeallnodes(&head);         // call free all nodes
			break;
		case 13:
			printf("Enter the ele\n");
			scanf("%d",&ele);
			sort(&head,ele);
			break;
			

		case 14:
			exit(0);			// call exit for out of the switch
			break;

		default :
			printf("invalid entry\n");	// termination of program
	}
	}
	return 0;
}
void insert_at_beg(struct node **p,int ele)		// defination for insert at beginning
{
	struct node *t1=*p;				
	struct node *temp;					
	t1=*p;
	temp =(struct node *)malloc(sizeof(struct node ));	
	temp->data=ele;
	temp->next=NULL;

	if(*p==NULL){						
		*p=temp;
	}
	else
	{	temp->next=*p;
		*p=temp;
	}
}

void del_at_beg(struct node **p)		//defination of delete at beginning
{
	struct node *t1=*p;
	
	*p=t1->next;

	free(t1);

}

void display(struct node *p)			// defination of display
{
	struct node *t1=p;
	if(p == NULL)
	{
		printf("Empty Linked list\n");
		return;
	}
	while(t1!=NULL){			
	
	printf("->%d",t1->data);
	t1=t1->next;
	}
}

void insert_at_end(struct node **p,int ele)     // defination of insert at end
{
	struct node *temp;
	struct node *t1=*p;
	
	temp=(struct node *)malloc(sizeof(struct node));      
	temp->data=ele;
	temp->next=NULL;
	if((*p)==NULL)
	{
		*p=temp;
	}
	else
	{
		while(t1->next!=NULL)
		{
			t1=t1->next;
		}
			t1->next=temp;
	}
}	

void del_end(struct node **p)			// defination of delete at end 
{
	struct node *t1=*p;
	struct node *t2;
	//t1=t1->next;	
	while(t1->next!=NULL)
	{
		t2=t1;
		t1=t1->next;
	}
	t2->next=NULL;
	free(t1);		
}

void insert_mid(struct node **p,int ele,int pos)			// defination of insertion at position function
{
	int count=1;
	struct node *t1=*p;
//	struct node *t2;
	struct node *temp;

	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=NULL;
	
	while(t1->next!=NULL)
	{
		count++;
		if(pos==count)
		{
			temp->next=t1->next;
			t1->next=temp;		
		}
		t1=t1->next;
	}

}

void del_mid(struct node **p,int pos)
{
	struct node *t1=*p;
	struct node *t2 = NULL;
	int i=1;
	while(i<pos)
	{	t2=t1;
		t1=t1->next;
		i++;
	}
	t2->next=t1->next;
	free(t1);
}
		
void del_ele(struct node **p,int ele)
{
	struct node *t1=*p;
	struct node *t2=NULL;
	
	int n=1;
	
	while(t1->data!=ele)
	{	t1=t1->next;
		n++;
	}
	
	del_mid(p,n);               				// call delete at mid position
	display(*p);						//call display function
}
				
int count(struct node **p)    			//defination of count function
{
	int count=0;
	struct node *t1=*p;
	while(t1!=NULL)
	{
		count++;
		t1=t1->next;
	}
	printf("%d",count);
	return count;
}


void rev_list(struct node **p)
{
	//int count=1;
	struct node *pre=NULL;
	struct node *t1=*p;
	struct node *t2=NULL;
	//count=0;
	while(t1!=NULL)
	{
		t2=t1->next;
		t1->next=pre;
		pre=t1;
		t1=t2;
	}
	*p=pre;
}

void rev_display(struct node **p)
{

	struct node *t1=*p;
	int count=0;
	
	while(t1->next!=NULL)
	{
		t1=t1->next;
		count++;
		
	}
	
	while(count>=0){
	t1=*p;
      	int i=0;
      	
      	while(i<count)
    	  {
     	 	t1=t1->next;
     	 	i++;
     	 	
     	 }
		printf("->%d",t1->data);
	count--;
	}
		
}	

void freeallnodes(struct node **p)
{
	struct node *t1=*p;
	struct node *t2=NULL;
	//int a=count(p);
	
		t1=*p;
		while(t1!=NULL)
		{	
			t2=t1;
			t1=t1->next;
			free(t2);
		}
		//free(t1);
	
	*p = NULL;
	display(*p);
}	

void sort(struct node **p,int ele)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=ele;
	new->next=NULL;
	
	int num=new->data;
	if((*p)==NULL || num<(*p)->data)
	{
		new->next=(*p);
		(*p)=new;
	}
	else
	{
		struct node *temp=*p;
		while(temp->next!=NULL && temp->next->data<num)
		{
		temp=temp->next;
		}
		new->next=temp->next;
		temp->next=new;
	}
}
