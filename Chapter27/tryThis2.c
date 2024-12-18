/*
 * Является ли корректной реализация функции strcpy()? Объясните, почему.
 *
 * Нет, реализация является не совсем корректной потому, что она возвращает указатель p на конец слова,
 * а должна возвращать указатель на первый символ слова. А конструкция while выглядит уродливо.
 * Ниже приведён исправленный вариант.
 * Как работает данная функция: мы разыменовываем указатель *p и присваиваем ему значение *q, а затем
 * инкрементируем оба указателя и так до тех пор, пока мы не дойдем до нулевого символа строки q.
 * Затем возвращаем указатель на первый символ строки, в которую мы скопировали другую строку.
 *
 * Но, хоть эта реализация и работает, мне кажется, она является уязвимой для ошибок:
 * если strlen(p) < strlen(q), то данный код может выполнить запись за пределы выделенной памяти, что
 * приведёт к неопределенному поведению, но библиотечная функция strcpy работает точно так же и позволяет,
 * например, скопировать строку "grigoriy" в char* someString = (char*)malloc(sizeof(char*)*4).
 * 
 * How to compile:
 * clang -std=c89 tryThis2.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* Strcpy(char* p, const char* q)
{
    // Выглядит уродливо и возвращает некорректный результат
    /*
     * while (*p++ = *q++);
     * return p;
     */
    
    // Исправленный код
    char* startOfString = p;  
    while(*q) // Пока мы не дошли до конца строки (до нулевого символа)
    {
        *p = *q;
        p++;
        q++;
    }
    return startOfString;
}

int main(void)
{
    char* copyString = "antoshka";
    char* someString = (char*)malloc(strlen(copyString)+1);
    someString = Strcpy(someString,copyString);
    printf("%s\n",someString);
    free(someString);
    return 0;
}
