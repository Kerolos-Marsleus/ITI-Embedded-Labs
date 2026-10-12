#include <stdio.h>
#include <string.h>

#define STRING_SIZE 30
#define MAX_BOOKS_STORAGE 30

enum BookCategory   {FICTION, SCIENCE, HISTORY, POETRY, CATEGORY_COUNT};
enum BookStatus     {AVAILABLE, ISSUED, RETURN, NUMBER_OF_BOOK_STATUS};
enum Menu           {ADD_BOOKS = 1, SEARCH_BY_AUTHOR, CHANGE_STATUS, COUNT_BOOKS, EXIT};

struct Book{
    char title[STRING_SIZE];
    char author[STRING_SIZE];
    double price;
    enum BookCategory category;
    enum BookStatus  status;
};

void clear_input_buffer(void);
int read_int(void);
double read_double(void);
int read_sentence(char *str);
int read_in_range(int min, int max);
void print_menu();
int add_book(struct Book *storage, int* book_count);
void display_the_count_for_each_category(struct Book *storage, const int* book_count);
void search_by_title_or_author(struct Book *storage, const int* book_count); 
void change_status(struct Book *storage, const int* book_count);

int main(void) {
    static struct Book storage[MAX_BOOKS_STORAGE];
    int book_count = 0;
    int option;
    int status;
    do{
        print_menu();
        option = read_in_range(1, EXIT);
        switch (option)
        {
        case ADD_BOOKS:
            status = add_book(storage, &book_count);
            break;
        case SEARCH_BY_AUTHOR:
            search_by_title_or_author(storage,&book_count);
            break;
        case CHANGE_STATUS:
            change_status(storage, &book_count);
            break;
        case COUNT_BOOKS:
            display_the_count_for_each_category(storage, &book_count);
            break;
        default:
            break;
        }
    }while(option != EXIT);
    return 0;
}

void print_menu(){
    printf("Choose what you want.\n");
    printf("1. Add a new book\n");
    printf("2. Search by title or author\n");
    printf("3. Change status (e.g., issue/return)\n");
    printf("4. Count books in each category\n");
    printf("5.EXIT\n");
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

int add_book(struct Book *storage, int* book_count){
    if(*book_count < MAX_BOOKS_STORAGE){
        printf("Enter the title : ");
        int status = read_sentence(storage[*book_count].title);
        if (status == -1){
            printf("Invalid input\n");
            return -1;
        }
        printf("Enter the Author name : ");
        status = read_sentence(storage[*book_count].author);
        if (status == -1){
            printf("Invalid input\n");
            return -1;
        }
        printf("Enter the Author price : ");
        storage[*book_count].price = read_double();

        printf("Choose the Category \n");
        printf("1.FICTION\n2.SCIENCE\n3.HISTORY\n4.POETRY\n");
        storage[*book_count].category = read_in_range(1, CATEGORY_COUNT) - 1;
        printf("Choose the BookStatus \n");
        printf("1.AVAILABLE\n2.ISSUED\n3.RETURN\n");
        storage[*book_count].status = read_in_range(1, NUMBER_OF_BOOK_STATUS) - 1;
        
        (*book_count)++;
    }else{
        printf("There is no room in storage for a new book.\n");
        return -1;
    }
    return 0;
}

void display_the_count_for_each_category(struct Book *storage, const int* book_count){
    int category_count[CATEGORY_COUNT] = {0};
    for(int i = 0; i < *(book_count); i++){
        category_count[storage[i].category]++;
    }
    const char* category_name[CATEGORY_COUNT] = {"FICTION", "SCIENCE", "HISTORY", "POETRY"};
    for(int i = 0; i < CATEGORY_COUNT; i++){
        printf("there are %d of type %s\n",category_count[i], category_name[i]);
    }
}

void search_by_title_or_author(struct Book *storage, const int* book_count){
    printf("1.Search by title\n2.search by author\n");
    int res = read_in_range(1,2);
    int found = 0;
    if(res == 1){
        printf("Enter the name of the title : ");
        char str[STRING_SIZE];
        read_sentence(str);
        for(int i = 0; i < *(book_count); i++){
            if(strcmp(str, storage[i].title) == 0){
                found = 1;
                printf("%s\n",storage[i].author);
            }
        }
    }else if(res == 2){
         printf("Enter the name of the Author : ");
        char str[STRING_SIZE];
        read_sentence(str);
        for(int i = 0; i < *(book_count); i++){
            if(strcmp(str, storage[i].author) == 0){
                found = 1;
                printf("%s\n",storage[i].title);
            }
        }
    }
    if(found == 0){
        printf("Not found\n");
    }
}

void change_status(struct Book *storage, const int* book_count){
    printf("Enter the title : ");
    char str[STRING_SIZE];
    const char* status_name[NUMBER_OF_BOOK_STATUS] = {"AVAILABLE", "ISSUED", "RETURN"};
    read_sentence(str);
    int found = 0;
    for(int i = 0; i < *(book_count); i++){
        if(strcmp(str,storage[i].title) == 0){
            found = 1;
            printf("changing the status from %s to : \n",status_name[storage[i].status]);
            printf("1.AVAILABLE\n2.ISSUED\n3.RETURN\n");
            storage[i].status = read_in_range(1, NUMBER_OF_BOOK_STATUS) - 1;
            return ;
        }
    }
    if(found == 0){
        printf("Not found\n");
    }
}


