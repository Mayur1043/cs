#include<stdio.h>
int main()
{
	FILE *fp;
	fp=fopen("fire.txt","r");
	fputs("it is ok\n",fp);
	printf("fp pos =%ld\n",ftell(fp));
	fseek(fp,3,SEEK_CUR);
	printf("fp pos =%ld\n",ftell(fp));

	fseek(fp,-5,SEEK_END);
	printf("fp pos =%ld\n",ftell(fp));

	fseek(fp,-5,SEEK_END);
	printf("fp pos =%ld\n",ftell(fp));

	fclose(fp);
	return 0;

}
