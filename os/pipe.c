#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){
	char buf[512];
	int ret,ret1,status;
	int pfd[2];

	ret = pipe(pfd);

	if(ret<0)
	{
		perror("error hai");
		exit(2);
	}

	ret = fork();

	if(ret<0);

	if(ret ==0)
	{
		close(pfd[1]);

		while((ret1=read(pfd[0],buf,512))>0)
		{
			write(STDOUT_FILENO,buf,ret1);
		}
		if(ret1<0){}
		close(pfd[0]);
	}
	if(ret>0)
	{
		close(pfd[0]);
		write(pfd[1],"hiii bipin",10);
		close(pfd[1]);
	}
	exit(0);
}
