/*
 * Завершите пример с интрузивным контейнером List из раздела 27.9 и протестируйте каждую его функцию.
 * 
 * P.S. Почему то в функции Erase во время удаления узла мы не освобождаем выделенную память с помощью 
 * функции free(). В List02 я добавил освобождение выделенной памяти в функцию Erase.
 * 
 * How to compile:
 * clang -std=c89 ex02.c src/List01.c
 */

#include <stdio.h>
#include <string.h>
#include "include/List01.h"

int main(void)
{
    int count = 0;
    struct List* names = Create();
    
    PushBack(names, (struct Link*)MakeName("Norah"));
    PushBack(names, (struct Link*)MakeName("Annemarie"));
    PushBack(names, (struct Link*)MakeName("Kris"));
    
    Erase(names, Advance(names->first, 1)); // Удаляем второй элемент
    struct Link* curr = names->first;
    for (; curr != 0; curr=curr->succ)
    {
        count++;
        printf("element %d: %s\n", count,
               ((struct Name*)curr)->n);
    }
    
    Destroy(names);
    
    return 0;
}
