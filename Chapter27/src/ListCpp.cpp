#include "../include/ListCpp.h"

Name* MakeName(std::string n)
{
    Name* p = new Name(n);
    p->n = n;
    return p;
}

List::List()
{
    head = tail = nullptr;
}

List::~List()
{
    Link* curr = head;
    while(curr)
    {
        Link* next = curr->succ;
        delete curr;
        curr = next;
    }
}

void List::PushBack(Link* p)
{
    if (head == nullptr && tail == nullptr)
    {
        head = tail = p;
    }
    else
    {
        tail->succ = p;
        p->prev = tail;
        tail = p;
    }
}

Link* List::Erase(Link* p)
{
    if (p == head)
    {
        if (head->succ)
        {
            head = head->succ;
            delete head->prev;
            head->prev = nullptr;
        }
        else
        {
            delete head;
            head = tail = nullptr;
        }
        return head;
    }
    else if (p == tail)
    {
        if (tail->prev)
        {
            tail = tail->prev;
            delete tail->succ;
            tail->succ = nullptr;
        }
        else
        {
            delete tail;
            head = tail = nullptr;
        }
        return nullptr;
    }
    else
    {
        p->prev->succ = p->succ;
        p->succ->prev = p->prev;
        Link* nextEl = p->succ;
        delete p;
        return nextEl;
    }
}
