			
#include<stdio.h>

void fun1();
int main(){
	fun1();
	return 0;
}	
void fun1(){
	int x=10, y=20, z=30, p=40;
	int arr[10000000]={0};

	static int count=0;
	printf("in fun1 with count = %d\n", ++count);
	fun1();
}

