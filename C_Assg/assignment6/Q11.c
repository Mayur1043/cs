/*Q11. Give an expression to print last element of array irrespective of
length using pointer notation.
(You shouldn't consider length or size of array)*/

#include<stdio.h>
int main()
{
	int a[5]={10,20,30,40,50};
	int ptr=(&a+1);
	printf("%d ",*(ptr-1));
	return 0;
}
