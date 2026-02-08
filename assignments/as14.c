#include <stdio.h>
#include <math.h>
/* this is comment - enter a binary form user to convert into decimal*/
/*decimal numbers can be found by taking each digit of binary*/
int main(){
    printf("input a binary number to convert it into decimal");
    int a,t,count=0,i;
    scanf("%d",&a);
    t=a;
    int b,sum=0,r=0;
/*count the number of digits*/
while(t!=0){
    count=count+1;
    t=t/10;

}
for(i=0;i<count;i++){
 b=a%10;
 a=a/10;
 r=(int)pow((double)2,(double)i)*b;
 sum=sum+r;
}
printf("%d",sum);


}