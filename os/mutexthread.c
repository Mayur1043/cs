#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

struct bipin
{
	int r;
};

	void* fun();
	int h=0;
	pthread_mutex_t rushi;
	pthread_t thread,thread2;

	int main()
	{

		struct bipin m,p;
		
		m.r=1;
		p.r=8;
		int a,b;
		if(pthread_mutex_init(&rushi,NULL)!=0){
		
			printf("Mutex failed\n");

		}
		a=pthread_create(&thread,NULL,fun,(void*)&m);
			if(a==0){
		//		printf("thread created\n");
			}
			else
			{
			printf("No created\n");
			}

		b=pthread_create(&thread2,NULL,fun,(void*)&p);
			if(b==0){
		//		printf("thread created 2nd time\n"); 
			}
			else
			{
				printf("No created\n");
			}
			

			pthread_join(thread,NULL);
			pthread_join(thread2,NULL);

		pthread_mutex_destroy(&rushi);
		printf("\nValue of H is %d ",h);
		exit(0);
	}

	void* fun(void* z_arg)
	{
		pthread_mutex_lock(&rushi);	
		
		struct bipin *k =(struct bipin*)z_arg;

		
		int i=0;
		int p=k->r;
	
		while(i<800000)
		{
		
			if(p==1)
				{
					h++;
					i++;
				}
			if(p==8)
				{
					h--;
					i=i+2;
				
				}
				
		}
		
		pthread_mutex_unlock(&rushi);

		
	} 
