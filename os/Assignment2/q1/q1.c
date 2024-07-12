/*>>1 Create a program, have 2 child created from the parent
    process and establish pipe ipc between 2 childs.*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main()
{	
	int  a,ret,ret1,pipe1,pipe2;
	char buff[50],arr[20];
	int fd1,pfd[2];

	int pipe3=pipe(pfd);

	ret=fork();
	
	if(ret>0)
	{
	printf("Enter the string");
     scanf("%[^\n]s",arr);
	printf("I am a parent pid %d ,ppid %d\n",getpid(),getppid());
	ret1=fork();
	{if(ret1<0)
	{}

	if(ret1==0)
	{
		printf(" I am a 2nd child pid %d, ppid %d\n",getpid(),getppid());
		close(pfd[0]);
	
	
     
    // write(pfd[1],"1..this is a message from parent",33);//no formatting 
    //  write(pfd[1],"2..this is a message from parent",33); 
	write(pfd[1],arr,strlen(arr)+1);
		//write(STDOUT_FILENO,arr,pipe2);
		//strcpy(a,arr);
	}
	close(pfd[1]);
	exit(0);
	}
	
	}

	if(ret<0)
	{
		printf("fork is not created\n");
	}

	else if(ret==0)
	{
		printf("I am a child pid %d,ppid %d\n",getpid(),getppid());

	close(pfd[1]);

	while((pipe1=read(pfd[0],buff,33))>0)
	{
		write(STDOUT_FILENO,buff,pipe1);
	}
	close(pfd[0]);
	
	}

}
