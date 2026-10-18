#include <stdio.h>
#include "my_string.h"
#include <string.h>
#include <stddef.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

int main(void) {
    const char *cases[] = {"", "a", "hello", "zay el 3asal", "line\n"};
    size_t size = ARRAY_SIZE(cases);
    
    for(int i = 0; i < size; i++){
        if(strlen(cases[i]) == my_strlen(cases[i])){
            printf("Success\n");
        }else{
            printf("fail\n");
        }
    }
    int arr[3];

    
    return 0;
}