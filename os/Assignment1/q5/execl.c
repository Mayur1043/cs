/*>>5 Create a process and implement execl() to run another command.
    Observe the O/P in top and ps. Check the PID and PPID and share
    your observation.*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{	
	int ret =fork();
	if(ret>0)
	{
		printf("i am a parent pid %d and ppid %d\n",getpid(),getppid());
		//execl("/usr/bin/evince","evince","/home/desd/ok/cdac_sharing_data-master/Mastering STM32.pdf",NULL);
	}
	else if(ret ==0)
	{
		printf("i am a child pid %d ppid %d\n",getpid(),getppid());
		//execl("/usr/bin/gcc","gcc","-o", "OUTER","modify2.c", NULL);
		execl("/usr/bin/evince","evince","/home/desd/Downloads/Operating System Concepts, 9th Edition.pdf",NULL);
	//	execl("/usr/bin/rm","rm","OUTER", NULL);
	}

	else 
	{
		printf("parent\n ");
	}
	return 0;
}


/*OBERSVATION ->
     IN THIS WE WILL OBSERVE THAT THE EXECL REPLACE THE CURRENT PROCESS BY THE NEW PROCESS i.e. IN PROGRAM THE FORK IS CREATED 1 CHILD AND PARENT PROCESS WHICH IS REPLACE BY THE NEW PROCESS WHICH IS CALLED BY THE EXECL HENCE WE WILL CONCLUDE THAT THE EXECL IS REPLACE THE CURRENT PROCESS BY THE NEW PROCESS WHICH IS PDF GIVEN IN THE PROGRAM.*/ 
