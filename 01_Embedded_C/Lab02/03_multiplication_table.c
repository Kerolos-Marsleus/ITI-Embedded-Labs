#include <stdio.h>
#define TABLE_SIZE 10
int main(){
    int input;
    printf("Please enter a positive number : ");
    if(scanf("%d",&input) != 1){
        printf("Invalid Input\n");
        return 1;
    }
    if(input <= 0){
        printf("the number must be positive\n");
        return 1;
    }
    unsigned long long result = 0;
    for(int i = 1; i <=TABLE_SIZE; i++){
        result += input;
        printf("%d x %d = %llu \n", input, i, result);
    }


    return 0;
}