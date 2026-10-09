#include <stdio.h>
#define STRING_SIZE 100

int str_length(const char *str);

int main(void){
    char sentence[STRING_SIZE];
    printf("Enter your sentence : ");
    if(fgets(sentence, sizeof(sentence), stdin) == NULL){ // return null when the user type ctrl + z 
        printf("Invalid input\n");
        return 1;
    }
    int len = str_length(sentence);
    if(len == -1){
        printf("The input is too long\n");
        return 1;
    }
    printf("The length of the string is %i\n", len);
    return 0;
}

int str_length(const char *sentence){
    int index = 0;
    while(sentence[index] != '\n' && sentence[index] != '\0'){
        index++;
    }
    if(sentence[index] == '\0'){
        return -1;
    }
    return index;
}