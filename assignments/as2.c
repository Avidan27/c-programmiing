#include <stdio.h>
void main(){
int c;
int a,b;
printf("hello world \n");
printf("input 1 for addition, 2 for subtraction , 3 for multiplication or 4 for divsion\n");
scanf("%d",&c);

printf("Enter two numbers a \n");
scanf("%d %d",&a,&b);

switch(c){
case 1:
printf("the result is %d",a+b);
break;
case 2:
printf("the result is %d",a-b);
break;
case 3:
printf("the result is %d",a*b);
break;
case 4:
printf("the result is %d",a/b);
break;
default:
printf("bad/wrong input");
}
}