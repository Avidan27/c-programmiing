#include <stdio.h>
#include <math.h>
int main(){
    printf("Enter your in-hand salary per month \n");
    printf("Enter your dream house and car combined cost(in lakhs) \n");
    int a=0,b=0;
    scanf("%d %d",&a,&b);
    int cost=b*100000;
int hrs=0;
hrs=8*22;
printf("salary per hour = %.2f \n",(float)(a/hrs));
printf("salary per day = %.2f \n",(float)(a/22));
double dreamdays=(double)cost/(double)(a/22);
 printf("Days required until dream complete = %.0lf\n", ceil(dreamdays));
}