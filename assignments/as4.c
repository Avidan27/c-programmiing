#include <stdio.h>
int main(){
    printf("please enter your basic pay \n ");
    int bsc;
    scanf("%d",&bsc);
    int pt,hra,tav,net,gross;
    pt=0.02*bsc;
    hra=0.1*bsc;
    tav=0.05*bsc;
    gross=bsc+hra+tav;
    net=gross-pt;
    printf("the net income is %d",net);


    
}