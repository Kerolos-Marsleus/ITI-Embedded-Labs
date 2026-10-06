#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define min 0
#define max 100

int read_data();
int main(void) {
    srand(time(NULL));
    int number = rand();
    int triales = 0;
    number = (number % max) + 1;
    int input;
    int not_found = 1;
    do{
        input = read_data();
        triales++;
        if(number == input){
            printf("You are correct\n");
            printf("you have tried %d times\n",triales);
            not_found = 0;
        }else if (number > input){
            printf("it is higher than that\n");
        }else{
            printf("it is lower than that\n");
        }

    }while(not_found);
    
    return 0;
}

int read_data(){
    int data;
    while(1){
        printf("Please Enter a random number : ");
        if(scanf("%d",&data) != 1){
            printf("Invalid Input\n");
            while(getchar() != '\n');
            continue;

        }
        while(getchar() != '\n');
        if(data < min || data > max){
            printf("Error: Enter a number from %d to %d",min, max);
            continue;
        }
        return data;
    }
    
}