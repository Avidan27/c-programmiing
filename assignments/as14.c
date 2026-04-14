#include <stdio.h>
#include <math.h>

int main(){
    printf("Enter a binary number: ");

    int a;
    scanf("%d", &a);

    int sum = 0, i = 0;

    while(a != 0){
        int digit = a % 10;

        if(digit != 0 && digit != 1){
            printf("Invalid binary number!\n");
            return 0;
        }

        sum += digit * pow(2, i);

        a = a / 10;
        i++;
    }

    printf("Decimal equivalent = %d\n", sum);

    return 0;
}