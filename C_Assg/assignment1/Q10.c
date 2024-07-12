#include<stdio.h>
int main()
{
        int i,j,s;
        for(i=0;i<5;i++)
        {
                for(s=3;s>=i;s--)
                {
                        printf(" ");
                }
                for(j=1;j<=(2*i)+1;j++)
                {
                        printf("%d",i+1);
                 }                
                printf("\n");
        }
        return 0;
}
