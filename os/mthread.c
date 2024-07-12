#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

struct bipin
{
	int r;
	char k;
	long int j;
};

void* fun();
//void* fun1();

pthread_t thread;
int main()
{
	struct bipin *m;
	m =(struct bipin*)malloc(sizeof(struct bipin));
	m->j=12454;
	m->r=12;
	m->k='c';

	int a,b;
	a=pthread_create(&thread,NULL,fun,(void*)m);
	if(a==0){
		printf("thread created\n");
	}
	else
	{
	printf("No created\n");
	}
	pthread_join(thread,NULL);

	b=pthread_create(&thread,NULL,fun,(void*)m);
	if(b==0){
		printf("thread created 2nd time\n"); 
	}
	else
	{
	printf("No created\n");
	}
	pthread_join(thread,NULL);
	exit(0);
}

void* fun(void* z_arg)
{
	struct bipin *m =(struct bipin*)z_arg;
	printf("i am a thread\n");
	printf(" value of r %d\n",m->r);
	printf(" value of k %c\n",m->k);
	printf(" value of j %ld\n",m->j);
	printf("i am a thread\n");
	printf("i am a thread\n");

	m->j=987987;
	m->r=65;
	m->k='p';
	while(1);
	
} 
