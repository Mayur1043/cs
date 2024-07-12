/*Q7. Write a program Number format conversions(decimal, binary and
octal)*/


#include<stdio.h>
void dec_to_bin();
void dec_to_octal();
void dec_to_hex();
int main()
{
	int n;
	printf("enter number to convert\n");
	scanf("%d",&n);

	dec_to_bin(n);
	dec_to_octal(n);
	dec_to_hex(n);
	return 0;
}

void dec_to_bin(int n)
{
	int i=0;
	int arr[32]={0,0};

	while (i<32)
	{
		arr[i]=n%2;
		n=n/2;

		i++;
	}
	printf(" binary number is: ");
	for (i--;i>=0;i--)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
}

void dec_to_octal(int n)
{
	int i=0;
	int arr[12]={0,0};

	while (i<12)
	{
		arr[i]=n%8;
		n=n/8;

		i++;
	}
	printf(" octal number is: ");
	for (i--;i>=0;i--)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
}
void dec_to_hex(int n)
{
	int i;
	char arr[8]={0,0};

	while (i<8)
	{
		int temp=n%16;
		if (temp<10)
			temp=temp+48;
		else
			temp=temp+55;
		arr[i]=temp;
		n=n/16;
		i++;
	}
	printf(" hex number is: ");
	for (i--;i>=0;i--)
	{
		printf("%c",arr[i]);
	}
	printf("\n");
}
