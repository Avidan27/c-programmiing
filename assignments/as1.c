#include <stdio.h>
int main(){
    printf("enter a number to check leap year");
    int a;
    scanf("%d",&a);

    if(a%400==0){
        printf("it is a leap year ");
    }
    else {
       if(a%4==0 && a%100!=0){
        printf("it is a leap year");
       }
       else{
        printf("it is not a leap year");
       }
    }
}