/*
 * Напишите программу на языке C, которая является эквивалентом инструкций string s; cin>>s;. Иначе говоря,
 * определите операцию ввода, которая считывала бы произвольно длинную последовательность символов,
 * завершающуюся пробельным символом, в массив символов, завершающийся нулевым символом.
 *
 * How to compile:
 * clang -std=c89 ex13.c
 */

#define STRING char*
#define CIN(str) ReadString(&str)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void ReadString(char** str)
{
    uint16_t memory = 8;
    *str = (char*)malloc(memory);
    uint16_t index = 0;
    char c;
    while ((c = getchar()) != EOF)
    {
        (*str)[index] = c;
        index++;
        if (index == (memory - 2))
        {
            memory *= 2;
            *str = (char*)realloc(*str, memory);
        }
    }
    if (index > 0 && (*str)[index-1] == '\n') {
        (*str)[index-1] = 0;
    }
    else
    {
        (*str)[index] = 0;
    }
}

int main(void)
{
    STRING name;
    CIN(name);
    printf("%s\n", name);
    free(name);
    return 0;
}
