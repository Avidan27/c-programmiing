#include <stdio.h>

int main(){
    printf("Enter your in-hand salary per month \n");
    printf("Enter your dream house and car combined cost(in lakhs) \n");
    int a=0,b=0;
    scanf("%d %d",&a,&b);
    int cost=b*100000;
int hrs=0;
hrs=8*22;
printf("salary per hour = %f \n",(float)(a/hrs));
printf("salary per day = %f \n",(float)(a/22));
float dreamdays=(float)cost/(a/22);
printf("days required until dream complete =%f \n",dreamdays);
}