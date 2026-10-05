#include <stdio.h>

int check_prime(int number);
int main(void) {
    int start = 0;
    int end = 0;
    printf("Please enter the first number : ");
    if(scanf("%d",&start) != 1){
        printf("Invalid Input\n");
        return 1;
    }
    printf("Please enter the last number : ");
    if(scanf("%d",&end) != 1){
        printf("Invalid Input\n");
        return 1;
    }
    if(start > end){
        int temp = start;
        start = end;
        end = temp;
    }
    if(start < 2 ){
        start = 2;
    }
    printf("prime numbers between them are : \n");
    while(start <= end){
        if (start == 2 && end >= 2){
            printf("%d\n", start);
        }
        if((start & 1) && (check_prime(start))){
            printf("%d\n", start);
        }
        start++;
    }
    return 0; 
}
int check_prime(int number){
    if(number < 2){
        return 0;
    }
    for(int i = 2; i * i <= number ; i++){
        if(number % i == 0){
            return 0;
        }
    }
    return 1;
}