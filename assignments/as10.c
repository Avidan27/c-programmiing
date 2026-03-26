/*10. To simulate a simple calculator that performs basic tasks such as addition, subtraction,
 multiplication and division with special operations like computing 
𝑥,𝑦,xy ,and 𝑥!
x!.
*/

#include <stdio.h>
int main(){
printf("hello world");
printf("enter two numbers x and y ");
int a,b;
scanf("%d %d",&a,&b);
int i,fact=1;
printf("PRESS 1 FOR ADDITION, 2 for subtraction, 3 for multiplication, 4 for division , 5 for factorial of first number");
int ch=0;
scanf("%d",&ch);

switch (ch)
{
case 1:
    /* code */
    printf("%d",a+b);
    break;
case 2:
printf("%d",a-b);
break;

case 3:
printf("%d",a*b);
break;

case 4:
printf("%lf",(double)a/b);
break;

case 5:
for(i=1;i<=a;i++){
fact=fact*i;
}
printf("%d",fact);
break;

default:
printf("invalid input");
    break;
}
}