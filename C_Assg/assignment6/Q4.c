#include<stdio.h>

/*Q4. Given int a[5] = {10, 20, 30, 40, 50 };
int *p=a, *q=*(&a+1) - 1;
evaluate following expressions
*p++, *++p, (*p)++, ++(*p), ++*p, *(p++), *(++p)
*q--, *--q, --(*q), --*q,
(*q)--, *(q--), *(--q)*/


int main()
{

	int a[5]={10,20,30,40,50};
	int *p;
	int *q;
	p=a;
	q=*(&a+1)-1;


	printf("p = %d\n",p); //1000

	printf("q = %d\n",q);//1016

	printf("*p++ = %d\n",*p++);//10   post inc = 20

	printf("*++p = %d\n",*++p);//30

	printf("(*p)++ = %d\n",(*p)++);//30  post inc of ele = 31

	printf("++(*p) = %d\n",++(*p));//32

	printf("++(*p) = %d\n",++(*p));//33

	printf("*(p++) = %d\n",*(p++));//

	printf("*(++p) = %d\n",*(++p));

	printf("*q-- = %d\n",*q--);

	printf("*--q = %d\n",*--q);

	printf("--(*q) = %d\n",--(*q));

	printf("--*q = %d\n",--*q);

	printf("(*q)-- = %d\n",(*q)--);

	printf("*(q--) = %d\n",*(q--));

	printf("*(--q) = %d\n",*(--q));
	return 0;
}
