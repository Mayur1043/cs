/* User space file to test userspace / kernelspace data exchange module */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define DEV	"/dev/cdac_dev"

int main()
{
	int fd = open(DEV, O_RDWR);
	if (fd<0)
	{
		perror("Cannot open device file");
		exit(EXIT_FAILURE);
	}
	char buf[15];
    char prn[]="24034010130018";
	int nread = read(fd, (void *)buf, 15);
    if(nread<0)
    {
        perror("Error in reading from device");
        exit(EXIT_FAILURE);
    }
    printf("Read from kernel: %s\n", buf);
    int n1=strcmp(buf, prn);
    {
        if(n1==0)
        {
            printf("prn matches\n");
        }
        else
        {
            printf("prn does not match\n");
        }
    }

	close(fd);


	return (EXIT_SUCCESS);
}
