/* Writie a C program to create a registration form for the user, the form should ask the
followingdetails:
Name: Age: Gender: City: PinCode:
Marital Status: Annual Salary:
Once input is received, display the data to the user.*/

#include<stdio.h>
struct form {
	char name [10];
	int age;
	char gender;
	char city [10];
	int pincode;
	char marital_status;
	int salary;

};

int main()
{
	struct form a;
	printf("enter name of applicant \n");
	scanf("%s",&a.name);
	
	printf("enter age  of applicant \n");
	scanf("%d",&a.age);

	printf("enter gender of applicant M=male,F=female \n");
	scanf(" %c",&a.gender);

	printf("enter city of applicant \n");
	scanf("%s",&a.city);

	printf("enter pincode of applicant \n");
	scanf("%d",&a.pincode);

	printf("enter M status  of applicant Y= yes, N= no \n");
	scanf(" %c",&a.marital_status);

	printf("enter salary of applicant \n");
	scanf("%d",&a.salary);

	printf("-------------------------\n");
	printf("Form detail \n");
	printf("Name is : %s\n",a.name);
	printf("Age  is : %d\n",a.age);
	printf("Gender is : %c\n",a.gender);
	printf("City is : %s\n",a.city);
	printf("Pincode is : %d\n",a.pincode);
	printf("Marital  is : %c\n",a.marital_status);
	printf("Salary is : %d\n",a.salary);
	
	return 0;
}
