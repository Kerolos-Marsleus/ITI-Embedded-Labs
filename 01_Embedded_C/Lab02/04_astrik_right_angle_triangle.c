#include <stdio.h>

int main(void) {
    int input = 0;
    printf("Please enter the number of rows : ");
    if(scanf("%d",&input) != 1){
        printf("Invalid Input\n");
        return 1;
    }
    if(input < 0){
        printf("no negative input\n");
        return 1;
    }
    for(int i = 0; i<input; i++){
        for(int j = 0; j <= i; j++){
            putchar('*');
        }
        printf("\n");
    }
    return 0;
}