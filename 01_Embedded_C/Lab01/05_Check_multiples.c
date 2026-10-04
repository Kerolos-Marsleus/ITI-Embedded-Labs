#include <stdio.h>

int main(){
    int first, second;
    printf("Enter the first number\n");
    if(scanf("%d", &first) != 1 ){
        printf("invalid input\n");
        return 1;
    }
    printf("Enter the second number\n");
    if(scanf("%d", &second) != 1){
        printf("invalid input\n");
        return 1;
    }
    if(first == 0 || second == 0){
        printf("zero is not allowed\n");
        return 1;
    }
    if((second % first) ==0 || (first % second) == 0 ){
        printf("they are multiples\n");
        return 0;
    }
    printf("they are not multiples\n");
    return 0;
}