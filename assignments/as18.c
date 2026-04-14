/*Write a C program that accepts a string from user and perform following string operations — i. Calculate length of string 
ii. String reversal iii. Equality check of two strings iv. Check palindrome v. 
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
  
  
  // String reversal
  char rev[100];
  printf("Reversed string: ");
  for (int i = len - 1; i >= 0; i--) {
    rev[len - 1 - i] = str[i];
  }
  rev[len] = '\0';
  printf("%s\n", rev);

  // Equality check of two strings
  char str2[100];
  printf("Enter another string: ");
  scanf("%s", str2);

  if (strcmp(str, str2) == 0) {
    printf("The strings are equal.\n");
  } else {
    printf("The strings are not equal.\n");
  }


  // Check palindrome
  int isPalindrome = 1;
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - 1 - i]) {
      isPalindrome = 0;
      break;



  }
  if (isPalindrome) {
    printf("The string is a palindrome.\n");
  } else {
    printf("The string is not a palindrome.\n");
  }
//Check substring.
  char substr[100];
  printf("Enter a substring to check: ");
  scanf("%s", substr);

  if (strstr(str, substr) != NULL) {
    printf("The substring is present in the string.\n");
  } else {
    printf("The substring is not present in the string.\n");
  }

  return 0;
}
}
