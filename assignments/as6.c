/*Write a C function to compute the factorial of a number with and without recursion.*/
#include <stdio.h>  
#include <stdlib.h> 

// function to calculate factorial without recursion
int factorial_non_recursive(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}   

// function to calculate factorial with recursion
int factorial_recursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}

int main() {
    int number;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    // Calculate factorial using non-recursive method
    int non_recursive_result = factorial_non_recursive(number);
    printf("Factorial of %d (non-recursive) is: %d\n", number, non_recursive_result);

    // Calculate factorial using recursive method
    int recursive_result = factorial_recursive(number);
    printf("Factorial of %d (recursive) is: %d\n", number, recursive_result);

    return 0;
}