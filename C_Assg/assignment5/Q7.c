
#include<stdio.h>

int main()
{

        int n;

        int i,j,k;
        int m1[3][3] ;
        int m2[2][2];

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

int x,y,z;
x=m1[0][0]*(m1[1][1]*m1[2][2]  -   m1[1][2]*m1[2][1]);


  
y=m1[0][1]*(m1[1][0]*m1[2][2]  -  m1[1][2]*m1[2][0]);

z=m1[0][2]*(m1[1][0]*m1[2][1]  -  m1[1][1]*m1[2][0]);

int result=(x-y)+z;
printf("Result : %d",result);



printf("\nEnter the value of matrix 2 : \n");
        for(i=0;i<2;i++)
        {

                for(j=0;j<2;j++)
                {
                        scanf("%d",&m2[i][j]);
                }
        }
        printf("3x3 Matrix : \n");
        
         for(i=0;i<2;i++)
        {

                for(j=0;j<2;j++)
                {
                        printf("%d\t",m2[i][j]);
                }
                printf("\n");
        }
        
        int r;
        r=m2[1][1]-m2[1][0];
        printf("2x2 Matrix :\n%d",r);
      return 0;
}
    
