/*
Q1. Write a program to implement display and reverse display function
for integer array element.
*/

#include<stdio.h>

void display(int arr[],int,int);
void revdisp(int arr[],int,int);

int main()
{
	int i=0;
	int arr[5]={1,2,3,4,5};
	display(arr,5,0);
	printf("\n");
	revdisp(arr,5,0);
}

void display(int arr[],int size,int i)
{
	if(i==size)
	{
		return;
	}
	else
	{
		printf("%d ",arr[i]);
		display(arr,size,i+1);
	}
}

void revdisp(int arr[],int size,int i)
{
	if(i==size)
	{
		return;
	}
	else
	{
		revdisp(arr,size,i+1);
		printf("%d ",arr[i]);
	}
}
