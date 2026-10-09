#include <stdio.h>
#define STRING_SIZE 100


int read_sentence(char *str);
void copy_string(const char* src, char *dest);
int main(void) {
    char string1[STRING_SIZE];
    char string2[STRING_SIZE];
    printf("Enter the sentence you want to copy : ");
    int status = read_sentence(string1);
    if (status == -1){
        printf("Invalid input\n");
        return 1;
    }

    copy_string(string1, string2);
    printf("The copied string is : %s", string2);
    return 0;
}

int read_sentence(char *str){
    if(fgets(str, STRING_SIZE, stdin) == NULL){ // return null when the user type ctrl + z 
        return -1;
    }
    return 0;
}

void copy_string(const char* src, char *dest){
    int index = 0;
    while( src[index] != '\0'){
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';

}