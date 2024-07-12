#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void* fun();
pthread_t thread;
int main()
{
	int a;
	a=pthread_create(&thread,NULL,fun,NULL);
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

void* fun()
{
	printf("i am a thread\n");
	printf("i am a thread\n");
	printf("i am a thread\n");
	printf("i am a thread\n");
	printf("i am a thread\n");
	printf("i am a thread\n");
	printf("i am a thread\n");
	while(1);
	
}




