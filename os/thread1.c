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
pthread_t thread;
int main()
{
	struct bipin m;
	
	
	m.j=12454;
	m.r=12;
	m.k='c';

	int a;
	a=pthread_create(&thread,NULL,fun,(void*)&m);
	if(a==0){
		printf("thread created\n");
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
	printf(" value of r %d\n",m->r);
	printf(" value of k %c\n",m->k);
	printf(" value of k %ld\n",m->j);
	printf("i am a thread\n");
	printf("i am a thread\n");
	printf("i am a thread\n");
	printf("i am a thread\n");
	printf("i am a thread\n");
	printf("i am a thread\n");
	printf("i am a thread\n");
	while(1);
	
}




