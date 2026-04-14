#include <stdio.h>

int main()
{
    int choice; 
        int digit; 
            int rev = 0;

                printf("Enter a number: ");
                    scanf("%d", &choice);

                        while (choice>0)
                            {
                                    digit = choice % 10;
                                            choice = (choice-digit) / 10;
                                                    rev = rev * 10 + digit;
                                                        }
                                                            printf("Reversed number: %d\n", rev);
                                                                return 0;
                                                    }