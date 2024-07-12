#include<stdio.h>
#include<stdlib.h>

typedef struct student{

	char name[20];
	int prn;
}x;
int main()
{
	x a[10];
	
	FILE *fp;
	int i,n;

	fp=fopen("Rushi.txt","w");

	printf("Enter how many entry you want :\n");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter name and PRN : \n");
		scanf("%s %d",a[i].name,&a[i].prn);
		printf("\n");
		fprintf(fp,"%s %d",a[i].name,a[i].prn);
		fputc('\n',fp);
			
	}

	return 0;
}
