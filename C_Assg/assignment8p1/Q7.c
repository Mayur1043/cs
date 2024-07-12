/*Q7: Write a C program to capture Alphabets from a given strings of mixed
alphabets, numeric and special characters. Store the captured data in another
array.
Example: array 1: “23w%#e$$lco--,me”
Output in array2: “welcome”*/

#include <stdio.h>

char string[256];
int character;
int c=0;

int main(){
    printf("Enter a string: ");
    while((character=getchar()) != '\n'){
        if((character>='A'&&character<='Z')||(character>='a'&&character<='z')){
           
            string[c++]=character;
        }
    }

        printf("Only Char : %s\n", string);
    return 0;
}

