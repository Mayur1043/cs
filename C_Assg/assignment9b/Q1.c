/*Q1:
Analyze the following code*/
union A
{
int x;
float y;
double z;
int arr[2];
}a1;
int main(){
a1.y=6.25f;
printf(“x=%x\n”, a1.x);
a1.z=0.15625;;
printf(“%x%x\n”,a1.arr[1],a1.arr[0]);
}
//Analyze the output of above code.
union B
{
int x;
short int y;
char ch;
char carr[4];
} b1;
b1.x=0x41424344;
/*Analyze the values of b1. y, b1.ch, print all elements of b1.carr
Modify b1.y =0x1122 or b1.ch= 0 and check the value of b1.x*/
