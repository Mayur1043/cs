#include<pthread.h>
#include<sys/types.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include <sys/sem.h>
#include<sys/shm.h>
#include<string.h>
#include<stdio_ext.h>

#define KEY 1111

struct shmarea{
    char name[20];
    int prn;
    char module[10];
}*shared;

 //creating a pointer to the struct

pthread_mutex_t mute;   //creating variable for mutex

void *producer(void *arg)
{	
	char n_buff[20];
	int n;
     pthread_mutex_lock(&mute);
     	printf("Enter name: ");
     	__fpurge(stdin);
	fgets(n_buff, sizeof(n_buff), stdin);
     	strcpy(shared->name,n_buff);
	    
	printf("Enter PRN: ");
    	scanf("%d",&shared->prn);
     	
	printf("Enter Module Name: ");
     	__fpurge(stdin);
	fgets(n_buff, sizeof(n_buff), stdin);
     	strcpy(shared->module,n_buff);
    pthread_mutex_unlock(&mute);
    return NULL;
}

void *consumer(void *arg)
{
	//struct shmarea *p = (struct shmarea *)arg;	
     pthread_mutex_lock(&mute);
     	printf("------STUDENT DETAILS-----\n");
     	printf("Name: %s",shared->name);
     	printf("Prn: %d\n",shared->prn);
     	printf("Module: %s\n",shared->module);
     pthread_mutex_unlock(&mute);
    return NULL;
}

int main(){

  printf("HELLO\n");
  pthread_t s1,s2;
  int n,n1,id;
  id =  shmget(KEY,2*2*getpagesize(),IPC_CREAT|0600);

 if(id <0) 
     { 
	     perror("error in shmget"); 
	     exit(5); 
     }

    shared = shmat(id,0,0);
    pthread_mutex_init(&mute,NULL);
     
     n=pthread_create(&s1,NULL,producer,NULL);
    if(n!=0)
    {
        printf("Thread is not created\n");
    }
    else
    {
        printf("Thread 1 has been created\n");
    }

    n1=pthread_create(&s2,NULL,consumer,NULL);
    if(n1!=0)
    {
        printf("Thread is not created\n");
    }
    else{
        printf("Thread 2 has been created\n");
    }

    pthread_join(s1,NULL);
    pthread_join(s2,NULL);

  pthread_mutex_destroy(&mute);
  
  
  return 0;

}
