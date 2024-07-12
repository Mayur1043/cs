/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>  
#include<stdlib.h>  					// use for malloc
struct node   						// Declare Structure
{  
    int data;  
    struct node *next;   
};  
struct node *head;  					// Declare Global Variable
  
void beginsert ();   
void lastinsert ();  
void randominsert();  
void begin_delete();  					// Function Declarations
void last_delete();  
void random_delete();
void insert_m();
void display();  

void main ()  
{  
    int choice =0;  
    while(1)   
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Display\n7.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);				// for user input  
        switch(choice)  
        {  
            case 1:  
                    beginsert();      
                    break;  
            case 2:  
                    lastinsert();         
                    break;  
            case 3:  
                    begin_delete();       			// Funtion Call
                    break;  
            case 4:  
                    last_delete();        
                    break;  
            case 5:  
                    display();     
                    break;  
            case 6: 
                    insert_m();
                    break;
            case 7:  
                    exit(0);  				// for EXIT
           
            default:  
                    printf("Please enter valid choice.."); 	// For Wrong User Input
                    break;
        }  
    }  
}  
void beginsert()  				// Function Defination
{  
    struct node *ptr,*temp;   
    int item;   
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  				// for not allowing memory
    {  
        printf("\nOVERFLOW");  
    }  
    else   
    {  
        printf("\nEnter the node data : ");  
        scanf("%d",&item);  			
        ptr -> data = item;  		// store data
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;  
        }  
        else   			// if head is not NULL
        {     
            temp = head;  
            while(temp->next != head)  
                temp = temp->next;  
            ptr->next = head;   
            temp -> next = ptr;   
            head = ptr;  
        }   
        printf("\nnode inserted\n");  
    }  
              
}  
void lastinsert()  			// Function Defination
{  
    struct node *ptr,*temp;   
    int item;  
    ptr = (struct node *)malloc(sizeof(struct node));   // Malloc Allocation
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
    }  
    else  
    {  
        printf("\nEnter Data : ");  		
        scanf("%d",&item);  
        ptr->data = item;  
        if(head == NULL)  
        {  
            head = ptr;  			// update head with ptr
            ptr -> next = head;    		
        }  
        else  
        {  
            temp = head;  
            while(temp -> next != head)  
            {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr -> next = head;  
        }  
          
        printf("\nnode inserted\n");  
    }  
  
}  
  
void begin_delete()  					// Function Defination
{  
    struct node *ptr;   
    if(head == NULL)  
    {  
        printf("\nUNDERFLOW");    
    }  
    else if(head->next == head)  
    {  
        head = NULL;  
        free(head);  
        printf("\nnode deleted\n");  
    }  
      
    else  						// if head is not NULL
    {   ptr = head;   
        while(ptr -> next != head)  
            ptr = ptr -> next;   
        ptr->next = head->next;  
        free(head);  
        head = ptr->next;  
        printf("\nnode deleted\n");  
  
    }  
}  
void last_delete()  					// Function Defination
{  
    struct node *ptr, *preptr;  
    if(head==NULL)  					// for head = NULL
    {  
        printf("\nUNDERFLOW");  
    }  
    else if (head ->next == head)  
    {  
        head = NULL;  
        free(head);  
        printf("\nnode deleted\n");  
  
    }  
    else   
    {  
        ptr = head;  					// update ptr with head
        while(ptr ->next != head)  
        {  
            preptr=ptr;  
            ptr = ptr->next;  
        }  
        preptr->next = ptr -> next;  
        free(ptr);  
        printf("\nnode deleted\n");  
  
    }  
}  
  

void display()  				// diaply function defination
{  
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        printf("\nnothing to print");  
    }     
    else  
    {  
        printf("\n printing values ... \n");  
          
        while(ptr -> next != head)  
        {  
          
            printf("%d\n", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);  		// printing Data
    }  
              
} 
void insert_m()				// insert function defination
{
	int count=0;
	struct node *new;
	struct node *temp;
	int ele,pos;
	printf("Enter ele : ");
	scanf("%d",&ele);			// user input
	printf("Enter pos : ");
	scanf("%d",&pos);
	printf("\n");
	new=(struct node *)malloc(sizeof(struct node));		// for malloc
	if(new==NULL)
	{
		printf("Error!\n");
	}
	else
	{
		while(temp!=head)
		{
			count++;
			if(pos==count)				// for finding exact location in linkedlist
			{
				new->next=temp->next;
				temp->next=new;		// updation with new node

			}
			temp=temp->next;
		}
	}

}
