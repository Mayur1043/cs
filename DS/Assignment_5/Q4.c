/*Q4. Write a C/C++ program to implement priority queue data
structure using array.*/
#include<stdio.h>
#include<stdlib.h> 						// for malloc
struct node{   
	
	int value;
	int pri;
}pq[5];

int isempty();
int isfull();
int insert(int,int);
int gethighpriority();
int delete();
void display();

int rear=-1;
 int n=5;
int main()				// starting main
	{
	  int p,ele;
	 
     
        int choice;
        while(1)
        {
            printf("\n\t1:insert\n\t2:get high priority \n\t3:delete \n\t4:display\n\t  5:exit");
           printf("\n\tenter the choice\n\t");
           scanf("%d",&choice);				// user input
             switch(choice)
             {
                  case 1:
                          if(isfull()){
                           printf("priority queue is full\n\t");
                          }
                          else{
                                   printf("enter element\n\t");
                                   scanf("%d",&ele);
                                   printf("enter priority \n\t");
                                   scanf("%d",&p);
                                   insert(ele,p);	//insert Function Call
                          }
                  		break;
                 
                  case 2:
                            if(isempty())
                            {
                              printf("priority is empty\n\t");
                            }
                            else
                            {
                                  p=gethighpriority();
                                   printf("\n\thighest priority --->%d\n\t",p);
                            }
                            
                  break;
                 
                  case 3:
                           if(isempty())
                            {
                              printf("priority is empty\n\t");
                            }
                            else{
                                  ele=delete();				// delete function call
                                  printf("%d is delete",ele);
                            }
                           
                  break;
                 
                  case 4:
                               if(isempty())
                            {
                              printf("priority is empty\n\t");
                            }
                            else{
                                 display();			// display function call
                            }
                  break;
                 
                 
                 
                  case 5:
                      exit(0);
                      default:
                      printf("wrong choice\n\t");
             }
             
        
        }
        return 0;
	}
	
		
	int isempty()				// function defination
	{    if(rear==-1)
	      return 1;
	      else
	      return 0;
	 }
	  
	  int isfull()
	  { 
	     if(rear==n-1)
	       return 1;
	       else
	       return 0;
	  }      	
	  int insert(int ele,int p)
	    {
		  rear=rear+1;
		  pq[rear].value=ele;				// storing value
		  pq[rear].pri=p;
	    }
	    
	    int gethighpriority()
	    {   int p=-1;
		  if(!isempty())			// check is empty condition
		  {
		    for(int i=0;i<=rear;i++)
		    {
		        if(pq[i].pri>p)
		        {
		               p=pq[i].pri;
		        }
		    }
		  }
		  return p;
	       }
		  
          int delete()						// function defination
          {
                int i,j,p,ele;
                p=gethighpriority();
                for(i=0;i<=rear;i++)
                {
                       if(pq[p].pri==p)
                       {
                              ele=pq[i].value;
                              break;
                       }
                }
                if(i<rear)
                {
                        for(j=i;j<rear;i++)
                            {
                                pq[j].value=pq[j+1].value;
                                pq[j].pri=pq[j+1].pri;
                            }
                }
                  rear=rear-1;
                  return ele;
          }
          
          void display()				// display Finction Defination
          {
              int i;
              printf("priority queue\n\t");
              for(i=0;i<=rear;i++)
              {
                 printf("value =%d---->priority =%d",pq[i].value,pq[i].pri); 
              }
          }
          
          
          
          
          
          
          
          
          
          
          
          
          
    
