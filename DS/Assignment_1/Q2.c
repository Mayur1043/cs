/*Q2. Create an employee structure with the following members
empid, employee name, salary, year of joining etc.
Accept the data for certain no. o of employees and find their total,
average, max, min salary.
Also find out the employees with maximum, minimum service,use a
function to find service for each employee element in the array.*/

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>
#define size 20

typedef struct employee{
	int empid;
	char *name;
	int salary;
	struct{
		short int date;
		short int month;
		short int year;
	}ser;
	int Year;

}emp;

int i=0;

void form(emp *);
void display(emp *);
void totalavg(emp *);
void maxsalary(emp *);
void minsalary(emp *);
int service(emp *);


int main()
{
	
	int choice;
	emp a[size];
	
	while(1)
    {
	printf("\n1.employee_form\n2.Display\n3.totalavg\n4.max salary\n5.min salary\n6.exit\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	printf("\n");
	
	switch(choice)
	{
	
		case 1:
			if(i==size)
			{
				printf("data full\n");
				break;
			}
			
			form(a);
			break;
		
		case 2:
			display(a);
			break;
			
		case 3:
			totalavg(a);
			break;
			
		case 4:
			maxsalary(a);
			break;
			
		case 5:
			minsalary(a);
			break;
		
		case 6:
			exit(0);
			break;
			
		default :
			printf("Invalid Entry\n");
			break;
	}
    }

	return 0;
}
	
void form(emp *a)
{
	char buff[20];
	
	printf("Enter the emp id \n");
	__fpurge(stdin);
	scanf("%d",&(a+i)->empid);
	
	
	printf("Enter the name of employee\n");
	scanf("%s",buff);
	__fpurge(stdin);

	int j=strlen(buff);
	
	(a+i)->name = (char *)malloc(sizeof(char)*(j+1));
	strcpy((a+i)->name,buff);
	
	printf("Enter the salary of employee\n");
	__fpurge(stdin);
	scanf("%d",&a[i].salary);
	
	printf("Enter the year of joining\n");
	__fpurge(stdin);
	scanf("%d",&(a+i)->Year);
	
	i++;
}

void display(emp *a)
{	
	for(int j=0;j<i;j++){
	printf("Enter the emp id %d\n",a[j].empid);
	printf("Enter the name of employee %s\n",a[j].name);
	printf("Enter the emp salary %d\n",a[j].salary);
	printf("Enter the emp year joining %d\n",a[j].Year);
	printf("=================================\n");
	}

}

void totalavg(emp *b)
{
	int j,total=0;
	
	for(j=0;j<i;j++)
	{
	total = total+b[j].salary;
	}
	float avg = total/i;
	printf(" total salary is %.2f\n",avg);
	printf("========================="); 
	
	//total= a;
}

void maxsalary(emp *c)
{
	int j=0,k;
	int trap=c[j].salary;
	for(j=0;j<i;j++)
	{
		if(c[j].salary>trap)
		{
		trap=c[j].salary;
		k=j;
		}
	}
	printf("employee name : %s\n max salary of employee is = %d\n",c[k].name,trap);
	printf("===========================");
}
	//printf("Employee max salary is = %d\n",c[j].name 

void minsalary(emp *c)
{
	int j=0,k;
	int trap=c[j].salary;
	for(j=0;j<i;j++)
	{
		if(c[j].salary<trap)
		{
		trap=c[j].salary;
		k=j;
		}
	}
	printf("employee name : %s\n max salary of employee is = %d\n",c[k].name,trap);
	printf("===========================");
	
}


	
	
		
