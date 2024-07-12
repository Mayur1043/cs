/*Q4: Write a program wherein, you will be taking input in array1 and based on
the size of array1 you need to copy the data of array1 into array2 of bigger size:

char array1[20] = “CDAC-ACTS-PUNE”;
char array2[30];
Output should appear as:
printf(“array1: %s”, array1); - --> CDAC-ACTS-PUNE
printf(“array2: %s”, array2); - --> CDAC-ACTS-PUNE*/
#include<stdio.h>
#include<string.h>

int main()
{
	char name1[20];
	char name2[30];

	printf("Enter Your String : ");
	scanf("%s",name1);
	int len = strlen(name1);
	//printf("strlen(name)=%ld\n",strlen(name1));
	
	for(int i=0;i<len;i++)
	{
		name2[i]=name1[i];
	}
	printf("Your Copy String : %s\n",name2);
	
		
	return 0;
}



