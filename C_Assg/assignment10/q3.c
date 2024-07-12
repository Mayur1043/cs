#include<stdio.h>
struct student{
	char name;
	int prn;
};
//int main()
//{
//#include<stdio.h>
//#include<stdlib.h>
int main()
{
        FILE *fp;
        int i=0;
        fp = fopen("bipin.txt","w");
        int arr[4]={20,30,40,50};

        for(i=0;i<4;i++)
        {
                fprintf(fp,"%d ",arr[i]);

        }

        fclose(fp);

        fp = fopen("bipin.txt","r");

        int arr1[4];
        for(int i=0;i<4;i++)
{
        fscanf(stdin,"%d",arr1+i);
        printf("%d ",arr1[i]);
}
fclose(fp);
}
      

