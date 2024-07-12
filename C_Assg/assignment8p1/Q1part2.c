/*
Q1: Implement your own string length finding program, print the length of the
given string.*/

#include<stdio.h>
int length(char arr[]);
int compare(char arr[]);

int count = 0;	
int main()
{
	char arr[10];
	char crr[10];
	length(arr);
	compare(arr);
	

	return 0;
}
int length(char arr[])
{
	printf("enter the string \n");
        scanf("%s",arr);

	printf("your array is ");
	for(int i=0;arr[i]!='\0';i++)
	{	
		printf("%c",arr[i]);
		count++;
	}	
	printf("\ncount =%d\n",count);
	
	return count;


}

int compare(char arr[])
{
	printf("enter the string \n");
	char crr[10];
        scanf("%s",crr);

	int d,a,b,i=0;
	int second=0;
	

	
	for(i=0;crr[i]!='\0';i++)
	{
	
		second++;
		
	}

	printf("\ncount =%d\n",count);
	printf("\nsecond =%d\n",second);
	int cmp =0;
		
		for(int k=0;k<count;k++)
		{
			
			//printf("arr %c, crr %c  ", arr[k], crr[k]);
			if (arr[k]!=crr[k])
			{	
				cmp = 1;
			}

		}

			printf("cmp = %d\n", cmp);
	

			if (cmp==0){
				printf("Same\n");
			}

			else
			printf("Different\n");
}
