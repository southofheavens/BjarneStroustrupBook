#include "../include/List01.h"

struct Name* MakeName(char* n)
{
    struct Name* p = (struct Name*)malloc(sizeof(struct Name));
    p->n = n;
    return p;
}

void Init(struct List* lst)
{
    assert(lst);
    lst->first = lst->last = 0;
}

struct List* Create(void)
{
    struct List* lst = (struct List*)malloc(sizeof(struct List));
    Init(lst);
    return lst;
}

void Clear(struct List* lst)
{
    assert(lst);
    {
        struct Link* curr = lst->first;
        while(curr)
        {
            struct Link* next = curr->succ;
            free(curr);
            curr = next;
        }
        lst->first = lst->last = 0;
    }
}

void Destroy(struct List* lst)
{
    assert(lst);
    Clear(lst);
    free(lst);
}

void PushBack(struct List* lst, struct Link* p)
{
    assert(lst);
    {
        struct Link* last = lst->last;
        if (last)
        {
            last->succ = p;
            p->prev = last;
        }
        else
        {
            lst->first = p;
            p->prev = 0;
        }
        lst->last = p;
        p->succ = 0;
    }
}

struct Link* Erase(struct List* lst, struct Link* p)
{
    assert(lst);
    if (p == 0) {
        return 0;
    }
    
    if (p == lst->first)
    {
        if (p->succ)
        {
            lst->first = p->succ;
            p->succ->prev = 0;
            return p->succ;
        }
        else
        {
            lst->first = lst->last = 0;
            return 0;
        }
    }
    else if (p == lst->last)
    {
        if (p->prev)
        {
            lst->last = p->prev;
            p->prev->succ = 0;
            return p->succ;
        }
        else
        {
            lst->first = lst->last = 0;
            return 0;
        }
    }
    else
    {
        p->succ->prev = p->prev;
        p->prev->succ = p->succ;
        return p->succ;
    }
}

struct Link* Advance(struct Link* p, int n)
{
    while (n != 0)
    {
        if (n < 0)
        {
            p=p->prev;
            n++;
        }
        else
        {
            p=p->succ;
            n--;
        }
    }
    return p;
}
