/*Q2. Write a C/C++ program to implement single linked list.
Implement below metioned functions. Apply all required condition
check & validation like list empty or not, while inserting/deleting by
position validate the position.
a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
e)listNodeCount f) deleteFromEnd g) deleteFromBeg
h)deleteFromPos i) deleteByElement j) reverseDisplay
k)freeAllNode l) reverseList m)sortedList*/

#include<stdio.h>
#include<stdlib.h>


struct node{
    struct node *pre;
    int data;
    struct node *next;
};


void iend(struct node **,int );
void display(struct node *);
void ibeg(struct node **,int );
void ipos(struct node **,int,int);
void dpos(struct node **,int);
int sort(struct node **,int);
void freenode(struct node **);
void count(struct node *);



int main()
{
    struct node *head;
    int  n,ele,pos;
    while(1)
    {
        printf("\n\t0.EXIT\n\t1.Insert At End\n\t2.Insert At Beg\n\t3.Display\n\t4.Insert At Position\n\t5.Delete At Pos\n\t6.Sort\n7.Free Node\n8.Count\n");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
                    exit(0);
            case 1:
                    printf("Enter the ele : ");
                    scanf("%d",&ele);
                    iend(&head,ele);
                    break;
            case 2:
                    printf("Enter the ele : ");
                    scanf("%d",&ele);
                    ibeg(&head,ele);
                    break;
            case 3:
                    display(head);
                    break;
            case 4: 
                    printf("Enter the ele : ");
                    scanf("%d",&ele);
                    printf("Enter the pos : ");
                    scanf("%d",&pos);
                    ipos(&head,ele,pos);
                    break;
            case 5:
                    printf("Enter the pos : ");
                    scanf("%d",&pos);
                    dpos(&head,pos);
                    break;
            case 6:
                    printf("Enter the ele : ");
                    scanf("%d",&ele);
                    sort(&head,ele);
                    break;
            case 7:
                    freenode(&head);
                    break;
            case 8:
                    count(head);
                    break;
                
        }
    }
    return 0;
}
void iend(struct node **p,int ele)
{
    struct node *temp;
    struct node *t1=*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=NULL;
    temp->pre=NULL;

    if(*p==NULL)
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

void display(struct node *p)
{
    struct node *t1=p;
    while(t1!=NULL)
    {
        printf("-->%d",t1->data);
        t1=t1->next;
    }
    
}

void ibeg(struct node **p,int ele)
{
    struct node *temp;
    struct node *t1=*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=NULL;
    temp->pre=NULL;
    if(*p==NULL)
    {
        *p=temp;
    }
    else
    {
        temp->next=*p;
        *p=temp;
    }

}

void ipos(struct node **p,int ele,int pos)
{
    int count=0;
    struct node *temp;
    struct node *t1=*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=NULL;
    temp->pre=NULL;
    if(*p==NULL)
    {
        *p=temp;
    }
    else
    {
        while(t1->next!=NULL)
        {
            count++;
           
            if((pos-1)==count)
            {
                temp->next=t1->next;
                t1->next=temp;
                temp->pre=t1;
                t1->next->pre=temp;
            }
              t1=t1->next;
        }
       

    }

}
void dpos(struct node **p,int pos)
{
    int count=0;
   
    struct node *t1=*p;
     struct node *t2;
   
        while(t1!=NULL)
        {
            t2=t1;
            t1=t1->next;
            if((pos-2)==count)
            {
                t2->next=t1->next;
            }
            count++;
       }
       free(t1);
     
}

int sort(struct node **p,int ele)
{
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->data=ele;
    new->next=NULL;
    new->pre=NULL;
    int num=new->data;
    if((*p)==NULL || ele<(*p)->data)
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
        new->pre=temp;
        temp->next=new;
    }
}

void freenode(struct node **p)
{
    struct node *temp=*p;
    while(temp!=NULL)
    {
        temp=temp->next;
        free(*p);
        (*p)=temp;
    }
}
void count(struct node *p)
{
    int count=0;
    struct node *t1=p;
    while(t1!=NULL)
    {
        count++;
        t1=t1->next;
    }
    printf("Total Node = %d",count);
}
