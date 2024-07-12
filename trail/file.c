#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	fp=fopen("file.txt","w");
        char ch[20];
	char arr[20];
	char *p=arr;
        //fgets(arr,10,fp);
	fputc ('1',fp);
	fputc ('2',fp);
	fputc ('3',fp);
	fputs("RUSHI",fp);
	fputs ("-MAYUR",fp);
	fputs ("-BIPIN",fp);
	fclose(fp);
	 fp=fopen("file.txt","r");
   
	fgets(arr,11,fp);
	printf("arr=%s\n",p);

	fclose(fp);

return 0;
}
