#include <stdio.h>
int is_leap(int year);
int main(void) {
    int year = 0;
    printf("Please enter the year : ");
    if(scanf("%d",&year) != 1){
        printf("Invalid Input\n");
        return 1;
    }
    if(is_leap(year)){
        printf("%d is a leap year\n",year);
    }else{
        printf("%d is NOT a leap year\n",year);
    }
    return 0;
}
int is_leap(int year){
    return ((year % 4 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0) );
}