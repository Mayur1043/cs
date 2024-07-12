/*Q 10 : Access 2D array using pointers
int arr[3][4]; int (*p)[4]; p=arr;
sizeof(p), sizeof(p), sizeof(*p) , values of p, p+1
Check equivalence of arr[i][j], ((p+i))[j], *((p+i)+j)*/
#include<stdio.h>

int main()
{
	int a[3][4]={{1,2,3,4},{5,6,7,8},{8,7,6,5}};
	int (*p)[4];
	p=a;
	
	printf("sizeof(p)=%u\n",sizeof(p));    //8
	printf("sizeof(*p)=%u\n",sizeof(*p));  //16
	printf("sizeof(*p)=%u\n",sizeof(*p));  //4
	printf("p=%u\n",p);    //adress
	printf("p+1=%u\n",p+1);   //adress+16

	return 0;
}
