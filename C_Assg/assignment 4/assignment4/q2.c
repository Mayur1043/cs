/*
Q2. Write a program to implement display and reverse display function
for string.
*/

#include<stdio.h>
#include<string.h>

void display(char *arr,int,int);
void revdisp(char *arr,int,int);

int main()
{ 
	int i=0;
	char arr[]="actscdac";
	int size=strlen(arr);
	display(arr,size,i);
	printf("\n");
	revdisp(arr,size,0);
}

void display(char *arr,int size,int i)
{

	if(i==size)
	{
		return;
	}
	else
	{
		printf("%c",arr[i]);
		display(arr,size,i+1);
	}
}

void revdisp(char *arr,int size,int i)
{
	if(i==size)
	{
		return;
	}
	else
	{
		revdisp(arr,size,i+1);
		printf("%c",arr[i]);
	}
}
