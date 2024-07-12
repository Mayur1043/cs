#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc,char *argv[])
{
	char buf[512],wr_buf[512];
	int ret,ret1;
	int pfd[2];

	if(ret<0)
	{
		perror("error in the pipe");
	}

	ret =fork();
	
	if(ret==0)
	{
		printf("parent is created pid=%d, ppid=%d/n",getpid,getppid);
	close(pid[1]);
	}

       while( (ret1 = read(pfd[0],buf,512)) >0)
           {	
		   
                   write(STDOUT_FILENO,buf,ret1);
           }
           if(ret1<0){ }
           close(pfd[0]);
   }

if(ret>0)
{
	writepfd[1],"

	
