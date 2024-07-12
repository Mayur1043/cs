/*Q6: Implement the question 5 with an added feature, wherein at the end, user should be given an
option to verify the data, in-case user wishes to modify the entered data. If user wishes to
modify the data it has entered, new modified data should be displayed as output when
program ends.*/



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
	int l,n;
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
	
	printf("you want to change the details 1= yes or 2= No \n");
	scanf(" %d",&l);
	
	do

	{	
	if (l==1){
		printf("enter which option do you want to change\n");
		printf("1.name 2.age 3.gender 4.city 5.pincode 6.marital status 7.salary 8.EXIT \n");
		scanf("%d",&n);
		
		switch(n)
		{
			case 1:
				
				printf("enter name of applicant \n");
				scanf("%s",&a.name);
				break;
			 case 2:

                                printf("enter age of applicant \n");
                                scanf("%d",&a.age);
                                break;

			case 3:
				
				printf("enter gender of applicant \n");
				scanf(" %c",&a.gender);
				break;
			 case 4:

                                printf("enter city of applicant \n");
                                scanf("%s",&a.city);
                                break;

			case 5:
				
				printf("enter pincode of applicant \n");
				scanf("%d",&a.pincode);
				break;

			 case 6:

                                printf("enter Marital status of applicant \n");
                                scanf(" %c",&a.marital_status);
                                break;

			 case 7:

                                printf("enter Salary of applicant \n");
                                scanf("%d",&a.salary);
                                break;
			 case 8:
                                
				printf("Form detail \n");
				printf("Name is : %s\n",a.name);
				printf("Age  is : %d\n",a.age);
				printf("Gender is : %c\n",a.gender);
				printf("City is : %s\n",a.city);
				printf("Pincode is : %d\n",a.pincode);
				printf("Marital  is : %c\n",a.marital_status);
				printf("Salary is : %d\n",a.salary);
				break;
                                return -1;
                                
			default :
				printf("Invalid Number\n");

                          

		}		
	}

	else
	{	
	//printf("-------------------------\n");
	printf("Form detail \n");
	printf("Name is : %s\n",a.name);
	printf("Age  is : %d\n",a.age);
	printf("Gender is : %c\n",a.gender);
	printf("City is : %s\n",a.city);
	printf("Pincode is : %d\n",a.pincode);
	printf("Marital  is : %c\n",a.marital_status);
	printf("Salary is : %d\n",a.salary);
	}
	
	}
	
	while(n<8);
	//return 0;
}

