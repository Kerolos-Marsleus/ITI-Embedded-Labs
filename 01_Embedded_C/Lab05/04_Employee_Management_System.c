#include <stdio.h>
#include <string.h>

#define STRING_SIZE 30
#define MAX_EMPLOYEE_STORAGE 30

enum Department {ENGINEERING, SALES, MARKETING, DEPARTMENT_COUNT};
enum EmployeeType {FULL_TIME, PART_TIME, INTERN, EMPLOYEE_TYPE_COUNT};
enum Menu           {ADD_EMPLOYEE = 1, REMOVE_EMPLOYEE, FILTER_DEPARTMENT,FILTER_TYPE, CALC_PAYROLL,SEARCH_BY_ID, EXIT};
union Compensation{
    double hourly_rate;
    double monthly_Salary;
};

const char* Department_name[DEPARTMENT_COUNT] = {"ENGINEERING", "SALES", "MARKETING"};
const char* Employee_type_name[EMPLOYEE_TYPE_COUNT] = {"FULL_TIME", "PART_TIME", "INTERN"};


struct Employee{
    int id;
    char name[STRING_SIZE];
    union Compensation pay;
    enum Department dep;
    enum EmployeeType type;
};

void clear_input_buffer(void);
int read_int(void);
double read_double(void);
int read_sentence(char *str);
int read_in_range(int min, int max);
void print_menu(void);
int index_of_ID(const struct Employee* storage,  const int* employee_count, int id);
void search_employee_by_id(const struct Employee* storage,  const int* employee_count, int id);
int main(void) {
    static struct Employee storage[MAX_EMPLOYEE_STORAGE];
    int employee_count = 0;
    int option;
    do{
        print_menu();
        option = read_in_range(1, EXIT);
        switch (option)
        {
        case ADD_EMPLOYEE:
            
            break;
        case REMOVE_EMPLOYEE:
            
            break;
        case FILTER_DEPARTMENT:
            
            break;
        case FILTER_TYPE:
            
            break;
        case CALC_PAYROLL:
            
            break;
        case SEARCH_BY_ID:
            
            break;
        default:
            break;
        }
    }while(option != EXIT);
    return 0;
}


int read_int(void){
    int data;
    while(1){
        int ret = scanf("%d", &data);
        clear_input_buffer();
        if(ret != 1){
            printf("Enter an Integer\n");
            continue;
        }
        return data;
    }   
}
int read_in_range(int min, int max){
    int data;
    while(1){
        data = read_int();
        if(data < min || data > max){
            printf("Error: Enter a number between %d and %d \n", min, max);
            continue;
        }
        return data;
    } 
}
void clear_input_buffer(void){
    int buf ;       // can't be char because on some compiler char is unsigned and EOF = -1 so it will never equal to each other
    while((buf = getchar())){
        if(buf == '\n' || buf == EOF){
            break;
        }
    }
}
double read_double(void){
    double data;
    while(1){
        int ret = scanf("%lf", &data);
        clear_input_buffer();
        if(ret != 1){
            printf("Enter a number\n");
            continue;
        }
        return data;
    }   
}
int read_sentence(char *str){
    if(fgets(str, STRING_SIZE, stdin) == NULL){ // return null when the user type ctrl + z 
        return -1;
    }
    // flush the buffer if the input is greater than STRING_SIZE
    for(int i = 0; i < STRING_SIZE; i++){
        if(i + 1 == STRING_SIZE){
            str[i] = '\0';
            clear_input_buffer();
        }else if(str[i] == '\n'){
            str[i] = '\0';
            break;
        }
    }
    return 0;
}


void print_menu(void){
    printf("Choose what you want.\n");
    printf("1. Add a new Employee\n");
    printf("2. Remove an Employee\n");
    printf("3. Filter by Department\n");
    printf("4. Filter by Type\n");
    printf("5. Calculate total Payroll\n");
    printf("6. Search employee by ID\n");
    printf("7. EXIT\n");
}

int index_of_ID(const struct Employee* storage,  const int* employee_count, int id){
    for(int i = 0; i < *employee_count; i++){
        if(storage[i].id == id){
            return i;
        }
    }
    return -1;
}

void search_employee_by_id(const struct Employee* storage,  const int* employee_count, int id){
    int index = index_of_ID(storage, employee_count,id);
    if(index == -1){
        printf("There is no employee with this ID\n");
        return;
    }else{
        printf("Employee Name : %s\n",storage[index].name);
        printf("Employee Department : %s\n",Department_name[storage[index].dep]);
        printf("Employee Type : %s\n",Employee_type_name[storage[index].type]);
        if(storage[index].type == FULL_TIME){
            printf("Employee pay : %0.2lf/month\n",storage[index].pay.monthly_Salary);
        }else{
            printf("Employee pay : %0.2lf/hour\n",storage[index].pay.hourly_rate);
        }

    }
}

