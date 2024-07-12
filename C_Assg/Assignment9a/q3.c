/*(with or without loop)
Q3: Using array of structure, write a C program to find the area of 3 rectangles. Store the
dimensions of rectangle and calculated area in the structure itself. (User Input);*/
#include<stdio.h>
struct area {

	int l,b,ans;
};
int main()
{
	struct area arr[3];

	WITHOUT LOOP :

	printf("enter first l and b resp \n");
	scanf("%d%d",&arr[0].l,&arr[0].b);
	arr[0].ans= arr[0].l*arr[0].b;
	printf("ans is %d\n",arr[0].ans);


	printf("enter second  l and b resp \n");
	scanf("%d%d",&arr[1].l,&arr[1].b);
	arr[1].ans= arr[1].l*arr[1].b;
	printf("ans is %d\n",arr[1].ans);


	printf("enter third l and b resp \n");
	scanf("%d%d",&arr[2].l,&arr[2].b);
	arr[2].ans= arr[2].l*arr[2].b;
	printf("ans is %d\n",arr[2].ans);
	
	WITH LOOP :

	for(int i=0;i<3;i++)
	{
	scanf("%d%d",&arr[i].l,&arr[i].b);
	arr[i].ans= arr[i].l*arr[i].b;
	printf("ans is %d\n",arr[i].ans);
	}

	return 0;


}
