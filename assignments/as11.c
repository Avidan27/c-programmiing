/*11. To accept the number and compute:
a) square root of number
b) square of number
c) cube of number
d) check for prime
e) factorial of number
f) prime factors
*/
#include <stdio.h>
#include <math.h>
int main(){
    print("input a number you want to calculate");
    int a;
    scanf("%d",&a);
    print("press 1 for sq root, 2 for square, 3 for cube,\n 4 to check if number is prime , 5 to calc its factorial,\n
         6 to check its prime factors");
        int c;
        scanf("%d",&c);
    switch(c){
        case 1:
        break;
        printf("sq root is %lf",sqrt((double)a))
        case 2:
        prinftf("sqaure is")
        break;
        printf()

        case 3:
        printf("cube is ")
        break;

        case 4:
        printf("")
        break;

        case 5:for(i=1;i<=a;i++){
    fact=fact*i;
    }
    printf("%d",fact);
    break;
        

        case 6:
        printf()
        break;
    }
}