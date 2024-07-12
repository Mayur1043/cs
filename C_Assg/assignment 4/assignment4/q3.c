/*
Q3. Write a program to find sum of n numbers.
*/


#include<stdio.h>
int sum(int [],int);
int n;
int main(){
	printf("how many numbers you want to sum of:");
	scanf("%d",&n);
	int arr[n];
	int size=sizeof(arr)/ sizeof(arr[0]);
	for(int i=0;i<size;i++)
		scanf("%d",&arr[i]);
	printf("sum = %d\n",sum(arr,size-1));
	return 0;
}
int sum(int arr[],int s)
{
	if(s==0)
		return arr[s];
	return arr[s]+sum(arr,s-1);
}


