

#include<stdio.h>
#include<stdlib.h>					// for malloc
struct node{ 						// Declare Structure
     struct node *left,*right;
     int data;
};
void insert(struct node **,int);
void inorder(struct node *);
void preorder(struct node *);				// Declaration of Functions
void postorder(struct node *);
int countnode(struct node *);          

int main(){						// Staring main Function

struct node *head=NULL;				// Head use to store first node address 
  int choice,ele,m ;
  while(1){
  printf("\n\t1:insert\n\t2:preorder\n\t 3:preorder \n\t 4:postorder\n\t5:count total  node  \n\t 0:exit\n\t");
  printf("\n\tenter above choice\n\t");
  scanf("%d",&choice);					// User Input
    switch(choice){  
      
       case 0:
            printf("\n\tquite!!!!!!!!!!!!!\n\t");
            exit(0);					// For EXIT
    
          case 1:
            printf("\n\tenter element\n\t");
            scanf("%d",&ele);
          insert(&head,ele);				// Insert Funcrion Call
          break;
          
          case 2:
               printf("\n\ttree inorder traversal\n\t");
             inorder(head);				// Inorder Function Call
          break;
          
           case 3:
           printf("\n\ttree are in preorder\n\t");
           preorder(head);				// Preorder Function Call
           break;
           
           case 4:
           printf("\n\t Tree in post order\n\t");
           postorder(head);				// Postorder Function Call
           break;
          case 5:
              m=countnode(head);			// Countnode Function Call
              printf("\n\ttotal number in tree is %d\n\t",m);
               break;
          default:
          printf("\n\twrong choicen\n\t");		// For Wrong Input
          
    
    }
  
  }
}

void insert(struct node **p,int ele){

      if(*p==NULL)
      { 
           *p=(struct node *)malloc(sizeof(struct node));		// for Dyanamic Allocation
           (*p)->data=ele;
           (*p)->left=NULL;
           (*p)->right=NULL;
      }
      else{						// if head is not NULL then
      
             if(ele<(*p)->data)
             { 
             	insert(&((*p)->left),ele);
             }
             else{  
                   insert(&((*p)->right),ele);
             }
      }
   

}
void inorder(struct node *p){				// inoder Function Defination

        if(p!=NULL)
        { 
         inorder(p->left);
        printf("%d->",p->data);
        inorder(p->right);
}
}


void preorder(struct node *p)				// preorder derFunction Defination
{       if(p!=NULL)
       
        {
             printf("%d->",p->data);
             preorder(p->left);
             preorder(p->right);
        }
         

       
}
void postorder(struct node *p)			// Posrorder Function Defination
{
          if(p!=NULL)
     
          {
              postorder(p->left);
              postorder(p->right);
              printf("%d->",p->data);
          }
}

int  countnode(struct node *p)
{   
      int count=0;
      if(p!=NULL)
      {
             countnode(p->left);
             count++;
             countnode(p->right);
      }
         return count;
           
}  
	



