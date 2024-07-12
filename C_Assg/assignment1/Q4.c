#include<stdio.h>

int main()
{
	char ch;
	printf("Enter Your Character : ");
	scanf("%c",&ch);
	switch(ch)
	{
	case 'e':
	case 'a':
	case 'i':
	case 'o':
	case 'u':
		printf("Your Char is Vowel\n");
		break;

	default:
		printf("Your Char is Not Vowel\n");
	break;
	}
	return 0;

}
