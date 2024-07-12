/*
Q1: Implement your own string length finding program, print the length of the
given string.*/

#include<stdio.h>
int length(char arr[]);
int copy(char arr[]);
int compare(char arr[]);

int count =0;	
int main()
{
	char arr[10];
	printf("enter the string \n");
	scanf("%s",arr);
	length(arr);
	compare(arr);
	//copy(arr);

	return 0;
}
int length(char arr[])
{
	printf("your array is ");
	for(int i=0;arr[i]!='\0';i++)
	{	
		printf("%c",arr[i]);
		count++;
	}	
	printf("\ncount =%d\n",count);
	
	return count;


}

int copy(char arr[])
{
	int i,j;
	char brr[10];
	for(i=0;arr[i]!='\0';i++)
	{
		brr[i]=arr[i];
	
	}
       brr[i]='\0';	
	printf("copy array is %s\n",brr);

	
}
int compare(char arr[])
{
	int d,a,b,i;
	int second=0;
	int crr[10];
	printf("enter your second array \n");
	scanf("%s",crr);	
//	d=length(crr);

	
	for(i=0;crr[i]!='\0';i++)
	{
		printf("%c",crr[i]);
		second++;
		//return second;
	}


	crr[i]='\0';

	printf("\ncount =%d\n",count);//0
	printf("\nsecond =%d\n",second);
	
	if(count==second)
	{
		printf("same\n");
	}
	else
	{
		printf("Not\n");
	}

}

