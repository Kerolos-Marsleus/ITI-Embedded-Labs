#include <stdio.h>
#define MAX_ELEMENTS 100

/*
it will count extra copies 
{1, 2, 2, 2, 3, 3, 3, 3, 4 , 4}
       |     |  |  |      | --> result is 7   
*/

int read_int(void);
int read_size(void);
void read_array(int *arr, int size);
void sort_array(int *arr, int size);
void swap(int *arr, int i, int j);
void reverse_array(int* arr, int size);
int count_duplicates(const int *arr, int size);

int main(void) {
    printf("Enter the size of the array\n");
    int size = read_size();
    int arr[MAX_ELEMENTS];
    read_array(arr, size);
    sort_array(arr, size);
    int count = count_duplicates(arr, size);
    printf("The number of duplicates is : %d\n", count);
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
            reverse_array(arr, size);
            return;
        }else if (arr[i] > arr[i+1]){
            break;
        }
    }
    int largest_index = 0;
    for(int i = 0; i < size - 1; i++){
        largest_index= i;
        for(int j = i+1; j<size; j++){
            if(arr[j] > arr[largest_index]){
                largest_index = j;
            }
        }
        if(i != largest_index){
            swap(arr, i, largest_index);
        }
    }
}
void reverse_array(int* arr, int size){
    for(int k = 0, l = size-1; k < l; k++, l--){
        swap(arr, k, l);
    }
}

int count_duplicates(const int *arr, int size){
    int count = 0;
    for(int i = 0; i < size-1; i++){
        if(arr[i] == arr[i+1]){
            count++;
        }
    }
    return count;
}
