#include<stdio.h>
#include<stdlib.h>
//define macros
#define LAST_NAME_LENGTH 64
#define FIRST_NAME_LENGTH 32

//define structs
typedef struct{
    char *last_name;
    char *first_name;
    unsigned long int id;
    unsigned short ssn;
}Employee;

typedef struct{
    Employee employ1;
    Employee employ2;
}EmployeePair;

//define function prototypes
void process_last_name(Employee *employee);
void process_first_name(Employee *employee);
void process_id_number(Employee *employee);
void process_ssn(Employee *employee);
void process_employee_details(Employee *employee);
void print_employee_details(Employee *employee);
void free_employee_allocation(Employee *employee);
void allocate_memory_for_employee(Employee *employee);

int main(int argc, char* argv[]){
    //define and allocate memory for structs
    Employee employee1, employee2;
    
    allocate_memory_for_employee(&employee1);
    allocate_memory_for_employee(&employee2);

    //register first employee
    printf("Let's begin the registration process:\n");
    process_employee_details(&employee1);
    print_employee_details(&employee1);
    

    free_employee_allocation(&employee1);
    free_employee_allocation(&employee2);
    return 0;
}

void process_last_name(Employee *employee){
    printf("Last name:");
    scanf("%s", employee->last_name);
}

void process_first_name(Employee *employee){
    printf("First name:");
    scanf("%s", employee->first_name);
}

void process_id_number(Employee *employee){
    unsigned long int temp;
    
    printf("ID number:");
    scanf("%lu", &temp);

    employee->id = temp;
}

void process_ssn(Employee *employee){
    short temp;
    
    printf("SSN number:");
    scanf("%hu", &temp);

    employee->ssn = temp;
}

void process_employee_details(Employee *employee){
    process_last_name(employee);
    process_first_name(employee);
    process_id_number(employee);
    process_ssn(employee);
}

void print_employee_details(Employee *employee){
    printf("STRUCT employee {\n");
    printf("\t Last name: %s\n", employee->last_name); 
    printf("\t First name: %s\n", employee->first_name);
    printf("\t ID number: %lu \n", employee->id); 
    printf("\t %hu \n", employee->ssn);
    printf("}\n");
}

void free_employee_allocation(Employee *employee){
    free(employee->first_name);
    free(employee->last_name);
}

void allocate_memory_for_employee(Employee *employee){
    employee->last_name= malloc(LAST_NAME_LENGTH * sizeof(char));

    if(employee->last_name == NULL){
        printf("Error! Could not allocate memory for employee last name!");
        return 1;
    }
    employee->first_name = malloc(FIRST_NAME_LENGTH * sizeof(char));

    if(employee->first_name == NULL){
        printf("Error! Could not allocate memory for employee first name!");
        return 1;
    }
    
}