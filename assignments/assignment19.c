#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];         
    char designation[20];
    char gender[10];
    char date_of_joining[20];
    int salary;
};                      

// a) Total number of employees
void totalEmployees(int n) {
    printf("\nTotal employees: %d\n", n);
}

// b) Count of male and female employees
void countGender(struct Employee emp[], int n) {
    int male = 0, female = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(emp[i].gender, "Male") == 0)
            male++;
        else if (strcmp(emp[i].gender, "Female") == 0)
            female++;
    }
    printf("\nMale employees: %d\nFemale employees: %d\n", male, female);
}

// c) Employees with salary > 10000
void salaryAbove10k(struct Employee emp[], int n) {
    printf("\nEmployees with salary > 10000:\n");
    for (int i = 0; i < n; i++) {
        if (emp[i].salary > 10000)
            printf("  %s | Salary: %d\n", emp[i].name, emp[i].salary);
    }
}

// d) Employees with designation "Asset Manager"
void findAssetManager(struct Employee emp[], int n) {
    printf("\nAsset Managers:\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(emp[i].designation, "Asset Manager") == 0)
            printf("  %s\n", emp[i].name);
    }
}

int main() {
    printf("Enter how many employees: ");
    int n;
    scanf("%d", &n);

    struct Employee emp[n];

    for (int i = 0; i < n; i++) {   // FIX 3: int i declared
        printf("\n--- Employee %d ---\n", i + 1);

        printf("Name: ");
        scanf("%s", emp[i].name);           // no & for strings

        printf("Designation: ");
        scanf("%s", emp[i].designation);

        printf("Gender (Male/Female): ");
        scanf("%s", emp[i].gender);

        printf("Date of Joining: ");
        scanf("%s", emp[i].date_of_joining); // FIX 5: was missing

        printf("Salary: ");
        scanf("%d", &emp[i].salary);         // & needed for int
    }

    printf("\n--- All Employees ---\n");
    for (int j = 0; j < n; j++) {    // FIX 4: int j declared
        printf("%s | %s | %s | %s | %d\n",  // FIX 7: format specifiers added
               emp[j].name,
               emp[j].designation,
               emp[j].gender,
               emp[j].date_of_joining,
               emp[j].salary);               // FIX 8: emp[j] not emp[i]
    }

    // Call all 4 required functions
    totalEmployees(n);
    countGender(emp, n);
    salaryAbove10k(emp, n);
    findAssetManager(emp, n);

    return 0;
}