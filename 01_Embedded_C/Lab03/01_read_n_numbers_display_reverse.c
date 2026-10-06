#include <stdio.h>
#define MAX_ELEMENTS 100
int read_int(void);
int read_size(void);
void read_array(int *arr, int size);
void print_reverse(const int *arr,const int size);
int main(void) {
    int size = read_size();
    int arr[MAX_ELEMENTS];
    read_array(arr, size);
    print_reverse(arr, size);

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
        printf("Please Enter the number of Elements : ");
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

void print_reverse(const int *arr, const int size){
    printf("the order in reverse is : \n");
    for(int i = size-1; i>=0; i--){
        printf("Element %d : %d \n",size - i,arr[i]);
    }
}