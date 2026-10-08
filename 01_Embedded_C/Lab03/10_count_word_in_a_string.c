#include <stdio.h>
#define STRING_SIZE 100
int count_words(const char *sentence);

int main(void) {
    char sentence[STRING_SIZE];
    printf("Enter your sentence : ");
    if(fgets(sentence, sizeof(sentence), stdin) == NULL){ // return null when the user type ctrl + z 
        printf("Invalid input\n");
        return 1;
    }
    int counter = count_words(sentence);
    printf("Number of words %i\n", counter);
    
    return 0;
}


int count_words(const char *sentence){
    int index = 0;
    int counter = 0;
    while(sentence[index] != '\n' && sentence[index] != '\0'){
        int entered_a_word = 0;
        while(sentence[index] == ' '){
            index++;
        }
        while(sentence[index] != ' ' && sentence[index] != '\n' && sentence[index] != '\0'){
            index++;
            entered_a_word = 1;
        }
        if(entered_a_word == 1){
            counter++;
        }
    }
    return counter;
}
