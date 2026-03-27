#include <stdio.h>
int main(){
    int i;
    int a[4];
 printf("enter 4 elemtns for making the 2x2 matrix \n");
 for(i=0;i<4;i++){
 scanf("%d",&a[i]);
 }

 for(i=0;i<4;i++){
  printf("%d ",a[i]);
  if(i==1){
    printf("\n");
  }
 }
}
