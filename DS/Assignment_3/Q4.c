/*Q4. Write a C/C++ program to implement single linked list to store
Student Information ( StudentName and StudentPRN).
Implement below metioned functions. Apply all required condition
check & validation like list empty or not, while inserting/deleting by
position validate the position.
a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
e)listNodeCount f) deleteFromEnd g) deleteFromBeg
h)deleteFromPos i) deleteByElement j) reverseDisplay
k)freeAllNode*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

struct node
{
	int prn;
	char name[20];
	struct node *next;
};

void insert(struct node **);
void display(struct node *);
void count(struct node *);
void deleteatend(struct node **p);
void deleteatpos(struct node **p,int pos);
void deleteatbeg(struct node **p);


int main()
{	
	struct node *head;
	head=NULL;
	
	int a,b,choice,pos,ele;
	
	while(1)
	{
	printf("\n1->insert  \n2->display\n3->Node count\n4->delete from pos\n5->delete at end\n6->delete at beg\n7->delete by element\n8->exit\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			insert(&head);
			break;
			
		case 2:
			display(head);
			break;
		case 3:
			count(head);
			break;
			
		case 4:
			printf("Enter tye bposition you want\n");
			scanf("%d",&pos);
			deleteatpos(&head,pos);
			break;
			
		case 5:
			deleteatend(&head);
			break;
			
		case 6:
			deleteatbeg(&head);
			break;
			
		case 8:
			exit(0);
			break;
		
		default:
			printf("invalid input\n");
			break;
			
			}
		}		
	return 0;
}

void insert(struct node **p)
{
	int prn;
	char n[20];
	struct node *t1=*p,*t2;
	struct node *temp;
	

	printf("Enter the student name\n");
	__fpurge(stdin);
	scanf("%[^\n]s",n);
	__fpurge(stdin);
	
	printf("Enter the prn\n");
	__fpurge(stdin);
	scanf("%d",&prn);
	
	temp=(struct node *)malloc(sizeof(struct node));
	temp->prn=prn;
	strcpy(temp->name,n);
	temp->next=NULL;
		
	if(*p==NULL)
	{
		*p=temp;
	}else if((temp->prn)<(t1->prn))
		{
		temp->next=*p;
		*p=temp;
		}
		else {
		while(t1!=NULL){
		
		if(temp->prn < t1->prn){
			break;
			}
			t2=t1;
			t1=t1->next;
			}
			temp->next =t1;
			t2->next=temp;
		}
	}
		
void display(struct node *p)
{
	struct node *t1=p;
	
	if(t1==NULL){
		printf("\nLinked list empty\n");
		return;
	}else{
		while(t1!=NULL){
		printf("\t%d\t%s\n",t1->prn,t1->name);
		t1=t1->next;
		}
	}
}	
		
void count(struct node *p)
{
	struct node *t1=p;
	int i=0;
	if(p==NULL)
	{
	printf("empty linklist\n");
	}
	else{
		while(t1!=NULL)
		{
			i++;
			t1=t1->next;
		}
	printf("->%d\n",i);
	}
		
}	
	
void deleteatend(struct node **p)
{
	struct node *t1=*p;
	struct node *t2;
	
	while(t1->next!=NULL)
	{
		t2=t1;
		t1=t1->next;
	}
	t2->next=NULL;
		free(t1);
	display(*p);
}
		
void deleteatbeg(struct node **p)
{
	struct node *t1=*p;
	struct node *t2=NULL;
	
	if(*p==NULL)
	{
	printf("linklist is empty");
		return ;
	}
	 else
	{
		*p=t1->next;
	}
	free(t1);
}
	
void deleteatpos(struct node **p,int pos)
{
	struct node *t1=*p;
	struct node *t2=NULL;
	
	if(*p==NULL)
	{
	printf("linklist is empty");
	}

	int i=0;
	while(t1->next!=NULL)
	{
		i++;
	}
	*p=t1;
	while(i==pos)
	{
		t2->next=t1->next;
		t2=t1->next;
	}
	t1=t1->next;
}
