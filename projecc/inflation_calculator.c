#include <stdio.h>

int main(){
    printf("so this is an inflation calculator (avg inflation last 10yrs is 4.8per)\n" );
    printf("enter the amount of money and number of years \n");
    int a=0,n=0,i=0;
    
    scanf("%d",&a);
    scanf("%d",&n);
    float val=(float)a;

    for(i=1;i<n;i++){
        val=val*0.952;
        printf(" year %d : amount: %f \n",i,val);
    }


}