/*Q9: Implement Q5 with data of n number of student (based on user input) and display the data at
the end.*/

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
	
	int n;

	printf("Enter how many student data you want to print\n");
	scanf("%d",&n);

	struct form a[n];
	
	for(int i=0;i<n;i++)
	{
	

	printf("enter name of applicant \n");
	scanf("%s",a[i].name);
	
	printf("enter age  of applicant \n");
	scanf("%d",&a[i].age);

	printf("enter gender of applicant M=male,F=female \n");
	scanf(" %c",&a[i].gender);

	printf("enter city of applicant \n");
	scanf("%s",a[i].city);

	printf("enter pincode of applicant \n");
	scanf("%d",&a[i].pincode);

	printf("enter M status  of applicant Y= yes, N= no \n");
	scanf(" %c",&a[i].marital_status);

	printf("enter salary of applicant \n");
	scanf("%d",&a[i].salary);

	printf("\n\n\n-------------------------\n");
	printf("Form detail \n");
	printf("Name is : %s\n",a[i].name);
	printf("Age  is : %d\n",a[i].age);
	printf("Gender is : %c\n",a[i].gender);
	printf("City is : %s\n",a[i].city);
	printf("Pincode is : %d\n",a[i].pincode);
	printf("Marital  is : %c\n",a[i].marital_status);
	printf("Salary is : %d\n",a[i].salary);
	}
	return 0;
}
