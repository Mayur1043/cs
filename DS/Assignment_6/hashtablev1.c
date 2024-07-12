#include<stdio.h>
#include<stdlib.h>						// Library for Malloc

#define SIZE 10						// Define SIZE
int hashFunction(int);
void insert(int *, int); 
int search(const int *, int); 				// Declaration of functions
void delete(int *, int); 
void display(const int *); 		

int main(){							// Staring main
	int arr[SIZE];
	for(int i=0; i<SIZE; i++){				// String -99 in array
		arr[i]=-99;
	}
	int choice, ele, index;
	while(1){
	printf("1->insert 2->display 3->search 4->delete 5->exit\n");
	scanf("%d", &choice);					// User Input
	switch(choice){		
		case 1:
			printf("enter a ele\n");
			scanf("%d", &ele);
			insert(arr, ele);			// Insert Function Call
			break;
		case 2:
			printf("-------------\n");
			display(arr);				// Display Function Call
			printf("-------------\n");
			break;
		case 3:
			printf("enter a ele to search\n");
			scanf("%d", &ele);
			index=search(arr, ele);
			if(index>=0 && index<SIZE){				// for Element Found
				printf("element =%d found\n", ele);
			}else {						// for Element Not Found
				printf("element =%d not found\n", ele);
			}
			break;
		case 4:
			printf("enter a ele to delete\n");
			scanf("%d", &ele);
			delete(arr, ele);
			break;
		case 5:
			exit(0);					// For EXIT
	}}
	return 0;
}

int hashFunction(int input){						// Function Defination
	int key = input%SIZE;
	return key;
}

void insert(int *a, int ele){
	int key=hashFunction(ele);
	if(a[key]==-99){
		a[key]=ele;
	}else{
		printf("slot is occupied\n");
	}
}

void display(const int *a){						// Display Function Defination
	for(int i=0; i<SIZE; i++){
		printf("key: %d = val: %d\n", i, a[i]);
	}
}

int search(const int *a, int ele){
	int key=hashFunction(ele);
	if( a[key]== ele){
		return key;
	} else {
		return -11;
	}
}
void delete(int *a, int ele){
	int index=search(a, ele);
	if(index == -11){
		printf("ele=%d not found \n", ele);
	}else {
		a[index]=-99;
	}
}









