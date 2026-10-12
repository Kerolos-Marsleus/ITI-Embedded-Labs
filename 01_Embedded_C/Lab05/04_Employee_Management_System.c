#include <stdio.h>
#include <string.h>

#define STRING_SIZE 30

enum Department {ENGINEERING, SALES, MARKETING, DEPARTMENT_COUNT};
enum Role {ENGINEER, ACCOUNTANT,MANAGER,ROLE_COUNT};
enum EmployeeType {FULL_TIME, PART_TIME, INTERN, EMPLOYEE_TYPE_COUNT};
union Salary_type{
    double hourly_rate;
    double monthly_Salary;
};

struct Employee{
    int id;
    char name[STRING_SIZE];
    union Salary_type pay_type;
    enum Department dep;
    enum Role role;
    enum EmployeeType type;
};

int main(void) {
    
    return 0;
}