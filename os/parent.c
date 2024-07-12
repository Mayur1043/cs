#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int ret,ret1;


	ret=fork();

	if(ret==0)
	{
	printf("We Are In Child 1 Process pid : %d, ppid : %d\n",getpid(),getppid());
	}

	else if(ret>0){

	ret1=fork();
	//fork();

	if(ret1==0)
	{
	printf("We Are In Child 2 Process pid : %d, ppid : %d\n",getpid(),getppid());
	}

	else if(ret1>0)
	{

		printf("We Are In Parent Process pid : %d, ppid : %d\n",getpid(),getppid());
		
	}
       }
       else{
       printf("Failed to create child");
       }

	return 0;

}
