#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int ret =fork();
	if(ret>0)
	{
		printf(" I am a parent\n");
	}
	else if(ret ==0)
	{
		printf(" I am a child\n");
//		execl("/usr/bin/gcc","gcc","-o","OUTER","modify2.c",NULL);
		//execl("/usr/bin/gcc","gcc","/home/desd/ok/os/assignment1/child.c","/home/desd/ok/assignment1/temp",NULL);
		//execl("/usr/bin/evince","evince","/home/desd/ok/cdac_sharing_data-master/Mastering STM32.pdf",NULL);
//		execl("/usr/bin/evince","evince","/home/desd/Downloads/Operating System Concepts, 9th Edition.pdf",NULL);

	//	execl("home/desd/ok/assignment1/a.out","NULL);


		execl("/usr/bin/rm","rm","OUTER",NULL);
	}
	
	else
	{
		printf("parent\n");
	}
	return 0;
}


