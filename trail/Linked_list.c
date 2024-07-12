#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;

};


int main()
{

	struct node *head;
	head=NULL;
	if(head==NULL)
	{
		printf("Your Linked list is empty\n");
	}

	struct node *temp;
	
	temp=(struct node *)malloc(sizeof(struct node));	

	temp->data=10;
	temp->next=NULL;

	if(head==NULL)
	{
		head=temp;
	}

	if(head==NULL)
	{
	printf("empty\n");
	}
	else
	{
	printf("No Your Linkedlist is not empty\n");
	}
	
	return 0;
}


















































































