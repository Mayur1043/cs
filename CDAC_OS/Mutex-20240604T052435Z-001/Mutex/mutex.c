#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mutex;


int i=0;

void *inc(void *arg) //a pointer function returning a void pointer
{
   pthread_mutex_lock(&mutex);
         for(int j=0;j<10;j++)
         {
         i++;
         printf("%d\n",i);
         }
        pthread_mutex_unlock(&mutex);
        printf("i in thread1:%d\n",i);
    }

void *dec(void *)
{
	  pthread_mutex_lock(&mutex);
          for(int j=0;j<10;j++)
	 {
	 i--;
          printf("%d\n",i);
         }
         pthread_mutex_unlock(&mutex);
         printf("i in thread2:%d\n",i);
}


int main(){
    pthread_t s1,s2;
    int n,n1;
    pthread_mutex_init(&mutex,NULL);
    n=pthread_create(&s1,NULL,inc,NULL);
    if(n!=0)
    {
        printf("Thread is not created\n");
    }
    else{
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

    printf("Final value %d\n",i);

    pthread_mutex_destroy(&mutex);
    return 0;
}
    






