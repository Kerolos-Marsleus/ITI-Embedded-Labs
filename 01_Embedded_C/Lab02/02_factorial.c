#include <stdio.h>
#define MAX_FACTORIAL_INPUT 20

int main(){
    unsigned long long factorial = 1;
    int input;
    printf("Please enter the number (must be less than %d) : ",MAX_FACTORIAL_INPUT);
    if(scanf("%d",&input) != 1){
        printf("Invalid Input\n");
        return 1;
    }
    if(input > MAX_FACTORIAL_INPUT){
        printf("very large number\n");
        return 1;
    }
    if(input < 0){
        printf("no factorial for negative numbers\n");
        return 1;
    }
    while(input > 1){
        factorial *= input;
        input--;
    }
    printf("the factorial is : %llu\n", factorial);
    return 0;
}