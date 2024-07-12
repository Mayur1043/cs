#include<stdio.h>

int main()
{
 	int x,y,z,n,n1;
	printf("Enter First Number : ");
	scanf("%d",&x);

	printf("Enter Second Number : ");
	scanf("%d",&y);

	printf("Enter Third Number : ");
	scanf("%d",&z);

	int num=(x>y && x>z)?x:(y>x && y>z)?y:z;
	printf("Your Biggest Number is : %d\n",num);
	return 0;

}
