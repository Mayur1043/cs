/*Q5: Implement your own string concatenation function.
(man strcat for reference)*/
#include<stdio.h>
#include<string.h>

int main()
{
	char name1[20];
	printf("Enter Your String : ");
	scanf("%s",name1);
	//printf("%s",name1);
	strcat(name1,"-Pro");
	printf("\nYour New String : %s\n",name1);		
	return 0;
}

