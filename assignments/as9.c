#include <stdio.h>
int main(){
    printf("enter a number to check if armstrong or not");
    int a,b,c,e=0;
    scanf("%d",&a);
    b=a;
    c=a%10;

    while(b!=0){
        c=b%10;
        e=e+c*c*c;
         b=b/10;
        
        

    }
    printf("%d",e);
}