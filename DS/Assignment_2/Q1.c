/*Q1. Write a C/C++ program to implement Linear Search. We need to check for duplicate inputs. If the
duplicate element is allowed then a linear search algo needs to implement accordingly. An
appropriate condition check needs to apply for element not found scenario.
(a) Search Element ( iterative approach )
(b) Search Element ( recursion approach )
(c) Print Input array ( iterative approach )
(d) Print Input array ( recursion approach )
(e) Print Input array reverse order ( iterative approach )
(f) Print Input array reverse order ( recursion approach )
*/

#include<stdio.h>

void search(int [],int,int);

int search_i(int [],int,int,int);
void input(int [],int);
void input_r(int [],int,int);
void reverse(int [],int);
void reverse_r(int [],int,int);

//void revorder(int [])
//void revorderrec(int [])

int main()
{
	int n,i,choice,ele,num;
	int a[10];
	int index=0;
	printf("How Many Element YOu Want To Enter : ");
	scanf("%d",&n);
	printf("Enter Your Array : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	
   while(1)
   {
	printf("\n1. Search Element(I)\n2. Search Element(R)\n3. Print Input Array(I)\n4. Print Input Array(R)\n5. Print In Reverse Order(I)\n6. Print In Reverse Order(R)\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			printf("enter Element You Want To Search : ");
			scanf("%d",&ele);
			printf("\n");
			search(a,n,ele);
			break;
		
		case 2:
			printf("enter Element You Want To Search : ");
			scanf("%d",&ele);
			num=search_i(a,ele,index,n);
			//printf("Element Found : %d",num);
			if(num==-1)
			{
			printf("Not Found\n");
			}
			
			break;
			
		case 3:
		 	input(a,n);
		 	break;
		 
		case 4:
			printf("Your array : ");
		 	input_r(a,index,n);
		 	break;
		 	
		 case 5:
		 	reverse(a,n);
		 	break;
		 	
		 case 6:
		 	index=n-1;
		 	printf("Your reverse array : ");
		 	reverse_r(a,index,n);
		 	break;
		 	
		 default:
		 	printf("invalid input\n");
		 	break;
	}
    }	
	
	
	return 0;
}

void search(int a[],int n,int ele)
{
	int i,flag=0;
	
	for(i=0;i<n;i++)
	{
		if(a[i]==ele)
		{
			flag=1;
			printf("Found\n");
		}
	}
	if(flag==0)
	{

		printf("Not Found\n");
	}
}

int search_i(int a[],int ele,int index,int n)
{
		if(index==n)
		{
			return -1;
		}
		else if(a[index]==ele)
		{
			printf("Element Found %d",ele);
			printf("\n");
			return ele;
		}
		else
		{
			search_i(a,ele,index+1,n);
		}

}

void input(int a[],int n)
{
	printf("Your array : ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void input_r(int a[],int index,int n)
{
	
	if(index<n)
	{
	printf("%d ",a[index]);
	
	input_r(a,index+1,n);
	}
}

void reverse(int a[],int n)
{
	int i;
	printf("Your Reverse Array : ");
	for(i=n-1;i>=0;i--)
	{
	printf("%d ",a[i]);
	}
	printf("\n");
}

void reverse_r(int a[],int index,int n)
{
	if(index<n)
	{
		printf("%d",a[index]);
		
		reverse_r(a,index-1,n);
	}
}
	
		
