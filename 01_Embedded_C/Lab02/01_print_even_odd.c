#include <stdio.h>

int main(){
    //the user will give me two inputs and will specify if i will show him the odd or even numbers
    // handle the negative 
    // how they will choose between even or odd
    
    // another better approach for future me
    // I can convert the the even_or_odd var into an integer -'0'
    // and then check the last bit of the start the the number with & operation to see if it is odd or ever
    // what will i get from this (more optimized, less instruction cycles, fewer code to debug)
    // this is an AI tip
    int start, end;
    char even_or_odd;
    printf("Enter the start number\n");
    if(scanf("%d",&start) != 1){
        printf("Invalid Input\n");
        return 1;
    }
    printf("Enter the end number\n");
    if(scanf("%d",&end) != 1){
        printf("Invalid Input\n");
        return 1;
    }
    printf("Do you want to print the even or odd integers between them ?\n");
    printf("for even press 0\n");
    printf("for odd press 1\n");
    if(scanf(" %c",&even_or_odd) != 1){
        printf("Invalid Input\n");
        return 1;
    }
    if(even_or_odd != '0' && even_or_odd != '1'){
        printf("Invalid Input\n");
        return 1 ;
    }
    if(start > end){
        int temp = start;
        start = end;
        end = temp;
    }
    
    // printf("%d  , %d", start, end); // debug
    if(even_or_odd == '0' && start % 2){ // even
        start++;
    }else if(even_or_odd == '1' && start % 2 == 0){ // odd
        start++;
    }
    while(start <= end){
            printf("%d    ", start);
            start +=2;
    }

}