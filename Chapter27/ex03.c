/*
 * Усовершенствуйте пример с интрузивным контейнером List из раздела 27.9 по своему усмотрению. Предусмотрите
 * перехват и обработку как можно большего количества ошибок. При этом можно изменить детали определений
 * структур, использовать макросы и т.д.
 *
 * Я решил добавить функции PopBack, PushFront, PopFront и Insert.
 * 
 * How to compile: 
 * clang -std=c89 ex03.c src/List02.c
 */

#include <stdio.h>
#include <string.h>
#include "include/List02.h"

int main(void)
{
    struct List* names = Create();
        
    Insert(names,names->head,(struct Link*)MakeName("Arthur"));
    PushBack(names, (struct Link*)MakeName("Norah"));
    PushBack(names, (struct Link*)MakeName("Annemarie"));
    PushBack(names, (struct Link*)MakeName("Kris"));
    PushFront(names, (struct Link*)MakeName("Semyon"));
    PushFront(names, (struct Link*)MakeName("Anton"));
    PushFront(names, (struct Link*)MakeName("David"));
    Insert(names,Advance(names->head,2),(struct Link*)MakeName("Vladimir"));
    Insert(names,names->tail,(struct Link*)MakeName("Sofia"));
    Insert(names,names->tail,(struct Link*)MakeName("Poly"));
    
    // David, Anton, Semyon, Vladimir, Arthur, Norah, Annemarie, Kris, Sofia, Poly
    
    Erase(names, Advance(names->head, 2));  // Удаляем третий элемент (с индексом 2, где
                                            // нумерация начинается с нуля)
    PopBack(names);                         // Удаляем последний элемент
    PopFront(names);                        // Удаляем первый элемент
    Erase(names, Advance(names->tail, -2)); // Удаляем третий с конца элемент
    
    struct Link* curr = names->head;
    int count = 1;
    for (; curr != 0; curr=curr->succ)
    {
        printf("element %d: %s\n", count,
               ((struct Name*)curr)->n);
        count++;
    }
    
    Destroy(names);
    
    return 0;
}
