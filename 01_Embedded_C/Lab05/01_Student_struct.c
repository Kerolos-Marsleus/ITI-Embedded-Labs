#include <stdio.h>

#define STUDENT_NAME_LENGTH 28
#define MAX_STUDENTS        50

struct Student
{
    char name[STUDENT_NAME_LENGTH];
    unsigned int age;
    double total_mark; // the size of the object of the struct will be 40 without padding
};


int read_int(void);
double read_double(void);
int read_size(void);
int read_sentence(char *str);
int read_struct(struct Student* students, int count);
void clear_input_buffer(void);
void display_students(const struct Student* students, const int numb_of_students);
double average_between_students(const struct Student* students, const int numb_of_students);
int index_of_highest(const struct Student* students, const int numb_of_students);
void top_3(const struct Student* students, const int numb_of_students, int *top_3_arr);


int main(void) {
    static struct Student  students[MAX_STUDENTS];
    printf("Enter the number of students : ");
    int numb_of_students = read_size();
    int status = read_struct(students,numb_of_students);
    if(status == -1)return 1;


    display_students(students,numb_of_students);

    double average = average_between_students(students, numb_of_students); // the division by zero is handeled by read_size()
    printf("The average is %.2lf\n", average);

    int index = index_of_highest(students, numb_of_students);
    printf("the highest score was %.2lf for %s\n",students[index].total_mark, students[index].name);
    
    int top_3_arr[3] = {-1, -1, -1};
    top_3(students, numb_of_students, top_3_arr);
    int i = 0;
    printf("The order based on total mark\n");
    while( i < 3 && top_3_arr[i] != -1 ){
        printf("%6.2lf %-27s\n",students[top_3_arr[i]].total_mark, students[top_3_arr[i]].name);
        i++;
    }
    
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
int read_size(void){
    int data;
    while(1){
        data = read_int();
        if(data <= 0 || data > MAX_STUDENTS){
            printf("Error: Enter a number between 1 and %d \n", MAX_STUDENTS);
            continue;
        }
        return data;
    } 
}
int read_sentence(char *str){
    if(fgets(str, STUDENT_NAME_LENGTH, stdin) == NULL){ // return null when the user type ctrl + z 
        return -1;
    }
    // flush the buffer if the input is greater than STUDENT_NAME_LENGTH
    for(int i = 0; i < STUDENT_NAME_LENGTH; i++){
        if(i + 1 == STUDENT_NAME_LENGTH){
            str[i] = '\0';
            clear_input_buffer();
        }else if(str[i] == '\n'){
            str[i] = '\0';
            break;
        }
    }
    return 0;
}
int read_struct(struct Student* students, int count){
    for(int i = 0; i < count; i++){
        printf("Student %i \n", i+1);
        printf("Enter the name of the student : ");
        int status = read_sentence(students[i].name);
        if (status == -1){
            printf("Invalid input\n");
            return -1;
        }
        printf("Enter the Age : ");
        students[i].age = read_int();
        printf("Enter the total marks : ");
        students[i].total_mark = read_double();
    }
    return 0;

}
void clear_input_buffer(void){
    int buf ;       // can't be char because on some compiler char is unsigned and EOF = -1 so it will never equal to each other
    while((buf = getchar())){
        if(buf == '\n' || buf == EOF){
            break;
        }
    }
}

void display_students(const struct Student* students, const int numb_of_students){
        printf("%-3s %-27s %-8s %-8s\n","#", "Name" ,"Age" ,"Marks");
    for(int i = 0; i < numb_of_students ; i++){
        printf("%-3d %-27s %-8u %6.2lf \n",i+1,students[i].name, students[i].age, students[i].total_mark);
       }
}

double average_between_students(const struct Student* students, const int numb_of_students){
    double sum = 0;
    for(int i = 0; i < numb_of_students; i++){
        sum += students[i].total_mark;
    }
    return sum / (double)numb_of_students;
}

int index_of_highest(const struct Student* students, const int numb_of_students){
    int index = 0;
    for(int i = 1; i < numb_of_students; i++){
        if(students[index].total_mark < students[i].total_mark){
            index = i;
        }
    }
    return index;
}

void top_3(const struct Student* students, const int numb_of_students, int *top_3_arr){
    for(int i = 0; i < numb_of_students; i++){
        if(top_3_arr[0] == -1 ||students[top_3_arr[0]].total_mark < students[i].total_mark){
            top_3_arr[2] = top_3_arr[1];
            top_3_arr[1] = top_3_arr[0];
            top_3_arr[0] = i;
        }else if(top_3_arr[1] == -1 || students[top_3_arr[1]].total_mark < students[i].total_mark){
            top_3_arr[2] = top_3_arr[1];
            top_3_arr[1] = i;
        }else if(top_3_arr[2] == -1 || students[top_3_arr[2]].total_mark < students[i].total_mark){
            top_3_arr[2] = i;
        }
    }
}
