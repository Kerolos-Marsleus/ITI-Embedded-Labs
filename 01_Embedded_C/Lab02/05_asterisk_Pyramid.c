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
    int spaces = input - 1;
    int asterisk = 1;
    for(int row = 0; row < input; row++){
        // print spaces
        for(int column = 0; column < spaces; ++column){
            putchar(' ');
        }
        spaces--;
        // print asterisk
        for(int column = 0; column < asterisk; column++){
            putchar('*');
        }
        asterisk+=2;
        putchar('\n');
    }
    return 0;
}