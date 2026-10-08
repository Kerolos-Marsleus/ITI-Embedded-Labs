#include <stdio.h>
#define MAX_ELEMENTS 100

int read_int(void);
int read_size(void);
void read_array(int *arr, int size);
void sort_array(int *arr, int size);
void swap(int *arr, int i, int j);
void print_array(const int *arr, int size);

int main(void) {
    printf("Enter the size of the array : ");
    int size = read_size();
    int arr[MAX_ELEMENTS];
    read_array(arr, size);
    sort_array(arr, size);
    printf("sorting the array in ascending order : \n");
    printf("*************************************************\n");
    print_array(arr, size);
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

void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j] = temp;
}

void sort_array(int *arr, int size){
    for(int i = 0; i < size -1 ; i++){
        if(arr[i] <= arr[i+1] && i+2 == size){
            return;
        }else if (arr[i] > arr[i+1]){
            break;
        }
    }
    for(int i = 0; i < size - 1; i++){
        int smallest_index= i;
        for(int j = i+1; j<size; j++){
            if(arr[j] < arr[smallest_index]){
                smallest_index = j;
            }
        }
        if(i != smallest_index){
            swap(arr, i, smallest_index);
        }
    }
}

void print_array(const int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("Element %d : %d\n", i+1, arr[i]);
    }
}
