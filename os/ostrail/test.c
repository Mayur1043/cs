#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int ret,ret1;

	ret=fork();
	if(ret==0)
	{
		printf(" I am child pid=%d ppid=%d/n",get pid,get ppid):
			while(1);
	}
	else if
	{
		printf("I am aparent pid =%d ppid=%d/n",getpid,getppid);
		while(1);
	
	}
	
	return 0;
}

