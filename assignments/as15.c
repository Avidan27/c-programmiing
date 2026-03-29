/*15 To generate pseudo random numbers.*/
#include <stdio.h>
#include <stdlib.h>  // rand, srand
#include <time.h>    // time

int main(void)
{
    int i, n;

    printf("How many random numbers do you want? ");
    scanf("%d", &n);

    /* Seed the pseudo-random number generator with current time */
    srand(time(NULL));   // different sequence each run [web:5][web:6]

    printf("Random numbers (0 to RAND_MAX):\n");
    for (i = 0; i < n; i++) {
        int r = rand();  // pseudo random integer in [0, RAND_MAX] [web:2][web:10]
        printf("%d\n", r);
    }

    return 0;
}