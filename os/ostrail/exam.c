#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

struct stand {
	int a;
	char b;
long unsigned d;
};

void *producer(void *);
void *consumer(void *);

pthread_t p1;
pthread_t p2; 

int main()
{	
	int ret,ret1;
	
	struct stand z;
	z.a=24;
	z.b='k';
	z.d=80000000;
	
	ret=fork();	
	if(ret>0)
	{
	printf(" I am a parent pid %d, ppid %d\n",getpid(),getppid());
		ret1=fork();			
		if(ret1==0)
		{
		printf("I am a child2 pid %d ppid %d\n",getpid(),getppid());
		pthread_create(&p1,NULL,consumer,(void *)&z);
		}
		
	}
	else if(ret==0)
	{
		printf("I am a child1 pid %d ppid %d\n",getpid(),getppid());
		pthread_create(&p1,NULL,producer,(void *)&z);			
	}
	else
	{
		perror("fork not created");
		exit(0);
		}
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);	
	return 0;
}

void *producer(void *g)
{
	struct stand *z=(struct stand *)g;
	printf("I am a producer\n");
	printf("value of a %d\n",z->a);
	printf("value of b %c\n",z->b);
	printf("value of d %ld\n",z->d);
}

void *consumer(void *q)
{
	struct stand *z=(struct stand *)q;
	printf("I am a consumer\n");
	printf("value of a %d\n",z->a);
	printf("value of b %c\n",z->b);
	printf("value of d %ld\n",z->d);
}	



