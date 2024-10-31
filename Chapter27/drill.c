/*
 * Задание
 * 
 * 1. Напишите программу "Hello World!" на языке C, скомпилируйте ее и выполните.
 * 2. Определите две переменные, хранящие строки "Hello" и "World!" соответственно; конкатенируйте их
 * с пробелом между ними и выведите в виде строки Hello World!.
 * 3. Определите функцию на языке C, получающую параметр p типа char* и параметр x типа int, и выведите
 * на печать их значения в следующем формате: p is "foo" and x is 7. Вызовите эту функцию для нескольких
 * пар аргументов
 *
 * How to compile:
 * clang -std=c89 drill.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void F(char* p, int x)
{
    printf("p is '%s' and x is %d\n",p,x);
}

int main(void)
{
    printf("%s\n", "Hello World!");
    
    // ---

    char* hello = "Hello";
    char* world = "World!";
    uint32_t sz = strlen(hello)+strlen(world)+2;
    char* helloWorld = (char*)malloc(sz);
    strcpy(helloWorld,hello);
    helloWorld[strlen(hello)] = ' ';
    strcpy(helloWorld+strlen(hello)+1,world);
    helloWorld[sz-1] = 0;
    printf("%s\n",helloWorld);

    // ---

    F("Hello",5);
    F("America",-5);

    return 0;
}
