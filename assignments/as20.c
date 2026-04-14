/*Write a C function to swap two numbers with and without pointers.
*/
#include <stdio.h>  
void swapWithPointers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapWithoutPointers(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapWithoutPointers - a: %d, b: %d\n", a, b);
}
int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Before swapping - num1: %d, num2: %d\n", num1, num2);
    
    swapWithPointers(&num1, &num2);
    printf("After swapping with pointers - num1: %d, num2: %d\n", num1, num2);

    // Resetting values for the next test
    num1 = 5;
    num2 = 10;
    
    swapWithoutPointers(num1, num2);
    printf("After swapping without pointers - num1: %d, num2: %d\n", num1, num2);

    return 0;
}