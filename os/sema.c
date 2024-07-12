#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>

#define KEY1 1256

#define KEY2 1256

struct shmarea {
	int x;
	char k;
	char m;
	long int j;
	unsigned long int b;
};

//struct shmera *shma;

union bipin{
	int val;
};

int main()
{
	int ret,ret1,id,sem_id,status;
	int i =0;
	struct shmarea *shma;

	struct sembuf sembuf1;

	union bipin a1;
	id=shmget(KEY1, 2*2*2*getpagesize(), IPC_CREAT|0660);
	
	shma= shmat(id,0,0);
	sem_id = semget(KEY2,1,IPC_CREAT|0600);

	a1.val=1;

	ret1 = semctl(sem_id,0,SETVAL,a1);
	ret1 = semctl(sem_id,0,GETVAL);

	printf("semapores is created values %d\n",ret1);
	

	shma->x =6565;
	shma->k ='c';
	shma->m ='s';
	shma->j =54564;
	shma->b =5324546552;

	int j=0;
	while(i++<1)
	{
		ret= fork();

		if(ret >0)
		{
			printf("I am parent process context");
			printf("in parent  pid %d and ppd %d\n",getpid(),getppid());
			sembuf1.sem_num = 0;
			sembuf1.sem_op = -1;
			sembuf1.sem_flg = 0;

			ret1 = semop(sem_id,&sembuf1,1);
			
			while(j++<8000000)
			{
				shma->x++;
			//	shma->k='q';
			//	shma->m='l';
				shma->j++;
				shma->b++;
			}
			sembuf1.sem_num =0;
			sembuf1.sem_op = 1;
			sembuf1.sem_flg = 0;

			ret1 = semop(sem_id,&sembuf1,1);

		}
	printf("parent process finished\n");

	if(ret==0)
		{
			printf(" i am child process");
			printf(" in child pid %d and ppid %d\n",getpid(),getppid());
			sembuf1.sem_num = 0;
			sembuf1.sem_op = -1;
			sembuf1.sem_flg = 0;
			
			ret1= semop(sem_id,&sembuf1,1);

			while(j++<8000000)
			{
				shma->x--;
			//	shma->y='q';
			//	shma->m='l';
				shma->j--;
				shma->b--;
			}
			
			sembuf1.sem_num = 0;
			sembuf1.sem_op = +1;
			sembuf1.sem_flg = 0;
			ret =semop(sem_id,&sembuf1, 1);
		}
	printf("child process is finished\n");
}

	if(ret>0)
{
	while(1)
	{
	ret = waitpid(-1,&status,0);
	if(ret<0)
	{
		printf("final value shared x %d\n",shma->x);
		//printf("final value shared y %c\n",shma->y);
		//printf("final value shared m %c\n",shma->m);
		printf("final value shared j %ld\n",shma->j);
		printf("final value shared r %ld\n",shma->b);

		shmctl(id,IPC_RMID,0);
		exit(0);
	}
	}
}
	
	
return 0;
}






