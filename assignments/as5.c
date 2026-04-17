/*Write a program in C to perform basic operations such as addition, subtle point, inverse, magic square of two matrices.*/
#include <stdio.h>

int main() {
    int A[10][10], B[10][10], sum[10][10];
    int r, c, i, j, k;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter Matrix A:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &B[i][j]);

    // 1. Addition
    printf("\nAddition:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            sum[i][j] = A[i][j] + B[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    // 2. Saddle Point (Matrix A)
    int found = 0;
    for(i = 0; i < r; i++) {
        int min = A[i][0], col = 0;

        for(j = 1; j < c; j++) {
            if(A[i][j] < min) {
                min = A[i][j];
                col = j;
            }
        }

        int isSaddle = 1;
        for(k = 0; k < r; k++) {
            if(A[k][col] > min) {
                isSaddle = 0;
                break;
            }
        }

        if(isSaddle) {
            printf("\nSaddle Point: %d\n", min);
            found = 1;
        }
    }

    if(found == 0)
        printf("\nNo Saddle Point\n");

    // 3. Inverse (only 2x2)
    if(r == 2 && c == 2) {
        int det = A[0][0]*A[1][1] - A[0][1]*A[1][0];

        if(det == 0) {
            printf("\nInverse not possible\n");
        } else {
            printf("\nInverse:\n");
            printf("%f %f\n", (float)A[1][1]/det, (float)-A[0][1]/det);
            printf("%f %f\n", (float)-A[1][0]/det, (float)A[0][0]/det);
        }
    }

    // 4. Magic Square (only square matrix)
    if(r == c) {
        int sumRow = 0;

        for(j = 0; j < c; j++)
            sumRow += A[0][j];

        int magic = 1;

        // check rows
        for(i = 1; i < r; i++) {
            int s = 0;
            for(j = 0; j < c; j++)
                s += A[i][j];
            if(s != sumRow)
                magic = 0;
        }

        // check columns
        for(j = 0; j < c; j++) {
            int s = 0;
            for(i = 0; i < r; i++)
                s += A[i][j];
            if(s != sumRow)
                magic = 0;
        }

        // diagonals
        int d1 = 0, d2 = 0;
        for(i = 0; i < r; i++) {
            d1 += A[i][i];
            d2 += A[i][r-i-1];
        }

        if(d1 != sumRow || d2 != sumRow)
            magic = 0;

        if(magic)
            printf("\nMagic Square\n");
        else
            printf("\nNot Magic Square\n");
    }

    return 0;
}

