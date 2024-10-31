#include "../include/Table.h"

void Init(struct Table* tbl)
{
    assert(tbl);
    tbl->capacity = 8;
    tbl->size = 0;
    tbl->elements = (struct KV*)malloc(sizeof(struct KV)*tbl->capacity);
}

void Clear(struct Table* tbl)
{
    assert(tbl);
    uint16_t i = 0;
    for (; i < tbl->size; ++i)
    {
        free((tbl->elements[i]).key);
    }
    free(tbl->elements);
}

struct KV* Insert(struct Table* tbl, const char* key, int val)
{
    assert(tbl);
    if (tbl->size == tbl->capacity)
    {
        tbl->capacity *= 2;
        tbl->elements = (struct KV*)realloc(tbl->elements,
                                            sizeof(struct KV)*tbl->capacity);
    }
    tbl->elements[tbl->size].value = val;
    tbl->elements[tbl->size].key = (char*)malloc(strlen(key)+1);
    strcpy(tbl->elements[tbl->size].key,key);
    tbl->size++;
    return &tbl->elements[tbl->size - 1];
}

struct KV* Find(struct Table* tbl, const char* key)
{
    assert(tbl);
    uint16_t i = 0;
    for (; i < tbl->size; ++i)
    {
        if (strcmp(key,(tbl->elements[i]).key) == 0)
        {
            return &tbl->elements[i];
        }
    }
    return 0;
}

void Remove(struct Table* tbl, const char* key)
{
    assert(tbl);
    struct KV* f = Find(tbl,key);
    if (f == 0) {
        return;
    }
    else
    {
        uint16_t i = 0;
        for (; i < tbl->size; ++i)
        {
            if (strcmp(key,(tbl->elements[i]).key) == 0)
            {
                free((tbl->elements[i]).key);
                break;
            }
        }
                
        for (; i < tbl->size; ++i)
        {
            tbl->elements[i] = tbl->elements[i+1];
        }
        tbl->size--;
    }
}
