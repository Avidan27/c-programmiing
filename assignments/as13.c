/*13. To accept a number from user and print digits of number in a reverse order.*/
#include <stdio.h>
int main(){
    printf("enter a number and i will print its digits in reverse order");
    
    int a,i;
    scanf("%d",&a);
//add digits one by one to a number
//digit counter--one by one iterate count++ when the number !=0
    int temp=a;
    int digit;
    int sum=0;
    
    while(temp!=0){
        digit=temp%10;
        temp=temp/10;
        sum=sum*10+digit;
    }
    printf("the number in reverse order is %d",sum);
}