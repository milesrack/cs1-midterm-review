#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee{
    int id;
    char *first_name;
    char *last_name;
} Employee;

Employee *makeArray(char **firstNames, char **lastNames, int *IDs, int n);
void printArray(Employee *employees, int n);
void freeArray(Employee *employees, int n);

int main(){
    int IDs[] = {1, 2, 3};
    int n = sizeof(IDs)/sizeof(IDs[0]);
    char *firstNames[] = {"Tom", "Jack", "Joe"};
    char *lastNames[] = {"Smith", "Roberts", "Brown"};
    Employee *employees = makeArray(firstNames, lastNames, IDs, n);
    printArray(employees, n);
    freeArray(employees, n);
    return 0;
}

Employee *makeArray(char **firstNames, char **lastNames, int *IDs, int n){
    Employee *array = (Employee *) malloc(n * sizeof(Employee));
    for (int i = 0; i < n; i++){
        array[i].first_name = (char*) malloc(sizeof(char) * (strlen(firstNames[i]) + 1));
        array[i].last_name = (char*) malloc(sizeof(char) * (strlen(lastNames[i]) + 1));
        array[i].id = IDs[i];
        strcpy(array[i].first_name, firstNames[i]);
        strcpy(array[i].last_name, lastNames[i]);
    }
    return array;
}

void printArray(Employee *employees, int n){
    printf("%-5s%-20s%-20s\n", "ID", "First Name", "Last Name");
    for (int i = 0; i < n; i++){
        printf("%-5d%-20s%-20s\n", employees[i].id, employees[i].first_name, employees[i].last_name);
    }
}

void freeArray(Employee *employees, int n){
    for (int i = 0; i < n; i++){
        free(employees[i].first_name);
        free(employees[i].last_name);
    }
    free(employees);
    employees = NULL;
}