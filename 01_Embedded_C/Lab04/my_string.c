#include "my_string.h"
#include <stddef.h>


size_t my_strlen(const char *sentence){
    size_t index = 0;
    while(sentence[index] != '\0'){
        index++;
    }
    return index;
}

char* my_strcpy(char *dest, const char* src){
    size_t index = 0;
    while( src[index] != '\0'){
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';
    return dest;
}

int my_strcmp(const char* lhs, const char* rhs){
    size_t index = 0;
    while(( lhs[index] == rhs[index]) && (lhs[index] != '\0' || rhs[index] != '\0')){
        index++;
    }
    if((unsigned char)lhs[index] < (unsigned char)rhs[index]){
        return -1;
    }else if((unsigned char)lhs[index] > (unsigned char)rhs[index]){
        return 1;
    }
    return 0;
}

char* my_strcat( char* dest, const char* src ){
    size_t i = 0;
    while(dest[i] != '\0'){
        i++;
    }
    size_t j = 0;
    while(src[j] != '\0'){
        dest[i] = src[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char* my_strncpy( char* restrict dest, const char* restrict src, size_t count ){
    size_t i = 0;
    while(i < count && src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    while(i < count){
        dest[i] = '\0';
        i++;
    }
    return dest;
}

char* my_strncat( char* restrict dest, const char* restrict src, size_t count ){
    size_t i = 0;
    while(dest[i] !='\0'){
        i++;
    }
    size_t j = 0;
    while(j < count && src[j] != '\0'){
        dest[i] = src[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int my_strncmp( const char* lhs, const char* rhs, size_t count ){
    size_t index = 0;
    while((index < count) &&( lhs[index] == rhs[index]) && (lhs[index] != '\0')){
        index++;
    }
    if(index == count){return 0;}
    if((unsigned char)lhs[index] < (unsigned char)rhs[index]){
        return -1;
    }else if((unsigned char)lhs[index] > (unsigned char)rhs[index]){
        return 1;
    }
    return 0;
}

char* my_strchr( const char* str, int ch ){
    const char* curr = str;
    while(*curr != (char)ch && *curr != '\0'){
        curr++;
    }
    if((char)ch == *curr){
        return (char *)curr;
    }
    return NULL;
}

char* my_strrchr( const char* str, int ch ){
    const char *last = NULL;
    const char *ptr = str;
    while(*ptr != '\0'){
        if(*ptr == (char)ch){
            last = ptr;
        }
        ptr++;
    }
    if((char)ch == '\0'){
        return (char *)ptr;
    }else{
        return (char *)last;
    }
}

void* my_memset( void* dest, int ch, size_t count ){
    unsigned char *ptr = (unsigned char *)dest;
    for(size_t i =0; i <count; i++){
        ptr[i] = (unsigned char)ch;
    }
    return dest;
}

void* my_memcpy( void* restrict dest, const void* restrict src, size_t count ){
    const unsigned char *ptr_src = (const unsigned char *)src;
    unsigned char *ptr_dest = (unsigned char *)dest;
    for(size_t i = 0; i < count; i++){
        ptr_dest[i] = ptr_src[i];
    }
    return dest;
}

int my_memcmp( const void* lhs, const void* rhs, size_t count ){
    const unsigned char *ptr_lhs = (const unsigned char *)lhs;
    const unsigned char *ptr_rhs = (const unsigned char *)rhs;
    for(size_t i = 0; i < count; i++){
        if(ptr_lhs[i] < ptr_rhs[i]){
            return -1;
        }else if(ptr_lhs[i] > ptr_rhs[i]){
            return 1;
        }
    }
    return 0;
}

void* my_memchr( const void* ptr, int ch, size_t count ){
    const unsigned char *src = (const unsigned char *)ptr;
    for(size_t i = 0; i < count; i++){
        if(src[i] == (unsigned char)ch){
            return (void*)(src+i);
        }
    }
    return NULL;
}

void* my_memmove( void* dest, const void* src, size_t count ){
    const unsigned char *ptr_src = (const unsigned char *)src;
    unsigned char *ptr_dest = (unsigned char *)dest;
    if(ptr_dest < ptr_src){
        for(size_t i = 0; i < count; i++){
        ptr_dest[i] = ptr_src[i];
        }
    }else if(ptr_dest > ptr_src){
        for(size_t i = count; i >= 1; i--){
        ptr_dest[i-1] = ptr_src[i-1];
        }
    }
    return dest;
}

char* my_strstr( const char* str, const char* substr ){
    if(substr[0] == '\0'){
        return (char*)str;
    }
    size_t i = 0;
    while(str[i] != '\0'){
        size_t j = 0;
        while(str[i+j] == substr[j] && (substr[j] != '\0')){
            j++;
        }
        if(substr[j] == '\0'){
            return (char *)(str+i);
        }
        if(str[i+j] == '\0')return NULL;
        i++;
    }
    return NULL;
}

size_t my_strcspn( const char *dest, const char *src ){
    size_t i = 0;
    while((dest[i] != '\0') && my_strchr(src,dest[i]) == NULL){
        i++;
    }
    return i;
}

char* my_strtok( char* restrict str, const char* restrict delim ){
    static char* ptr;
    if(str != NULL){
        ptr = str;
    }
    if(ptr == NULL){
        return NULL;
    }
    while(*ptr != '\0' && my_strchr(delim,*ptr)){
        ptr++;
    }
    if(*ptr == NULL){
        return NULL;
    }
    char* start = ptr;
    ptr += my_strcspn(ptr, delim);
    if(*ptr != '\0'){
        *ptr = '\0';
        ptr++;
    }
    return start;
}




