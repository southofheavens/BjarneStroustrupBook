/*
 * Протестируйте функцию cat(). Почему в первой инструкции мы добавляем число 2? В функции cat() мы сделали
 * ошибку, связанную с производительностью и характерную для новичка. Найдите и устраните ее. Мы также "забыли"
 * прокомментировать код. Добавьте соответствующие комментарии, предполагая, что читатель знает стандартные
 * функции для работы с C-строками.
 * 
 * How to compile:
 * clang -std=c89 tryThis1.c 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* Cat(const char* id, const char* addr)
{
    uint16_t sz = strlen(id)+strlen(addr)+2;    // прибавляем двойку для символа @ и нулевого символа
    char* res = (char*)malloc(sz);              // выделяем память для строки с результатом
    strcpy(res,id);                             // копируем id в строку с результатом начиная с нулевого символа
    res[strlen(id)] = '@';                      // добавляем в строку с результатом символ '@'
    strcpy(res+strlen(id)+1,addr);              // копируем addr в оставшуюся часть строки
    res[sz-1] = 0;                              // добавляем нулевой символ для завершения C-строки
    return res;
}

int main(void)
{
    char* id = "Semyon";
    char* addr = "southofheavens";
    char* res = Cat(id,addr);
    printf("%s\n",res);
    free(res);
    return 0;
}
