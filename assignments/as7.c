/*Write a C program to accept student details and display their result using an array of structures.*/

#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks1, marks2, marks3;
    float total, percentage;
};

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // Input
    for(int i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i+1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);  // NOTE: no spaces allowed

        printf("Enter marks of 3 subjects: ");
        scanf("%f %f %f", &s[i].marks1, &s[i].marks2, &s[i].marks3);

        // Calculate
        s[i].total = s[i].marks1 + s[i].marks2 + s[i].marks3;
        s[i].percentage = s[i].total / 3.0;
    }

    // Output
    printf("\n--- Student Results ---\n");
    for(int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i+1);
        printf("Roll: %d\n", s[i].roll);
        printf("Name: %s\n", s[i].name);
        printf("Total: %.2f\n", s[i].total);
        printf("Percentage: %.2f\n", s[i].percentage);
    }

    return 0;
}