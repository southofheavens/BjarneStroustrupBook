/*
    Модифицируйте класс Link из раздела 17.10.1, чтобы он хранил значение struct God. Этот тип
    должен иметь члены типа string: имя, мифология, транспортное средство и оружие. Например,
    God{"Зевс", "Греция", "", "Молния"} или God{"Один", "Норвегия", "Восьминогий летающий конь
    Слейпнер", "Копье Гунгнир"}. Напишите функцию print_all(), построчно выводящую имена богов
    и их атрибуты. Добавьте функцию-член add_ordered(), размещающую новый элемент, создаваемый
    с помощью оператора new, в правильной лексикографической позиции. Используя объекты Link
    со значениями типа God, составьте список богов из трех мифологий; затем переместите
    элементы (богов) из этого списка в три лексикографически упорядоченных списка - по одному
    для каждой мифологии.
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
    Link(const God& a): attributes{a} {}
    
    Link* Insert(Link* n);  // Вставляет n перед данным объектом
    Link* Add(Link* n);     // Вставляет n после данного объекта
    Link* AddOrdered(Link* n);
    Link* Erase();          // Удаляет данный объект из списка
    Link* Find(const std::string& s);           // Поиск в списке
    const Link* Find(const std::string& s) const; // Поиск в
                                        // константом списке
    Link* Advance(int n) const;                 // Перемещение
                                    // на n позиций по списку
    Link* Next() const { return succ; }
    Link* Previous() const { return prev; }
    God GetAttributes() const { return attributes; }
    
private:
    God attributes;
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

Link* Link::AddOrdered(Link* n)
{
    Link* t = this;
    while(true)
    {
        if (n->GetAttributes().name <= t->GetAttributes().name)
        {
            if (t->Previous()) 
            {
                if (n->GetAttributes().name >= t->Previous()->GetAttributes().name)
                {
                    t = t->Insert(n);
                    return t;
                }
                t = t->Previous();
            }
            else
            {
                t->Insert(n);
                return t;
            }
        }
        else
        {
            if (t->Next()) 
            {
                if (n->GetAttributes().name <= t->Next()->GetAttributes().name)
                {
                    t = t->Add(n);
                    return t;
                }
                t = t->Next();
            }
            else
            {
                t->Add(n);
                return t;
            }
        }
    }
}

Link* Link::Erase() // Удаление this из списка;
{                    // возврат преемника this
    if (succ) { succ->prev = prev; }
    if (prev) { prev->succ = succ; }
    if (succ) 
    {
        Link* s = succ;
        delete this;
        return s;
    }
    else 
    {
        Link* p = prev;
        delete this;
        return p;
    }
}

Link* Link::Find(const std::string& s) // Поиск s в списке;
{                           // возврат nullptr, если не найден
    Link* p = this;
    while(p->prev) {    // Переходим в начало списка
        p = p->prev;
    }
    while(p)
    {
        if (p->GetAttributes().name == s) { return p; }
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
        if (p->GetAttributes().name == s) { return p; }
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
    while(l->Previous()) {    // Переходим в начало списка
        l = l->Previous();
    }
    while(l)
    {
        std::cout << "{ ";
        std::cout << l->GetAttributes().name << ", " << l->GetAttributes().mythology;
        std::cout << ", " << l->GetAttributes().vehicle << ", " << l->GetAttributes().weapon;
        std::cout << " }\n";
        l = l->Next();
    }
}

int main()
{
    Link* gods = new Link{God{"Зевс","Греция","Небесная колесница","Молния"}};
    gods = gods->Add(new Link{God{"Парвати","Индия","Тигр","Дузи (лопата)"}});
    gods = gods->Add(new Link{God{"Тор","Норвегия","Корабль 'Нагльфар'","Мьёлнир"}});
    gods = gods->Add(new Link{God{"Афина","Греция","Птица","Щит и копье"}});
    gods = gods->Add(new Link{God{"Один","Норвегия","Конь Слейпнир","Копье Гунгнир"}});
    gods = gods->Add(new Link{God{"Рама","Индия","Летающая колесница","Лук и стрелы"}});
    gods = gods->Add(new Link{God{"Фрейя","Норвегия","Кадриль из котов","Валькирийский меч"}});
    gods = gods->Add(new Link{God{"Шива","Индия","Накшатра (птица)","Тризубец"}});
    gods = gods->Add(new Link{God{"Арес","Греция","Конь","Меч"}});

    PrintAll(gods);
    std::cout << '\n';
    
    Link* greekGods = nullptr;
    Link* norseGods = nullptr;
    Link* indianGods = nullptr;
    
    while(gods->Previous()) // Переходим в начало списка
    {
        gods = gods->Previous();
    }
    while(gods)
    {
        if (gods->GetAttributes().mythology == "Греция")
        {
            if (!greekGods) {
                greekGods = new Link{gods->GetAttributes()};
            } else {
                greekGods = greekGods->AddOrdered(new Link{gods->GetAttributes()});
            }
        }
        else if (gods->GetAttributes().mythology == "Норвегия")
        {
            if (!norseGods) {
                norseGods = new Link{gods->GetAttributes()};;
            } else {
                norseGods = norseGods->AddOrdered(new Link{gods->GetAttributes()});
            }
        }
        else
        {
            if (!indianGods) {
                indianGods = new Link{gods->GetAttributes()};;
            } else {
                indianGods = indianGods->AddOrdered(new Link{gods->GetAttributes()});
            }
        }
        gods = gods->Erase();
    }
    
    PrintAll(greekGods);
    std::cout << '\n';
    PrintAll(norseGods);
    std::cout << '\n';
    PrintAll(indianGods);
    std::cout << '\n';
    
    // Возврат ресурсов
    while(greekGods->Previous()) {
        greekGods = greekGods->Previous();
    }
    while(greekGods) {
        greekGods = greekGods->Erase();
    }
    while(norseGods->Previous()) {
        norseGods = norseGods->Previous();
    }
    while(norseGods) {
        norseGods = norseGods->Erase();
    }
    while(indianGods->Previous()) {
        indianGods = indianGods->Previous();
    }
    while(indianGods) {
        indianGods = indianGods->Erase();
    }
        
    return 0;
}
