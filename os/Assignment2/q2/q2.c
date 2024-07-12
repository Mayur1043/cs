#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){
	char buf[512],buff[512];
	int ret,ret1;
	int pfd[2],pfd1[2];
	char arr[50];
	ret = pipe(pfd);
	ret1 = pipe(pfd1);
	if(ret<0)
	{
		perror("error hai");
		exit(2);
	}

	ret = fork();

	if(ret<0);

	if(ret ==0)
	{

		//write
		close(pfd1[0]);
		write(pfd1[1],"BipinCDAC from parent at ",25);
		close(pfd1[1]);
		
		//read
		close(pfd[1]);
		while((ret1=read(pfd[0],buf,512))>0)
		{
			write(STDOUT_FILENO,buf,ret1);
		}
		close(pfd[0]);



	}
	if(ret>0)
	{
		//read
		close(pfd1[1]);
		while((ret=read(pfd1[0],buff,512))>0)
		{
			write(STDOUT_FILENO,buff,ret);
			//strcpy(arr,buff);
			strcat(arr,"PUNE from child");
		}
		close(pfd1[0]);

		//write
		close(pfd[0]);
		write(pfd[1],arr,strlen(arr)+1);
		close(pfd[1]);
	}
	exit(0);
}
