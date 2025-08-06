/*Q.1 manage employee record( id , name, salary) using structure array with dynamic memory allocation
 1. sorting the employees by salary
 2. searching an employee by there id */

/*Q.2 bank acc management
 1. deposit
 2. withdraw
 3. balance enquiry */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void sortEmployees(struct Employee* emp, int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(emp[j].salary > emp[j+1].salary) {
                struct Employee temp = emp[j];
                emp[j] = emp[j+1];
                emp[j+1] = temp;
            }
        }
    }
}

int searchEmployee(struct Employee* emp, int size, int searchId) {
    for(int i = 0; i < size; i++) {
        if(emp[i].id == searchId) 
            return i;
    }
    return -1;
}

int main() {
    int size;
    printf("Enter number of employees: ");
    scanf("%d", &size);
    
    struct Employee* employees = (struct Employee*)malloc(size * sizeof(struct Employee));
    if(employees == NULL) {
        printf("Memory allocation failed!\n");
    }

    for(int i = 0; i < size; i++) {
        printf("\nEmployee %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf(" %[^\n]s", employees[i].name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    sortEmployees(employees, size);
    printf("\nEmployees sorted by salary:\n");
    for(int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }

    int searchId;
    printf("\nEnter ID to search: ");
    scanf("%d", &searchId);
    int index = searchEmployee(employees, size, searchId);
    if(index != -1) {
        printf("Found: ID: %d, Name: %s, Salary: %.2f\n", employees[index].id, employees[index].name, employees[index].salary);
    } else {
        printf("Employee not found!\n");
    }

    free(employees);
    return 0;
}