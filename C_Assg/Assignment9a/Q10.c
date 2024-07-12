/*Q10: Implement the Q5, by using dynamic memory allocation for data members “name” and
“city”.*/

/*Hint: pointers will be used in data members for name and city.*/

#include<stdio.h>
#include<stdlib.h>
struct form {
	char name [10];
	int age;
	char gender;
	char city [10];
	int pincode;
	char marital_status;
	int salary;

	int *p;
	int *x;

};

int main()
{
	//int x,p;
	struct form a;
	a.p=(char *)malloc(sizeof(char)*10);
	printf("enter name of applicant \n");
	scanf(" %s",a.p);

	printf("enter age  of applicant \n");
	scanf("%d",&a.age);

	printf("enter gender of applicant M=male,F=female \n");
	scanf(" %c",&a.gender);
	
	a.x=(char *) malloc(sizeof(char)*10);
	printf("enter city of applicant \n");
	scanf(" %s",a.x);

	printf("enter pincode of applicant \n");
	scanf("%d",&a.pincode);

	printf("enter M status  of applicant Y= yes, N= no \n");
	scanf(" %c",&a.marital_status);

	printf("enter salary of applicant \n");
	scanf("%d",&a.salary);

	printf("-------------------------\n");
	printf("Form detail \n");
	printf("Name is : %s\n",a.p);
	printf("Age  is : %d\n",a.age);
	printf("Gender is : %c\n",a.gender);
	printf("City is : %s\n",a.x);
	printf("Pincode is : %d\n",a.pincode);
	printf("Marital  is : %c\n",a.marital_status);
	printf("Salary is : %d\n",a.salary);

	free(a.p);
	free(a.x);
	return 0;
}
