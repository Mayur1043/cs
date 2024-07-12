#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
       	struct node *next;
};

struct node *head;

void insertatend(int);
void display();

int main()
{
	head=NULL;
	int choice,n,a;
       	while(1)
       	{
	printf("\n1.Insert at end\n2.display\n3.end");
	printf("\nEnter your choice\n");
	scanf("%d",&n);
	
	switch(n)
	{
		case 1:
			printf("Enter the ele : ");
			scanf("%d",&a);
			insertatend(a);
			break;
		case 2:
			display();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("invalid input");
		       break;
		       
	}
       }
	return 0;
}	
				
void  insertatend(int a)
{
		struct node *temp;
		struct node *t1;
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=a;
		temp->next=NULL;
		t1=head;
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			while(t1->next!=NULL){
				t1=t1->next;
			}
			t1->next=temp;

		}
}

void display()
{
	struct node *t1=head;
	while(t1!=NULL)
	{
		printf("-->%d",t1->data);
		t1=t1->next;
	}
}





