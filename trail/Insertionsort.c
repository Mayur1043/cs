#include<stdio.h>
void isort(int [], int);
int main()
{
    int a[5];
    int j;
    printf("enter the five elements in array\n");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
        
    }
    printf("Array before sort : ");
    for(int i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    
    isort(a,5);
    
    printf("Array after sort : ");
    for(int i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void isort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp= a[i];
        j = i-1;
        while(j>=0&& a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
        
    }
    
}


