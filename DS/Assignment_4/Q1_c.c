#include<stdio.h>

void heap(int[],int);
void heapify(int[],int,int);

int main()
{
    int a[]={11,2,9,13,57,25,17,1,90,3};
    int i;
    printf("haeap sort\n");
    printf("array before sorting\t\n");
    for(i=0;i<10;i++)
    {
        printf("%d\t",a[i]);

    }
    heapsort(a,10);

    printf("after the sorting\t\n");
    for(i=0;i<10;i++)
    {
        printf("%d\t",a[i]);
    }
}


void heapsort(int a[],int size)
{
    int i,t;

    for(i=size/2-1;i>=0;i--)
        heapify(a,size,i);
    for(i=size-1;i>=0;i--)
    {
        t=a[0];
        a[0]=a[i];
        a[i]=t;

        heapify(a,i,0);

    }
}

void heapify(int a[],int size,int i)
{
    int largest,leftchild,rightchild,t;

    leftchild=2*i+1;
    rightchild=2*i+2;

    if(leftchild>=size)
        return;
    largest=i;

    //if left child is larger than root
    if(leftchild<size&&a[leftchild]>a[largest])
    {
        largest=leftchild;
    } 
    if(rightchild<size&&a[rightchild]>a[largest])
    {
        largest=rightchild;
    }

    //if largest is not root
    if(largest!=i)
    {
        t=a[i];
        a[i]=a[largest];
        a[largest]=t;

        //heapify the attached subtree
        heapify(a,size,largest);
    }

}
