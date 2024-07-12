/*Q7. int arr[5]; int (*parr)[5];
parr=&arr;
sizeof(parr), sizeof(*parr), sizeof(**parr)
access array elements with suitable dereferencing of parr*/


#include<stdio.h>
int main()
{
	int *p;
	int (**ap);
	int arr[5]={10,20,30,40,50};

	p=arr;
	ap=&p;

//	int (*parr)[5]=&arr;
	printf("size of array is %u\n",*(arr));//20
	printf("%u\n",(**ap));

	printf("%u\n",*(*ap+1));
	//printf("size of pointer array is %d\n",(p));//8
	//printf("value at ap0 is %u\n",*(*(*ap)));//4

	printf("%u\n",(**ap)+1);
/*

	printf("value at ap1 is %u\n",(*ap+2));//4
	printf("value at ap2 is %u\n",*(*(ap)));//4
	printf("value at ap3 is %u\n",*(ap[3]));//4
	*/
	return 0;

}

