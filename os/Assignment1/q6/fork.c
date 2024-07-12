/*>>6 Create child process using fork(), then call execl() from that
    child process and run aother command from that. Check the PID, PPID
    Share your observation.*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int ret;
	if(ret>0)
	{
		printf("I am a parent pid %d,ppid %d\n",getpid(),getppid());
	}
	else if(ret ==0)
	{
		printf(" I am a child pid %d ppid %d\n",getpid(),getppid());
		execl("/usr/bin/evince","evince","/home/desd/Downloads/Operating System Concepts, 9th Edition.pdf",NULL);
	}
	else 
	{
		printf("parent\n");
	}
	return 0;
}

/*OBERSVATION ->
     IN THIS WE WILL OBSERVE THAT THE EXECL REPLACE THE CURRENT PROCESS BY THE NEW PROCESS i.e. IN PROGRAM THE FORK IS CREATED 1 CHILD WHICH IS REPLACE BY THE NEW PROCESS WHICH IS CALLED BY THE EXECL HENCE WE WILL CONCLUDE THAT THE EXECL IS REPLACE THE CURRENT PROCESS BY THE NEW PROCESS WHICH IS PDF GIVEN IN THE PROGRAM.*/

