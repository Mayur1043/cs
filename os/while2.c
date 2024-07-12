#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int ret;

	int age=10;
	ret=fork();
	fork();
	fork();
	if(ret==0)
	{
	printf("We Are In Child Process pid : %d, ppid : %d\n",getpid(),getppid());
	printf("age = %d\n",age);
	while(1);
	}

	else if(ret>0)
	{
		age=20;
		printf("We Are In Parent Process pid : %d, ppid : %d\n",getpid(),getppid());
		printf("age=%d\n",age);
		while(1);
	}

	printf("Failed to Create \n");
	return 0;
}
