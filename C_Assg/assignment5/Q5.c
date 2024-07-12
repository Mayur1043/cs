#include<stdio.h>

int main()
{

int i,j;
int m1[3][3];
printf("Enter the value of matrix 1 : \n");
        for(i=0;i<3;i++)
        {

                for(j=0;j<3;j++)
                {
                        scanf("%d",&m1[i][j]);
                }
        }
        printf("Matrix is : \n");
        
         for(i=0;i<3;i++)
        {

                for(j=0;j<3;j++)
                {
                        printf("%d\t",m1[i][j]);
                }
                printf("\n");
        }


        
        printf("Transpose Matrix is : \n");

         for(i=0;i<3;i++)
        {

                for(j=0;j<3;j++)
                {
                        printf("%d\t",m1[j][i]);
                }
                printf("\n");
        }

return 0;
}
