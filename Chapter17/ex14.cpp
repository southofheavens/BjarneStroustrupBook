/*
    Можно ли написать список богов из раздела 17.10.1 в виде односвязного списка; другими словами, можно
    ли удалить член prev из класса Link? По каким причинам мы могли бы это сделать? В каких ситуациях
    разумно использовать односвязные списки? Переделайте такой пример с использованием только односвязного
    списка.
*/

#include <iostream>
#include <string>

struct God
{
    God(const std::string& n, const std::string& m, const std::string& v,
        const std::string& w) : name{n}, mythology{m}, vehicle{v}, weapon{w} {}
    
    std::string name;
    std::string mythology;
    std::string vehicle;
    std::string weapon;
};

class Link
{
public:
    explicit Link(const God& a): attributes{a} {}
    
    Link* Insert(Link* n, unsigned int k);        // Вставляет n после k-го элемента
    Link* PushBack(Link* n);             // Вставляет n в конец списка
    Link* PushFront(Link* n);            // Вставляет n в начало списка
    Link* Find(const std::string& s);    // Поиск в списке
    Link* Erase(Link* object);           // Удаляет object из списка
    Link* Advance(unsigned int n);       // Перемещение на n позиций по списку
    Link* Next() const { return succ; }
    unsigned int Size() const;
    God GetAttributes() const { return attributes; }

private:
    God attributes;
    Link* succ; // Следующий элемент
};

Link* Link::Insert(Link* n, unsigned int k)
{
    if (k < 0) 
    {
        std::cout << "Параметр k должен быть больше нуля!\n";
        return this;
    }
    if (k == 0) {
        return PushFront(n);
    }
    if (this == nullptr) {
        return n;
    }
    
    Link* head = this;
    Link* current = this;
    for (int i = 0; i < k - 1; ++i)
    {
        if (current->succ == nullptr) 
        {
            current->succ = n;
            return head;
        }
        current = current->succ;
    }
    if (current->succ)
    {
        Link* succ = current->succ;
        current->succ = n;
        current->succ->succ = succ;
        return head;
    }
    current->succ = n;
    return head;
}

Link* Link::PushBack(Link* n)
{
    Link* head = this;
    Link* current = this;
    while(current->succ) {
        current = current->succ;
    }
    current->succ = n;
    return head;
}

Link* Link::PushFront(Link* n)
{
    if (this == nullptr) {
        return n;
    }
    n->succ = this;
    return n;
}

Link* Link::Find(const std::string& s)
{
    if (this == nullptr) {
        return nullptr;
    }
    
    Link* current = this;
    while (current)
    {
        if (current->attributes.name == s)
        {
            return current;
        }
        current = current->succ;
    }
    return current;
}

Link* Link::Erase(Link* object)
{
    if (object == nullptr || !this->Find(object->attributes.name))
    {
        std::cout << "Данного объекта нет в списке!\n";
        return this;
    }
    
    Link* head = this;
    Link* next = head->succ;
    if (head == object) 
    {
        delete head;
        return next;
    }
    
    Link* current = this;
    while(next)
    {
        if (next == object)
        {
            if (next->succ)
            {
                current->succ = next->succ;
                delete next;
                return head;
            }
            else
            {
                delete next;
                current->succ = nullptr;
                return head;
            }
        }
        current = current->succ;
        next = current->succ;
    }
    delete current;
    return head;
}

unsigned int Link::Size() const
{
    const Link* current = this;
    unsigned int size = 0;
    while (current)
    {
        size++;
        current = current->succ;
    }
    return size;
}

Link* Link::Advance(unsigned int n)
{
    Link* current = this;
    for (int i = 0; i < n; ++i)
    {
        current = current->succ;
        if (current == nullptr) {
            return current;
        }
    }
    return current;
}


int main()
{
    Link* head = new Link{God{"Зевс","","",""}};
    head = head->PushFront(new Link{God{"Шива","","",""}});
    head = head->PushBack(new Link{God{"Тор","","",""}});
    head = head->Insert(new Link{God{"Афина","","",""}},2);
    
    Link* someElem = head;
    for (int i = 0; i < head->Size(); i++)
    {
        std::cout << someElem->GetAttributes().name << '\n';
        someElem = someElem->Advance(1);
    }
    std::cout << "----\n";
    
    head = head->Erase(head->Find("Зевс"));
    head = head->Erase(head->Find("Тор"));
    head = head->Erase(head->Find("Шива"));
    head = head->Erase(head->Find("Вася"));
    
    std::cout << "----\n";
    
    someElem = head;
    for (int i = 0; i < head->Size(); ++i)
    {
        std::cout << someElem->GetAttributes().name << '\n';
        someElem = someElem->Advance(1);
    }
    std::cout << "----\n";
    
    head = head->PushFront(new Link{God{"Один","","",""}});
    head = head->PushFront(new Link{God{"Арес","","",""}});
    head = head->Insert(new Link{God{"Парвати","","",""}}, 2);
    head = head->PushBack(new Link{God{"Фрейя","","",""}});
    
    someElem = head;
    for (int i = 0; i < head->Size(); ++i)
    {
        std::cout << someElem->GetAttributes().name << '\n';
        someElem = someElem->Advance(1);
    }
    
    // Очистка ресурсов
    someElem = head;
    Link* nextElem = someElem->Next();
    while(nextElem)
    {
        head = head->Erase(someElem);
        someElem = nextElem;
        nextElem = nextElem->Next();
    }
    delete someElem;
    head = nullptr;
    std::cout << head->Size() << '\n';
    
    return 0;
}
