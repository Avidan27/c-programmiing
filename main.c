#include <stdio.h>
int main(){
printf("hello world this ic c and it thing single doutes are chars \n ");
printf("Enter 3 numbers for array one \n ");
int i;
int a[3];
int b[3];
int c[3];
for(i=0;i<3;i++){
    scanf("%d",&a[i]);
   
}
printf("enter 3 numbers for second array \n ");
for(i=0;i<3;i++){
    scanf("%d",&b[i]);
    c[i]=a[i]+b[i];
}
for(i=0;i<3;i++){
printf("%d  ",c[i]);
}
 
}