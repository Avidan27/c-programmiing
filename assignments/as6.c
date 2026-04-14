/*Write a C function to compute the factorial of a number with and without recursion.*/
#include <stdio.h>
// Recursive factorial function
int factorialRecursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);


// Iterative factorial function
int factorialIterative(int n) { 
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
int main() {
    int number;
    printf("Enter a number to compute its factorial: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    printf("Factorial of %d (recursive): %d\n", number, factorialRecursive(number));
    printf("Factorial of %d (iterative): %d\n", number, factorialIterative(number));

    return 0;
}