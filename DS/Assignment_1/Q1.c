/*Q1. Write a C/C++ program that declares an array of length N
containing integers between 1 and N. Implement menu driven
program using switch case for below mentioned functionalities.
(a) insert element at index
(b) delete element at index
(c) find min val
(d) find max val
(e) display array element
(f) reverse display array element
(g) search element in array
(h) array element count
(i) avg of all array element
(j) determine if array contains any duplicates.
(k) reverse array element*/

#include<stdio.h>
#include<stdlib.h>				// use for exit
#include<stdio_ext.h>				// use for __fpurge__

void insert_index(int a[],int,int);  			// Declaration of Function.
void delete_index(int a[],int,int);
void display(int [],int);
//void reversedisplay(int [],int);
void max(int  a[],int x);
void min(int [],int);
void search(int [],int );
void avg(int [],int);
void rev(int [],int);
void count(int [],int);
void dup(int [],int);

int main()
{

	int a[10];					//array Declaration;
	int n,pos,x;
	printf("Enter how many element you want :\n"); 
	scanf("%d",&x);
	printf("Enter your elements : \n");

	for (int i=0;i<x;i++)   //loop for insert element in array 
	{
		scanf("%d",&a[i]);
	}
	
	while(1) 
	{
	printf("\tChoose Your Option : \n");
	printf("1.Insert Element At Index\n2.Delete Element At Index\n3.Min Val\n4.Max Val\n5.Display Array\n6.search\n7.avg\n8.Reverse\n9.count element\n10.duplicates array\n12.exit\n ");
	printf("\n");
	__fpurge(stdin); //for clear the buffer of input
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("\nEnter the index at you want to add : ");
			__fpurge(stdin);
			scanf("%d",&pos);
			insert_index(a,x,pos);    // call insert function
			x++;
			break;
		case 2:
			printf("Enter the index at you want to del : ");
			scanf("%d",&pos);
			delete_index(a,x,pos);    //call delete function
			x--;
			break;
		case 3:
			min(a,x);             //call min function
			printf("\n");
			break;
		case 4:
			max(a,x);         //call max function
			printf("\n");
			break;
		case 5:
			printf("your array : ");
			display(a,x);        //call display function
			printf("\n");
			break;
		case 6:
			 search(a,x);      // call search function
			 break;
		case 7:
			 avg(a,x);	// call average function
			 break;
		case 8:
			 printf("your Reverse array : ");
			 rev(a,x);	// call reverse function
			 break;

		case 9:
			printf("Your Element Count is : ");
			count(a,x);	//call count function
			break;
		case 10:
			dup(a,x); 	// call duplicate function.
			break;

		case 11:
			reversdisplay(a,x);
			break;

		case 12:
			exit(0);	// Termination of Program
			break;

		default:
			printf("invalid input");
			break;


	}
	}
	return 0;
}
void insert_index(int a[],int c,int pos)	//Defination of insert function
{	
	int b;
	printf("Enter the element you want : \n");
	scanf("%d",&b);

	for(int i=c;i>=pos;i--)
	{
		a[i]=a[i-1];			//loop for insert element in array index
	}
	a[pos-1]=b;
}

void display(int a[],int x)		//Defination of display function 

{
	for(int i=0;i<x;i++)
	{
		printf("\t%d",a[i]);      //loop for display element of array
	}
}

void min (int  a[],int x)
{
	int min;

	min=a[0];
	for (int i=1;i<x;i++)       //loop for min value of array
	{	
		if(min>a[i])
		{
			min = a[i];
		}
	}
		printf("minimum value is %d\n",min);

}

void max (int  a[],int x)
{
	int max;

	max=a[0];
	for (int i=1;i<x;i++)    //loop for max value of array
	{	
		if(max<a[i])
		{
			max = a[i];
		}
	}
		printf("maximum value is %d\n",max);
}

void search(int a[],int x)
{	
	int b,i;
	printf("Enter the value :\n");
	scanf("%d",&b);
	int flag=0;             //flag for search element
	for(i=0;i<x;i++)	 
	{
		if(a[i]==b)
		{
			flag=1;
		}

	}
	if(flag==1)
	{
		
		printf("Element found !\n");
	}
	else
	{

		pintf("Element Not found !\n");
}
void avg(int a[],int x)
{
	int sum=0;
	for(int i=0;i<x;i++)     //loop for sum  of array element
	{
		sum+=a[i];
	}
	int avg=sum/x;    //total avg of array element
	printf("avg is : %d\n",avg);   
}

void rev(int a[],int x)
{
	for(int i=x-1;i>=0;i--) //loop for reverse the element of array
	{
		printf("\t%d",a[i]);
	}
	printf("\n");
}

void count(int a[],int x)
{	
	int count=0;
	for(int i=0;i<x;i++)     //loop for count the element of array
	{
		count++;
	}
	printf("%d\n",count);
}

void dup(int a[],int x)
{
	int count=0;
	for(int i=0;i<x;i++)      //loop for check duplicate of array element
	{
		for(int j=i+1;j<x;j++)
		{
			if(a[i]==a[j])
			{
			count=1;
			}
		}
	}
	if(count==0)
	{
	printf("not");
	}
	else
	{
		printf("Yes You have duplicate \n");
	}
}

void delete_index(int a[],int x,int pos)
{
	int b;
        printf("Enter the element you want to want \n");
        scanf("%d",&b);

	for(int i=pos-1;i<=x;i++){      // loop for delete the array element
		a[i]=a[i+1];
	}
}





