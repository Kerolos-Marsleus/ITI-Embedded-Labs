#include <stdio.h>
#define STRING_SIZE 100

int read_sentence(char *str);
void swap_upper_lower_case(char* string);
int is_a_char(char character);
int main(void) {
    
    char string[STRING_SIZE];
    printf("Enter the sentence you want to copy : ");
    int status = read_sentence(string);
    if (status == -1){
        printf("Invalid input\n");
        return 1;
    }
    printf("Swapping ........\n");
    swap_upper_lower_case(string);
    fputs(string, stdout);


    return 0;
}

int read_sentence(char *str){
    if(fgets(str, STRING_SIZE, stdin) == NULL){ // return null when the user type ctrl + z 
        return -1;
    }
    return 0;
}

void swap_upper_lower_case(char* string){
    int index = 0;
    while(string[index] != '\n' && string[index] != '\0'){
        if(is_a_char(string[index])){
            string[index] ^= (1<<5);
        }
        index++;
    }
}

int is_a_char(char character){
    if((character >= 'a' && character <= 'z') || 
          (character >= 'A' && character <= 'Z')){
            return 1;
          }
    return 0;
}