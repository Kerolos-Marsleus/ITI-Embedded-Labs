#include <stdio.h>

int main(){
    int number;
    printf("Please enter the number\n");
    if(scanf("%d",&number)!= 1){
        printf("invalid input\n");
        return 1;
    }
    if(number <= 0){
        printf("the number must be positive\n");
        return 1;
    }
    if(number > 100){
        printf("no numbers found\n");
        return 0;
    }
    int increment = number;
    while(number <= 100){
        printf("%d  ",number);
        number += increment;
    }
    printf("\n");
    return 0;
}