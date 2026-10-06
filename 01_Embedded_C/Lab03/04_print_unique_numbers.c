#include <stdio.h>
#define MAX_ELEMENTS 100

int read_int(void);
int read_size(void);
void read_array(int *arr, int size);
void print_unique(const int *arr, int size);

int main(void) {
    printf("Enter the size of the array\n");
    int size = read_size();
    int arr[MAX_ELEMENTS];

    
    read_array(arr, size);
    
    print_unique(arr,size);
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

void print_unique(const int *arr, int size){
    int counter = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(arr[i] == arr[j] && i != j){
                break;
            }else if(j == size-1){
                printf(" %d \n", arr[i]);
                counter++;
            }
        }
    }
    if (counter==0){
        printf("No Unique Elements\n");
    }
}
