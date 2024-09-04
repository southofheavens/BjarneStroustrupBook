/*
    Завершите программу из раздела 17.10.1, создающую "список богов".
*/

#include <iostream>
#include <string>

class Link
{
public:
    Link(const std::string& v): value{v} {}
    
    Link* Insert(Link* n);  // Вставляет n перед данным объектом
    Link* Add(Link* n);     // Вставляет n после данного объекта
    Link* Erase();          // Удаляет данный объект из списка
    Link* Find(const std::string& s);           // Поиск в списке
    const Link* Find(const std::string& s) const; // Поиск в
                                        // константом списке
    Link* Advance(int n) const;                 // Перемещение
                                    // на n позиций по списку
    Link* Next() const { return succ; }
    Link* Previous() const { return prev; }
    std::string GetValue() const { return value; }
    
private:
    std::string value;
    Link* prev; // Предыдущий элемент
    Link* succ; // Следующий элемент
};

Link* Link::Insert(Link* n) // Вставка n перед this; возврат n
{
    if (n == nullptr) { return this; }
    //if (this == nullptr) { return n; }
    n->succ = this;    // this следует за n
    if (prev) {
        prev->succ = n;
    }
    n->prev = prev;  // Предшественник this становится предшественником n
    prev = n;    // n становится предшественником this
    return n;
}

Link* Link::Add(Link* n) // Вставка n после this; возврат n
{
    if (n == nullptr) { return this; }
    //if (this == nullptr) { return n; }
    n->prev = this;    // n следует за this
    if (succ) {
        succ->prev = n;
    }
    n->succ = succ;  // Потомок this становится потомком n
    succ = n;    // n становится потомком this
    return n;
}

Link* Link::Erase() // Удаление this из списка;
{                    // возврат преемника this
    if (succ) { succ->prev = prev; }
    if (prev) { prev->succ = succ; }
    if (succ) { return succ; }
    else { return prev; }
}

Link* Link::Find(const std::string& s) // Поиск s в списке;
{                           // возврат nullptr, если не найден
    Link* p = this;
    while(p->prev) {    // Переходим в начало списка
        p = p->prev;
    }
    while(p)
    {
        if (p->value == s) { return p; }
        p = p->succ;
    }
    return nullptr;
}

const Link* Link::Find(const std::string& s) const // Поиск s в константом списке;
{                           // возврат nullptr, если не найден
    const Link* p = this;
    while(p->prev) {    // Переходим в начало списка
        p = p->prev;
    }
    while(p)
    {
        if (p->value == s) { return p; }
        p = p->succ;
    }
    return nullptr;
}

Link* Link::Advance(int n) const // Переход на n позиций в списке
// Возвращает nullptr, если это невозможно
// Положительное n - движение вперед; отрицательное - назад
{
    const Link* p = this;
    if (0 < n)
    {
        while(n--)
        {
            if (p->succ == nullptr) { return nullptr; }
            p = p->succ;
        }
    }
    else if (n < 0)
    {
        while(n++)
        {
            if (p->prev == nullptr) { return nullptr; }
            p = p->prev;
        }
    }
    return const_cast<Link*>(p);
}

void PrintAll(const Link* l)
{
    std::cout << "{ ";
    while(l->Previous()) {    // Переходим в начало списка
        l = l->Previous();
    }
    while(l)
    {
        std::cout << l->GetValue();
        if (l->Next()) { std::cout << ", "; }
        l = l->Next();
    }
    std::cout << " }";
}

int main()
{
    Link* norseGods = new Link{"Odin"};
    norseGods->Insert(new Link{"Freia"});
    norseGods->Add(new Link{"Thor"});
        
    PrintAll(norseGods);
    std::cout << '\n';
        
    if (norseGods->Find("Thor")) {
        std::cout << "Thor найден!\n";
    } else {
        std::cout << "Thor не найден!\n";
    }
        
    norseGods = norseGods->Advance(1);
    norseGods = norseGods->Erase();
        
    PrintAll(norseGods);
    std::cout << '\n';
        
    if (norseGods->Find("Thor")) {
        std::cout << "Thor найден!\n";
    } else {
        std::cout << "Thor не найден!\n";
    }
    
    norseGods = norseGods->Erase();
    PrintAll(norseGods);
    std::cout << '\n';
        
    return 0;
}
