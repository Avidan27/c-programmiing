#include <stdio.h>
int main(){
    int i,j;
    int a[2][2];
 printf("enter 4 elemtns for making the 2x2 matrix \n");
 for(i=0;i<2;i++){
    for(j=0;j<2;j++){
     scanf("%d",&a[i][j]);
    }

 }

 for(i=0;i<2;i++){
  for(j=0;j<2;j++){
    printf("%d ",a[i][j]);

    if(j==1){
    printf("\n");
  }
  }
  
 }
}
