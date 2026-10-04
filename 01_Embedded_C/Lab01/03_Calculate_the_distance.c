#include <stdio.h>
#include <math.h>


int main(){
    double x1,x2,y1,y2;
    printf("Enter the x-coordinate of the first point \n");
    if(scanf("%lf",&x1) != 1){
        printf("Invalid Input\n");
        return 1;
    }

    printf("Enter the y-coordinate of the first point \n");
    
    if(scanf("%lf",&y1) != 1){
        printf("Invalid Input\n");
        return 1;
    }

    printf("Enter the x-coordinate of the second point \n");
    
    if(scanf("%lf",&x2) != 1){
        printf("Invalid Input\n");
        return 1;
    }

    printf("Enter the y-coordinate of the second point \n");
    if(scanf("%lf",&y2) != 1){
        printf("Invalid Input\n");
        return 1;
    }
    double dx = x2-x1;
    double dy = y2-y1;
    double result = dx * dx + dy * dy;
    result = sqrt(result);
    printf("the distance is : %.2lf\n", result);

    return 0;
}