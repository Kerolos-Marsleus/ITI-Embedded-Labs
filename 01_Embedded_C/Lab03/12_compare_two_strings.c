#include <stdio.h>
#define STRING_SIZE 100


int read_sentence(char *str);
int compare_strings(const char* str1, const char* str2); // return -1 0 1 
// -1 if str1 before str2
// 0 if identical
// 1 if str1 after str2

int main(void) {
    char string1[STRING_SIZE];
    char string2[STRING_SIZE];

    printf("Enter the first string : ");
    int failed = read_sentence(string1);
    if (failed == -1){
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter the second string : ");
    failed = read_sentence(string2);
    if (failed == -1){
        printf("Invalid input\n");
        return 1;
    }

    int ret = compare_strings(string1, string2);
    if (ret == 0){
        printf("The two sentences are identical\n");
    }else if(ret == -1){
        printf("Str1 comes before str2\n");
    }else{
        printf("Str1 comes after str2\n");
    }


    return 0;
}
int read_sentence(char *str){
    if(fgets(str, STRING_SIZE, stdin) == NULL){ // return null when the user type ctrl + z 
        return -1;
    }
    return 0;
}
int compare_strings(const char* str1, const char* str2){
    int index = 0;
    while((str1[index] == str2[index]) && (str1[index] != '\0' || str2[index] != '\0')){
        index++;
    }
    if(str1[index] < str2[index]){
        return -1;
    }else if(str1[index] > str2[index]){
        return 1;
    }
    return 0;
}