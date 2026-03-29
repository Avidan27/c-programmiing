/*Write a C program that accepts a string from user and perform following string operations — i. Calculate length of string 
ii. String reversal iii. Equality check of two strings iv. Check palindrome v. Check substring.
*/
#include <string.h>
#include <stdio.h>
int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);  

    printf("%s",str);
  printf("Length of the string: %lu \n", strlen(str));
  int len=strlen(str);
  printf("length is %d", len);

  
}
