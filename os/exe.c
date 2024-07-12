
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int ret;
	ret=fork();
	if(ret==0)
	{
	printf("We Are In Child Process pid : %d, ppid : %d\n",getpid(),getppid());
	
	execl("/home/desd","gcc","exe.c","-o","exe.o",NULL);
	printf("execl->pid:%d,ppid:%d\n",getpid(),getppid());
	//execl("/home/desd","gcc","exe.c","-o","exe.o",NULL);
	while(1);
	}

	else if(ret>0)
	{
		printf("We Are In Parent Process pid : %d, ppid : %d\n",getpid(),getppid());
		while(1);
	}

	printf("Failed to Create \n");
	return 0;
}
