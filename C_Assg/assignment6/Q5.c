#include<stdio.h>

//WAP to Convert from one type of pointer/address to other using void*

/*int main()
{

	void *vp;
	int a=10;
	printf("vp=%u\n",vp);//10 address
	//printf("*vp=%d",*vp);//garbage
	printf("vp+1=%u\n",vp+1); //garbage+1
	
	
	vp=&a;
	// printf("*vp=%d",*vp);//garbage
	printf("(int*)vp=%u\n",(int*)vp);//garbage

	printf("*(int*)vp=%d",*(int*)vp);//garbage
	return 0;*/


int main(){
	void *vp;
	int a=10;
	vp=&a;
	printf("&a =%u\n",&a);
	printf("vp =%u\n",vp);

	printf("(int*)vp =%u\n",(int*)vp);

//	printf("*vp =%u\n",*vp);

	printf("*(int*)vp =%u\n",*(int*)vp);

	printf("*(int*)vp+1 =%u\n",*(int*)vp+1);

	printf("vp =%u\n",vp);
	return 0;
	}
