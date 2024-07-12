
/*Q8: Using array of structure and loops, write a C program to store radius and area of 10 circles,take
user input to initialize the circles, (make sure that user can see that for which circle he’s entering the
data), at the end display the area of all the circles.*/


#include<stdio.h>


typedef struct area {

        int r;
        float ans;

}AREA;
void rec(AREA var[3]);


int main()
{

        AREA arr[10];
        rec(arr);

        return 0;


}
void rec(AREA arr[10])
{

        for(int i=0;i<10;i++)
        {

	printf("Enter Radius Of %d circle : \n",i+1);
        scanf("%d",&arr[i].r);
        arr[i].ans= (arr[i].r) * (arr[i].r) * (3.14);
        printf("ans is %f\n",arr[i].ans);
        }

}


