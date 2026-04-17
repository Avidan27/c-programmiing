#include <stdio.h>
#include <math.h>
int main() {
    long long binaryNum;
    int decimalNum = 0, i = 0, rem;

    printf("Enter a binary number: ");
    scanf("%lld", &binaryNum);

    while (binaryNum != 0) {
        rem = binaryNum % 10;
        decimalNum += rem * pow(2, i);
        binaryNum /= 10;
        i++;
    }

    printf("Decimal equivalent: %d\n", decimalNum);
    return 0;
}   