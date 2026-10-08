#include <stdio.h>
#define MAX_ELEMENTS 100


int read_int(void);
int read_size(void);
void read_array(int *arr, int size);
void print_max_min(const int *arr, const int size);
int main(void) {
    printf("Enter the size of the array : ");
    int size = read_size();
    int arr[MAX_ELEMENTS];
    read_array(arr, size);
    print_max_min(arr, size);
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

void print_max_min(const int *arr, const int size){
    int max = arr[0];
    int min = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }else if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("The min number is %d, The max number is : %d\n", min, max);
}
