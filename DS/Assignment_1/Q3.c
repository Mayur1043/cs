/*Q3. Write C/C++ prgram which allocate and deallocate memory
dynamically.
(a) Allocating 1D array dynamically and access the elements
(b) Allocating 2D array dynamically
(1) contiguous rows with fixed no.of cols,
(2) Non contiguous rows with variable no.of columns
(c) Allocate memory for array of structure variables dynamically and
access members of each element*/

#include<stdio.h>
#include<stdlib.h>

void ele_access(int [], int);
void display(int [],int);
void array2(int [][10],int,int);
void arrayp(int [][10],int,int);

int main()
{	
	int a[10];
	int b[10][10];
	int i,n,choice,raw,col;
	int *p;
	p=a;
	printf("enter the no of array you want\n");
	scanf("%d",&n);

	p=(int *)malloc(sizeof(int)*n);
	if(p==NULL){
		printf("memory not available\n");
		exit(0);
	}

	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	printf("Enter the number of rows : ");
	scanf("%d",&raw);
	printf("Enter the number of colums : ");
	scanf("%d",&col);

	while(1){

	printf("\n1.Element You Want to Print\n2.display\n3.2D Array\n4.Array of pointer\n");
	printf("\nEnter the choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			ele_access(p,n);
			break;
		case 2:
			display(p,n);
			break;
		case 3:
			array2(b,raw,col);
			break;
		case 4:
	 		arrayp(b,raw,col);
				break;

	}
	}
	return 0;
}

void display(int p[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d\t",p[i]);
	}
}
void ele_access(int p[], int n)
{
	int pos;
	printf("Enter the oposition you want to access\n");
	scanf("%d",&pos);
	printf("%d",p[pos-1]);

}
void array2(int m[][10],int raw,int col)
{	
	for(int i=0;i<raw;i++)
	{
		for(int j=0;j<col;j++)
		{
			scanf("%d",&m[i][j]);
		}
	}
	for(int i=0;i<raw;i++)
	{
		for(int j=0;j<col;j++)
		{
			printf("%d ",m[i][j]);
		}
		printf("\t");
	}
}

void arrayp(int b[][10],int raw,int col)
{
	int *brr[raw];
	
	for(int i=0;i<raw;i++)
	{
	brr[i]=(int *)malloc(sizeof(int)*col);
	}
	
	for(int i=0;i<raw;i++)
	{
		for(int j=0;j<col;j++)
		{
		
		scanf("%d",&b[i][j]);
		}
	}
	
	printf("Your 2D array : ");
	
	for(int i=0;i<raw;i++)
	{
		brr[i]=b[i];
	}
	for(int i=0;i<raw;i++)
	{
		for(int j=0;j<col;j++)
		{
			printf("%d\t",*(*(brr+i)+j));
		}
	}
	printf("\n");
}
	






