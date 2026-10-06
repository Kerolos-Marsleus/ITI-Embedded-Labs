#include <stdio.h>

#define MAX_ELEMENTS 100

int read_int(void);
int read_size(void);
void read_array(int *arr, int size);
void print_array(const int *arr, int size);
void copy_array(const int * src, int *dest, int size);
int main(void) {
    printf("Enter the size of the first & second array : ");
    int size = read_size();
    int src[MAX_ELEMENTS];
    read_array(src, size);
    int dest[MAX_ELEMENTS];
    copy_array(src, dest, size);
    printf("The destination array is: \n");
    printf("*************************************************\n");
    print_array(dest,size);

    return 0;
}

int read_int(void){
    int data;
    while(1){
        int ret = scanf("%d", &data);
        while(getchar() != '\n');
        if(ret != 1){
            printf("Enter an Integer\n");
            continue;
        }
        return data;
    }   
}

int read_size(void){
    int data;
    while(1){
        data = read_int();
        if(data <= 0 || data > MAX_ELEMENTS){
            printf("Error: Enter a number between 1 and %d \n", MAX_ELEMENTS);
            continue;
        }
        return data;
    }
    
}

void read_array(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("Element %d : ",i+1);
        arr[i]= read_int();
    }
}

void print_array(const int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("Element %d : %d\n", i+1, arr[i]);
    }
}

void copy_array(const int * src, int *dest, int size){
    for(int i = 0; i < size; i++){
        dest[i] = src[i];
    }
}