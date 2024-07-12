/*Q12. What is the significance of following pointer
int (*q)[3][4];

What are the sizes of q, q, **q, **q
Write some code to test this with a 2D array.*/

#include <stdio.h>

int main()
{
    int arr[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    int (*q)[3][4] = &arr;

    printf("Size of q: %lu\n", sizeof(q));
    printf("Size of *q: %lu\n", sizeof(*q));
    printf("Size of **q: %lu\n", sizeof(**q));
    printf("Size of ***q: %lu\n", sizeof(***q));

    return 0;
}

