#ifndef MY_STRING_H
#define MY_STRING_H

#include <stddef.h>

size_t my_strlen(const char *sentence);
char* my_strcpy(char *dest, const char* src);
int my_strcmp(const char* lhs, const char* rhs);
char* my_strcat( char* dest, const char* src );
char* my_strncpy( char* restrict dest, const char* restrict src, size_t count );
char* my_strncat( char* restrict dest, const char* restrict src, size_t count );
int my_strncmp( const char* lhs, const char* rhs, size_t count );
char* my_strchr( const char* str, int ch );
char* my_strrchr( const char* str, int ch );
void* my_memset( void* dest, int ch, size_t count );
void* my_memcpy( void* restrict dest, const void* restrict src, size_t count );
int my_memcmp( const void* lhs, const void* rhs, size_t count );
void* my_memchr( const void* ptr, int ch, size_t count );
void* my_memmove( void* dest, const void* src, size_t count );
char* my_strstr( const char* str, const char* substr );
size_t my_strcspn( const char *dest, const char *src );

#endif