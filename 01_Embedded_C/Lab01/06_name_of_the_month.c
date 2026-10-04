#include <stdio.h>

int main(){
    int number;
    printf("Enter a number from 1 to 12\n");
    if(scanf("%d",&number) != 1){
        printf("Invalid input\n");
        return 1;
    }
    if(number < 1 || number > 12){
        printf("Error: Out of range\n");
        return 1;
    }
    switch (number)
    {
    case 1:
        printf("January\n");
        break;
    case 2:
        printf("February\n");
        break;
    case 3:
        printf("March\n");
        break;
    case 4:
        printf("April\n");
        break;
    case 5:
        printf("May\n");
        break;
    case 6:
        printf("June\n");
        break;
    case 7:
        printf("July\n");
        break;
    case 8:
        printf("August\n");
        break;
    case 9:
        printf("September\n");
        break;
    case 10:
        printf("October\n");
        break;
    case 11:
        printf("November\n");
        break;
    case 12:
        printf("December\n");
        break;
    default:
        printf("Error\n");
        return 1;
    }
    return 0;
}