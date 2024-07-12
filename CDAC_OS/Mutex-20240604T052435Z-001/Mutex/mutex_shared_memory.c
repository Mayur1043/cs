#include<pthread.h>
#include<sys/types.h>
#include <time.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include <sys/sem.h>
#include<sys/shm.h>

#define KEY 1111

struct shmarea{
    unsigned long count1;
    unsigned long count2;
    unsigned long count3;
} * shared;

 //creating a pointer to the struct

pthread_mutex_t mute;   //creating variable for mutex

void *inc(void *arg)
{
    for(int i=0;i<500;i++)  
    {
      pthread_mutex_lock(&mute);
      shared->count1++;
      shared->count2++;
      shared->count3++;
      pthread_mutex_unlock(&mute);
    }
    return NULL;
}

void *dec(void *arg)
{
    for(int i=0;i<500;i++)  
    {
      pthread_mutex_lock(&mute);
      shared->count1--;
      shared->count2--;
      shared->count3--;
      pthread_mutex_unlock(&mute);
    }
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
    shared->count1 = 6533; 
    shared->count2 = 7533; 
    shared->count3 = 8533;
    pthread_mutex_init(&mute,NULL);
     n=pthread_create(&s1,NULL,inc,NULL);
    if(n!=0)
    {
        printf("Thread is not created\n");
    }
    else
    {
        printf("Thread 1 has been created\n");
    }

    n1=pthread_create(&s2,NULL,dec,NULL);
    if(n1!=0)
    {
        printf("Thread is not created\n");
    }
    else{
        printf("Thread 2 has been created\n");
    }

    pthread_join(s1,NULL);
    pthread_join(s2,NULL);

    printf("final value of shared counter is %ld\n", shared->count1);
    printf("final value of shared counter1 is %ld\n", shared->count2);
    printf("final value of shared counter2 is %ld\n", shared->count3);
  
  pthread_mutex_destroy(&mute);
  
  
  return 0;


}
