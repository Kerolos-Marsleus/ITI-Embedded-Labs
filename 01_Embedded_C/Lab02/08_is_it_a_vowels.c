#include <stdio.h>

int main(void) {
    printf("Please enter one character : ");
    int first = getchar();
    while(first == '\n'){
        first = getchar();
    }
    int second = getchar();
    if(second != '\n'){
        printf("Error: you entered more than one character.\n");
        return 1;
    }
    if(!(first >= 'a' && first <= 'z' || first >= 'A' && first <= 'Z')){
        printf("Error: please enter a character from a ... z or A ... Z\n");
        return 1;
    }
    
    switch (first)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        printf("It is a vowel\n");
        break;
    
    default:
        printf("It is a consonant\n");
        break;
    }
    
    return 0;
}