#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char argv[])
{
	int p1[2],p2[2],ret,ret2;
	ret=pipe(p1);
	ret2=pipe(p2);
	
	int pid = fork();

	if(pid==0)
	{
		//child process
	
	int a;
	close(p2[1]);
	if (read(p2[0], &a, sizeof(a)) ==-1)
	{
		return 3;
	}
	printf("received %d\n",a);
	close(p2[0]);
	
	//write
	close(p1[0]);
	a*=4;

	if (write(p1[1], &a, sizeof(a)) == -1)
	{
		return 4;
	}
	printf("wrote child %d\n",a); 
close(p1[1]);
//close(p1[0]);	
}
else if(pid>0) 
{
	//parent process
	close(p2[0]);
	srand(time(NULL));
	int c = rand() % 10;
	if (write(p2[1], &c,sizeof(c)) == -1)
	{
		return 5;
	}
	printf("wrote parent %d\n",c);
	close(p2[1]);
	
	//read
	close(p1[1]);
	if(read(p1[0], &c,sizeof(c)) == -1)
	{
			return 6;
	}
	printf("result %d\n",c);
	close(p1[0]);
}
//close(p1[0]);
//close(p1[1]);

return 0;
}
