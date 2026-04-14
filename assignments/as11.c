#include <stdio.h>
#include <math.h>

int main(){
    printf("Input a number you want to calculate: ");
    int a;
    scanf("%d",&a);

    printf("Press 1 for sq root, 2 for square, 3 for cube,\n");
    printf("4 to check prime, 5 to calc factorial,\n");
    printf("6 to check its prime factors\n");

    int c;
    scanf("%d",&c);

    switch(c){

        case 1:
            printf("Square root is %.2lf\n", sqrt((double)a));
            break;

        case 2:
            printf("Square is %d\n", a*a);
            break;

        case 3:
            printf("Cube is %d\n", a*a*a);
            break;

        case 4: {
            if(a <= 1){
                printf("Number is NOT PRIME\n");
                break;
            }

            int isPrime = 1;
            for(int i = 2; i <= sqrt(a); i++){
                if(a % i == 0){
                    isPrime = 0;
                    break;
                }
            }

            if(isPrime)
                printf("Number is PRIME\n");
            else
                printf("Number is NOT PRIME\n");

            break;
        }

        case 5: {
            long long fact = 1;
            for(int i = 1; i <= a; i++){
                fact *= i;
            }
            printf("Factorial is %lld\n", fact);
            break;
        }

        case 6: {
            int temp = a;  // preserve original number
            printf("Prime factors of %d are:\n", a);

            for(int i = 2; i <= temp; i++){
                while(temp % i == 0){
                    printf("%d ", i);
                    temp /= i;
                }
            }
            break;
        }

        default:
            printf("Invalid choice\n");
    }

    return 0;
}