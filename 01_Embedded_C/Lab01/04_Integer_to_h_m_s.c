#include <stdio.h>

int main(){
    int input;
    printf("Please enter the time in seconds \n");
    if(scanf("%d",&input)!= 1){
        printf("invalid input\n");
        return 1;
    }
    if(input < 0){
        printf("no time in negative\n");
        return 1;
    }

    int hours, min, sec;
    sec = input % 60;
    input = (input - sec)/60;
    min = input % 60;
    hours = input / 60;
    printf("hours = %d\n", hours);
    printf("minutes = %d\n", min);
    printf("seconds = %d\n", sec);
    return 0;
}