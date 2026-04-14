/*To accept the number of terms n finds the sum of sine series.*/

#include <stdio.h>
#include <math.h>

// factorial function OUTSIDE main
int factorial(int n) {
    int result = 1;
    for(int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    printf("Enter the number of terms: ");
    int n;
    scanf("%d", &n);

    printf("Enter the value of x (in radians): ");
    double x;
    scanf("%lf", &x);

    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        double sign = pow(-1, i);  // keeping pow()
        double term = sign * pow(x, 2 * i + 1) / factorial(2 * i + 1);
        sum += term;
    }

    printf("Sum of the sine series: %lf\n", sum);

    return 0;
}