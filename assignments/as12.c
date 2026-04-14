#include <stdio.h>
/*12. To accept two numbers from user and compute smallest divisor and Greatest Common Divisor of these two numbers.*/
int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // -------- Smallest Divisor --------
    int min = (a < b) ? a : b;
    int smallest_divisor = 1;

    for(int i = 2; i <= min; i++) {
        if(a % i == 0 && b % i == 0) {
            smallest_divisor = i;
            break;   // first common divisor → smallest
        }
    }

    printf("Smallest common divisor = %d\n", smallest_divisor);

    // -------- GCD (Greatest Common Divisor) --------
    int gcd = 1;

    for(int i = 1; i <= min; i++) {
        if(a % i == 0 && b % i == 0) {
            gcd = i;   // keeps updating → last = greatest
        }
    }

    printf("GCD = %d\n", gcd);

    return 0;
}