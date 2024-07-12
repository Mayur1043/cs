#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char argv[])
{
	int p1[2];
	if(pipe(p1) == -1)
	{
		return 1;
	}
	int pid = fork();

	if(pid ==-1)
	{
		return 2;
	}
	if(pid==0)
	{
		//child process
	
	int a;
	if (read(p1[0], &a, sizeof(a)) ==-1)
	{
		return 3;
	}
	printf("received %d\n",a);

	a*=4;

	if (write(p1[1], &a, sizeof(a)) == -1)
	{
		return 4;
	}
	printf("wrote child %d\n",a); 
//close(p1[1]);
//close(p1[0]);	
}
else {
	//parent process
	srand(time(NULL));
	int c = rand() % 10;
	if (write(p1[1], &c,sizeof(c)) == -1)
	{
		return 5;
	}
	printf("wrote parent %d\n",c);

	if(read(p1[0], &c,sizeof(c)) == -1)
	{
			return 6;
	}
	printf("result %d\n",c);

}
//close(p1[0]);
//close(p1[1]);

return 0;
}

	


