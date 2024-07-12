/*Q4. Count Duplicate Elements
Given an integer array, numbers, count the number of elements that occur more than once.
Example numbers = [1, 3, 3, 4, 4, 4]

There are two non-unique elements: 3 and 4.
Function Description:
Complete the function countDuplicate in the editor below.
countDuplicate has the following parameter(s):
int numbers[n]: an array of integers
Returns:
int: an integer that denotes the number of non-unique values in the numbers array*/

#include<stdio.h>

int main()
{
    int n,count=0;
	printf("Enter No Of Elements : ");
	scanf("%d",&n);
	int a[n];

	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				count++;
				break;
			}
		}
	}
	printf("No of duplicate ele %d",count+1);
	return 0;
}
