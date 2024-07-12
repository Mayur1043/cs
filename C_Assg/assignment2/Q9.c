#include<stdio.h>
int main()
{

        int n,rem,sum;
        printf("Enter Number : ");
        scanf("%d",&n);
        do{
            sum=0;
        
        
        while(n!=0)
        {
                rem=n%10;
                sum=sum+rem;
                n=n/10;

        }
    
        n=sum;
	printf("n=%d",n);
        }
        while(n>=10);
        {
                printf("Final sum is %d\n",n);
                
        }
        return 0;
}

