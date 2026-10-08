#include <stdio.h>
#define MAX_ELEMENTS 100


int read_int(void);
int read_size(void);
void read_array(int *arr, int size);
void print_frequency(const int *arr, int size);

int main(void) {
    printf("Enter the size of the array : ");
    int size = read_size();
    int arr[MAX_ELEMENTS];
    read_array(arr, size);
    print_frequency(arr, size);
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

void print_frequency(const int *arr, int size){
    for(int i = 0; i < size; i++){
        int counter = 0;
        int is_seen = 0;
        for(int j = 0; j < size; j++){
            if(j < i && arr[i] == arr[j]){
                is_seen = 1;
                break;
            }else if(arr[i] == arr[j] && i != j){
                counter++;
            }
        }
        if(!is_seen){
            printf("%d occurs %d times.\n", arr[i], counter + 1);
        }
    }
}