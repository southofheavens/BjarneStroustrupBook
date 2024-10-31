/*
 * Реализуйте таблицу поиска (C-строка,int) с операциями find(struct table*, const char*), insert(struct table*,
 * const char*, int) и remove(struct table*, const char*). Эту таблицу можно представить в виде массива структур
 * или пары массивов(с элементами const char*[] и int*); выбор за вами. Выберите типы возвращаемых значений
 * для ваших функций. Документируйте ваши проектные решения.
 * 
 * How to compile:
 * clang -std=c89 ex12.c src/Table.c
 */

#include <stdio.h>
#include "include/Table.h"

int main(void)
{
    struct Table myTable;
    Init(&myTable);
    Insert(&myTable, "Hello", 15);
    Insert(&myTable, "Obama", 25);
    Insert(&myTable, "America", 65);
    Remove(&myTable, "Obama");
    Insert(&myTable, "Trump", 1000);

    if (Find(&myTable, "Obama")) {
        printf("Обама найден!\n");
    }
    else {
        printf("Обама не найден!\n");
    }

    if (Find(&myTable, "America")) {
        printf("Америка найдена!\n");
    }
    else {
        printf("Америка не найдена!\n");
    }

    uint32_t i = 0;
    for (; i < myTable.size; ++i)
    {
        printf("%s-%d\n",*&myTable.elements[i].key,*&myTable.elements[i].value);
    }
    
    Clear(&myTable);
    
    return 0;
}

