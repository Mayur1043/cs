/*Q8. Implement a C program to check given no. is perfect no. or not
( eg 6, 28, 496, 8128 ( perfect no is equal to half the sum of
all its positive divisors for 6 it is (1+2+3+6) / 2 is 6)*/

#include<stdio.h>
int main()
{
int n,i,sum=0;
 printf("Enter the number:");
 scanf("%d",&n);
 for(i=1;i<n;i++)
 {
	 if(n%i==0)
	 {
		 sum+=i;
	 }
	 
 }
         if(sum==n)
	    {
		    printf("Perfect no.");
	    }
	    else
	    {
		    printf("Not Perfect:");
	    }

	    return 0;
}
