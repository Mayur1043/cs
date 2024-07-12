#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

#define FIFO_PATH "/home/desd/RB/os/Assignment2/q3/bipin" 

int main()
{
	int fd;
	char messages[100];

	fd = open(FIFO_PATH, O_RDONLY);

	if(fd ==-1){
		perror("failure");
		exit(0);
		}
//		while(1)
		{
			ssize_t num_bytes = read(fd,messages, sizeof(messages));

		if (num_bytes ==-1){
			perror("read");
			exit(0);
		}
		printf("receive meassages %s\n", messages);
		}
	close(fd);
			
	return 0;
}




