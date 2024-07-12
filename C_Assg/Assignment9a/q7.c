/*Using function calls, create a structure variable in one function and return the structure
variable to the caller function, where caller can use the data returned by function to display
the output.
Example:
main(){

	struct data var = function();
	----- code to display var data ----
i	}
	struct data function()
	{
		struct data var1;
		--- initialization code ---
		return var1;
	}
*/


#include<stdio.h>
struct add{
       	int a;
	int b;
 	int c;
};


struct add fun();
void display (struct add d);


int main(){
	struct add a1=  fun();
	display(a1);
	return 0;
}




struct add fun(){
	struct add x;
	 x.a = 10;
	 x.b = 15;
	 x.c = 29;

	 return x;
	
}

void display (struct add d){
	printf("%d\n",d.a);
	printf("%d\n",d.b);
	printf("%d\n",d.c);
	
	return;
}
