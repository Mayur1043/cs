#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{	
	int ret =fork();
	if(ret>0)
	{
		printf("i am a parent\n");
	}
	else if(ret ==0)
	{
		printf("i am a child\n");
		execl("/usr/bin/gcc","gcc","-o", "OUTER","modify2.c", NULL);
		
	//	execl("/usr/bin/rm","rm","OUTER", NULL);
	}

	else 
	{
		printf("parent\n ");
	}
	return 0;
}

