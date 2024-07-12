#include <stdio.h>
int main()
{
   char ch[]="visual studio code\n";
   char *c="visual studio code\n";

    printf("\n%d %d",sizeof(ch),sizeof(c));
    printf("\n%d %d",sizeof(*ch),sizeof(*c));


    return 0;
}
