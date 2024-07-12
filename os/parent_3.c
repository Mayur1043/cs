#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int ret1,ret2,ret3;


	ret1=fork();
	ret2=fork();
	ret3=fork();
	if(ret1==0)
	{
	printf("Child :  pid : %d, ppid : %d\n",getpid(),getppid());
	}

	else if(ret1>0){
	
	if(ret2==0)
	{
	printf("We Are In Child 2 Process pid : %d, ppid : %d\n",getpid(),getppid());
	}

	else if(ret2>0)
	if(ret3==0)
	{
	printf("We Are In Child 2 Process pid : %d, ppid : %d\n",getpid(),getppid());
	}

	else if(ret3>0)
	{

		printf("We Are In Parent Process pid : %d, ppid : %d\n",getpid(),getppid());
		
	}

		//printf("We Are In Parent Process pid : %d, ppid : %d\n",getpid(),getppid());
		
	}
	
       }
       else{
       printf("Failed to create child");
       }

	return 0;

}
