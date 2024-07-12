#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};


int main()
{

	struct node *head;
	head=NULL;
	if(head==NULL)
	{
		printf("you have a ll\n");
	}

	struct node *temp;

	temp=(struct node *)malloc(sizeof(struct node));

	temp->data=10;
	temp->next=NULL;

	if(head==NULL){
		head=temp;
		
	if(head==NULL){
		
		printf("no ll found\n");
	}
	else{
		printf("you have a ll\n");
}
}	return 0;
}

		












		


