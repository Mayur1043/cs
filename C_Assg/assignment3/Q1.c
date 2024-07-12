//Q1. Write a C program to print pascal triangle.

#include<stdio.h>
int main()
{
	int n,a=1,b,i,j;
	printf("Enter the number:");
        scanf("%d",&n);
        
          for(i=0;i<n;i++)
           {
		   a=1;
            for(b=0;b<=(n-i)-2;b++)
             {
              printf(" ");
             }

	    for (j=0;j<=i;j++)

	    {

		    if(j==0 || i==0) {
			    a=1;
                     }

		    else
			a=a*(i-j+1)/j;
			printf("%d ",a);
		    
	    } 

	printf("\n");
	}
   return 0;
}
