/*Write a program in C to perform basic operations such as addition, subtle point, inverse, magic square of two matrices.*/
#include <stdio.h>
int main() {
    int rows, cols;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    int matrixA[rows][cols], matrixB[rows][cols];
    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Addition
    int sum[rows][cols];
    printf("Sum of Matrix A and B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");


    }
    // Subtraction
    int diff[rows][cols];
    printf("Difference of Matrix A and B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            diff[i][j] = matrixA[i][j] - matrixB[i][j
            ];
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }

    // Inverse (only for 2x2 matrices)
    if (rows == 2 && cols == 2) {
        int det = matrixA[0][0] * matrixA[1][1] - matrixA[0][1] * matrixA[1][0];
        if (det != 0) {
            float inverse[2][2];
            inverse[0][0] = matrixA[1][1] / (float)
            det;
            inverse[0][1] = -matrixA[0][1] / (float) det;
            inverse[1][0] = -matrixA[1][0] / (float) det;
            inverse[1][1] = matrixA[0][0] / (float) det;    
            printf("Inverse of Matrix A:\n");
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    printf("%.2f ", inverse[i][j]);
                }
                printf("\n");

            }
        } else {
            printf("Matrix A is singular and cannot be inverted.\n");
        }
    } else {
        printf("Inverse calculation is only implemented for 2x2 matrices.\n");
        
    }
    // Magic Square (only for 3x3 matrices)
    if (rows == 3 && cols == 3) {
        int magicSquare[3][3] = {
            {8, 1, 6},

            {3, 5, 7},
            {4, 9, 2}
        };
        printf("Magic Square (3x3):\n");
        for (int i = 0; i < 3; i++) {          
            for (int j = 0; j < 3; j++) {
                printf("%d ", magicSquare[i][j]);
            }
            printf("\n");
        }



