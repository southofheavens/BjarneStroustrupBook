/*
 * Реализуйте варианты функций strlen(), strcmp() и strcpy().
 *
 * How to compile:
 * clang -std=c89 ex01.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint32_t Strlen(const char* str)
{
    uint32_t result = 0;
    while(*str)
    {
        result++;
        str++;
    }
    return result;
}

int32_t Strcmp(const char* first, const char* second)
{
    while(*first || *second)
    {
        if (*first == 0) {
            return -1;
        }
        else if (*second == 0) {
            return 1;
        }
        
        if (*first < *second) {
            return -1;
        }
        else if (*first > *second) {
            return 1;
        }
        first++;
        second++;
    }
    return 0;
}

char* Strcpy(char* where, const char* what)
{
    char* firstSymbol = where;
    while(*what)
    {
        *where = *what;
        what++;
        where++;
    }
    return firstSymbol;
}

int main(void)
{
    char* first = "april";
    char* second = "zoo";
    printf("%d\n",Strcmp(first,second));
    
    char* newWord = (char*)malloc(Strlen(first)+1);
    Strcpy(newWord,first);
    printf("%s\n",newWord);
        
    free(newWord);
    return 0;
}