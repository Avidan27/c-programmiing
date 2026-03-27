/*8. To accept a student's five course marks and compute his/her result. Student is passing
 if he/she scores marks equal to and above 40 in each course. If student scores aggregate greater than 75%, then the
  grade is distinguished. If aggregate is 60% and <75 then the grade is first division. If aggregate is 50% and <60, then 
 the grade is second division. If aggregate is 40% and <50, then the grade is third division.*/


#include <stdio.h>
void main(){
printf("Enter the 5 course marks one by one");
int a=0,b=0,c=0,d=0,e=0;

scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);
scanf("%d",&d);
scanf("%d",&e);

int sum =a+b+c+d+e;
double perc=(double)sum/500.0;
printf("%lf \n",perc);

if (perc>0.6){
printf("FIRST DIVISION \n");
}
else if(perc>0.4 && perc<0.5){
printf("THIRD DIVISION \n");
}
else if(perc> 0.5&& perc<0.6){
printf("SECOND DIVISION \n");
}

if(a>40 && b>40 &&c>40 &&d>40 &&e>40){
    printf("passed");
}
else{
    printf("not passed");
}

}


