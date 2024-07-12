#include<stdio.h>

void printArr(int []);

int main(){
	int arr[5]={10, 20, 30, 40, 50}; // declaration of array as well init
					 // here 5 indicate size
	
	printf("%d\n",arr[1]); // 20  // what 1 indicate here index// read 
			     //
	printf("%d\n", arr[4]); // 50 // read
				
	arr[1]=22; // write
	
	printf("%d\n",arr[1]); // 22  // read 
	printf("%d\n", arr[5]); //  // read
				//
	printArr(arr);
	return 0;
}

void printArr(int a[]){
	printf("inside printArr method\n");
	for(int i=0; i<5; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
