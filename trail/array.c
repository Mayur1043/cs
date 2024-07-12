#include<stdio.h>
int main()
{	
	int i,j,m,n;
	int a[5]={10,20,30,40,50};
	i=++a[1];
	j=a[1]++;
	printf("i=%d j=%d\n",i,j);
	i=1;
	m=a[i++];
	printf("i=%d m=%d\n",i,m);
	i=2;
	n=a[++i];
	printf("i=%d n=%d\n",i,n);
	
	return 0;
}
