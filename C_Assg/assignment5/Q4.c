#include<stdio.h>
#define row1 3
#define col1 3
#define row2 col1 
#define col2 3
//void_mat_mul(int a[][3], int b[][3]);

int main()
{
	int i,j,k;
	int m1[row1][col1], m2[row2][col2],m3[row1][col2]; 
	
	printf("Enter the value of matrix 1 : \n");
	for(i=0;i<3;i++)
	{

		for(j=0;j<3;j++)
		{
			scanf("%d",&m1[i][j]);
		}
	}


	for(i=0;i<row1;i++)
	{

		for(j=0;j<col1;j++)
		{
			printf("%d\t",m1[i][j]);
		}
		printf("\n");

	}


	printf("Enter the value of matrix 2 : \n");
	for(i=0;i<row2;i++)
	{
		for(j=0;j<col2;j++)
		{
			scanf("%d",&m2[i][j]);
		}
	}


	for(i=0;i<row2;i++)
	{
		for(j=0;j<col2;j++)
		{
			
		printf("%d\t",m2[i][j]);
		}
		printf("\n");
	}

/*multiplication*/
	for(i=0;i<row2;i++)
	{
		for(j=0;j<col1;j++)
		{
			m3[i][j] = 0;
		for(k=0;k<col1;k++)
			m3[i][j] += m1[i][k] * m2[k][j];
		}
	}
	printf("multiplication :\n");
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col2;j++)
		{
			printf("%d\t\t",m3[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
