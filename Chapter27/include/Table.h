#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

struct KV
{
    char* key;
    int value;
};

struct Table
{
    uint16_t capacity;
    uint16_t size;
    struct KV* elements;
};

void Init(struct Table*);
void Clear(struct Table*);

struct KV* Insert(struct Table*, const char*, int);
struct KV* Find(struct Table*, const char*);
void Remove(struct Table*, const char*);
