#include <stdio.h>
int main(){
    printf("enter a number to generate its table");
    int a,i,c;
    scanf("%d",&a);

    printf("table is as follows \n");

    for(i=0;i<=10;i++){
        c=a*i;
        printf("%d x %d = %d \n",a,i,c);
    }

}