#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	char buf1[512],buf2[512];
	int ret1,ret2;
	int pfd1[2], pfd2[2];
	char arr[50],arr2[50];

	ret1=pipe(pfd1);
	ret2=pipe(pfd2);

	if(ret1<0)
	{
		perror("errroe");
		exit(2);
	}

	ret1=fork();
	if(ret1<0);

	if(ret1 ==0)
	{                //read
                close(pfd1[1]);
                while((ret2=read(pfd1[0],buf1,512))>0)
                {
			strcpy(arr,buf1);
                        //write(STDOUT_FILENO,buf1,ret2);
                        printf("%s\n",arr);
			strcat(arr,"Rashi");
                }
                close(pfd1[0]);

		//write
		close(pfd2[0]);
		write(pfd2[1],arr,strlen(arr)+1);
		close(pfd1[1]);

	
	}


	if(ret1>0)
	{        
		//write
                close(pfd1[0]);
                write(pfd1[1],"SHikha",15);
                close(pfd1[1]);

		//read
		close(pfd2[1]);
		while((ret1=read(pfd2[0],buf2,512))>0)
		{
			//strcpy(arr,buf2);
			//strcat(arr,"rashi");
			//write(STDOUT_FILENO,buf1,ret1);
			printf("child = %s",buf2);
		}
		close(pfd2[0]);

	}
	return 0;
}



