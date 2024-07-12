#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_PATH "/home/desd/RB/os/Assignment2/q3/bipin"

int main()
{
	int fd;
	char messages[100];

	mkfifo(FIFO_PATH, 0666);

	fd = open(FIFO_PATH, O_WRONLY);

	if(fd ==-1){
		perror("'open");
	exit(0);
	}
		printf("enter the messages: ");
		fgets(messages,sizeof(messages), stdin);

		write(fd, messages,strlen(messages)+1);

		close(fd);

		unlink(FIFO_PATH);

		return 0;
}



