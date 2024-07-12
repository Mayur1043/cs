#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include <sys/sem.h>
#include<sys/shm.h>



struct sh_mem {
	int c;
	int c1;
	int c2;
	int c3;
};

	struct sh_mem *memory;


int main(){
	
	#define KEY1 37824
	
	int ret,ret1,ret2,id;


	id = shmget( KEY1, sizeof(struct sh_mem), IPC_CREAT|0666);

	memory = shmat(id,0,0);

	memory->c=30;
	memory->c1=30;
	memory->c2=30;
	memory->c3=30;


	ret = fork();

	if(ret==0){
	
		printf("\nChild Process- PID = %d\tPPID = %d",getpid(),getppid());
		long i=0;
		while(i++<1000000){
		
			memory->c++;
			memory->c2++;
			memory->c1++;
			memory->c3++;
		
		}

	
	}
	if(ret>0){
		printf("\nParent process PID -%d\tPPID = %d",getpid(),getppid());

		long i=0;
		while(i++<1000000){
		
			memory->c--;
			memory->c1--;
		
			memory->c2--;
			memory->c3--;
		
		
		
		}
	
		printf("final values:\n\tC:%d\n\tC1:%d\n\tC2:%d\n\tC3:%d",memory->c,memory->c1,memory->c2,memory->c3);
	}

}
