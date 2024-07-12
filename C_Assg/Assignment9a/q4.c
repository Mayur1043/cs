/*Using structures in C, write a program to find the area of a given rectangle, and store the
dimensions and result in the structure data member. Make sure to use another function for
the calculation of area (passing structure variable to a function).*/

#include<stdio.h>


typedef struct area {

        int l;
	int b;
	int ans;

}AREA;
void rec(AREA var[3]);


int main()
{

        AREA arr[3];
	//AREA var ={3,5,8};
	rec(arr);

        return 0;


}
void rec(AREA arr[3])
{
//	int x,y,ans;
        for(int i=0;i<3;i++)
        {
        scanf("%d%d",&arr[i].l,&arr[i].b);
        arr[i].ans= arr[i].l*arr[i].b;
        printf("ans is %d\n",arr[i].ans);
        }

}

