#include <stdio.h>
#include <limits.h>
int read_int(void);
void print_decimal_in_binary(int number,int number_of_bits);
int main(void) {
    printf("Enter the decimal number you want to convert to binary : ");
    int num = read_int();
    int number_of_bits = sizeof(int) * CHAR_BIT;
    printf("binary : ");

    print_decimal_in_binary(num, number_of_bits);
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

void print_decimal_in_binary(int number,int number_of_bits){
    if(number == 0){
        printf("0");
        return;
    }
    int digit = number_of_bits -1;
    for(; digit > 0; digit--){
        if((number >> digit) == 0){
            continue;
        }else{
            break;
        }
    }
    while(digit >= 0){
        printf("%d",(number >> digit) & 0x1);
        digit--;
    }
}
