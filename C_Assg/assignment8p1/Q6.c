/*Q6: Write a C program to reverse the string “Welcome to CDAC Pune”, using
array notation and loops.*/

#include<stdio.h>
#include<string.h>
int main()
{
	char arr[20];
	printf("Enter Your String :");
	gets(arr);
	int i;
	int len=strlen(arr);
	printf("Your Reverse String : ");
	for(i=len-1;i>=0;i--)                                                                                                                                                   {

		printf("%c",arr[i]);
	}
	printf("\n");
	return 0;
}
