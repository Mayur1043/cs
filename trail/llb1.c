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

struct node
{
	int data;
	struct node *next;
};

void insert_at_beg(struct node **,int);
void insert_at_end(struct node **p,int ele);
void del_at_beg(struct node **);
void display(struct node *);
void insert_mid(struct node **,int,int);
//void de<F7>l_mid(struct node **,int);
//void insert_end(struct node **,int);
void del_end(struct node **);
void count(struct node **);
void rev_display(struct node **);
void rev_list(struct node **);

int main()
{	
	struct node *head;
	head=NULL;
	
	int choice,ele,pos;
	while(1){
	printf("\n10.EXIT\n1.insert_at_beg\n2.delete_at_beg\n3.display\n4.insert_at_end\n5.del_end\n6.insert _end\n7.Count Nodes\n8.Reverse Display\n9.reverse_list");
	printf("Enter your choice\n");
	scanf("%d",&choice);

	switch(choice){

		case 1:
			printf("Enter the ele\n");
			scanf("%d",&ele);
			insert_at_beg(&head,ele);
			break;
		case 2:
	 		
			del_at_beg(&head);
			break;
		case 3:
			display(head);
			break;
		
		case 4:
			printf("Enter the ele\n");
			scanf("%d",&ele);
			insert_at_end(&head,ele);
			break;

		case 5:
			del_end(&head);
			break;

		case 6:
			printf("Enter the ele\n");
			scanf("%d",&ele);
			insert_mid(&head,ele,pos);
			break;
		case 7:
			count(&head);
			break;
		case 8:
			//printf("***");
			rev_display(&head);
			break;
			
		case 9:
			rev_list(&head);
			break:

		case 10:
			exit(0);
			break;

		default :
			printf("invalid entry\n");
	}
	}
	return 0;
}
void insert_at_beg(struct node **p,int ele)
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

void del_at_beg(struct node **p)
{
	struct node *t1=*p;
	
	*p=t1->next;

	free(t1);

}

void display(struct node *p)
{
	struct node *t1=p;
	
	while(t1!=NULL){
	
	printf("->%d",t1->data);
	t1=t1->next;
	}
}

void insert_at_end(struct node **p,int ele)
{
	struct node *t1=*p;
	struct node *temp;
	
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=NULL;

	while(t1->next!=NULL){
		t1=t1->next;
	}
		t1->next=temp;
}	

void del_end(struct node **p)
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

void insert_mid(struct node **p,int ele,int pos)
{
	struct node *t1=*p;
//	struct node *t2;
	struct node *temp;

	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=NULL;
	
	int i=1;
	printf("Enter the position of index\n");
	scanf("%d",&pos);
	
	while(i<pos-1){
		t1=t1->next;
		i++;
	}
	
	temp->next=t1->next;
	t1->next=temp;

}
void count(struct node **p)
{
	int count=0;
	struct node *t1=*p;
	while(t1!=NULL)
	{
		count++;
		t1=t1->next;
	}
	printf("%d",count);
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

		
