// for ex13
#include <stdexcept>

template<typename Elem>
struct Link
{
    Link* prev; // Предыдущий узел
    Link* succ; // Следующий узел
    Elem val;   // Значение
    
    Link(const Elem& v = Elem{0}, Link* p = nullptr, Link* s = nullptr) :
    val{v}, prev{p}, succ{s} {}
};

template<typename Elem>
class list
{
private:
    Link<Elem>* first;
    
public:
    list();
    ~list();
    
    class iterator;     // Тип - член класса: iterator
    
    iterator begin();   // Итератор, указывающий на первый элемент
    iterator end();     // Итератор, указывающий на элемент,
                        // следующий за последним
    
    iterator insert(iterator p,     // Вставка v в список
                    const Elem& v); // после элемента, на который
                                    // указывает итератор p
    iterator erase(iterator p);     // Удаление из списка элемента,
                                    // на который указывает итератор p
    void push_back(const Elem& v);  // Вставка v в конец списка
    void push_front(const Elem& v); // Вставка v в начало списка
    void pop_front();               // Удаление первого элемента
    void pop_back();                // Удаление последнего элемента
    
    Elem& front();                  // Первый элемент
    Elem& back();                   // Последний элемент
    // ...
};

// ---------------------------------------------

template<typename Elem>
class list<Elem>::iterator
{
private:
    Link<Elem>* curr;   // Текущий узел
    
public:
    iterator(Link<Elem>* p) : curr{p} {}
    
    // Вперед:
    iterator& operator++();
    
    // Назад:
    iterator& operator--();
    
    // Разыменование (получение значения):
    Elem& operator*() { return curr->val; }
    
    bool operator==(const iterator& b) const
        { return curr == b.curr; }
    bool operator!=(const iterator& b) const
        { return curr != b.curr; }
};

template<typename Elem>
typename list<Elem>::iterator& list<Elem>::iterator::operator++()
{
    if (!(curr->succ))
    {
        throw std::runtime_error("Попытка переместить итератор на "
                                 "несуществующий элемент");
    }
    curr = curr->succ;
    return *this;
}

template<typename Elem>
typename list<Elem>::iterator& list<Elem>::iterator::operator--()
{
    if (!(curr->prev))
    {
        throw std::runtime_error("Попытка переместить итератор на "
                                 "несуществующий элемент");
    }
    curr = curr->prev;
    return *this;
}

// ---------------------------------------------

template<typename Elem>
list<Elem>::list()
{
    first = nullptr;
}

template<typename Elem>
list<Elem>::~list()
{
    Link<Elem>* elem = first;
    if (elem)
    {
        while (elem->succ)
        {
            elem = elem->succ;
            delete elem->prev;
        }
        delete elem;
    }
}

template<typename Elem>
typename list<Elem>::iterator list<Elem>::begin()
{
    return iterator(first);
}

template<typename Elem>
typename list<Elem>::iterator list<Elem>::end()
{
    return iterator(nullptr);
}

template<typename Elem>
typename list<Elem>::iterator list<Elem>::insert(iterator p, const Elem& v)
// Если для списка lst1 мы передадим в качестве аргумента функции insert
// возвращаемое значение функции end() для любого другого списка (например, lst2.end()),
// то функция корректно отработает и вставит в конец списка lst1 элемент, хотя
// так быть не должно, но, учитывая задание, это сделать невозможно потому, что
// различить lst1.end() и lst2.end() невозможно, т.к. эти функции просто возвращают
// nullptr
{
    Link<Elem>* newNode = new Link<Elem>(v);

    if (begin() == end())
    {
        first = newNode;
        return iterator(newNode);
    }
    
    Link<Elem>* elem = first;
    if (p == end())
    {
        while (elem->succ) {
            elem = elem->succ;
        }
        elem->succ = newNode;
        newNode->prev = elem;
        return iterator(newNode);
    }
    
    while (iterator(elem) != p)
    {
        if (!(elem->succ))
        {
            throw std::runtime_error("В качестве аргумента функции insert передан итератор, не имеющий "
                                     "отношения к списку, для которого была вызвана функция");
        }
        elem = elem->succ;
    }
    
    if (elem->succ) {
        elem->succ->prev = newNode;
    }
    newNode->succ = elem->succ;
    newNode->prev = elem;
    elem->succ = newNode;
    return iterator(newNode);
}

template<typename Elem>
typename list<Elem>::iterator list<Elem>::erase(iterator p)
{
    if (begin() == end()) {
        throw std::runtime_error("Вызов функции erase для пустого списка");
    }
    if (p == begin())
    {
        if (first->succ) {
            first = first->succ;
            delete first->prev;
            first->prev = nullptr;
        } else
        {
            delete first;
            first = nullptr;
        }
        return iterator(first);
    }
    if (p == end()) {
        throw std::runtime_error("Вызов функции erase с итератором на конец списка");
    }
    
    Link<Elem>* elem = first;
    while (iterator(elem) != p)
    {
        if (!(elem->succ))
        {
            throw std::runtime_error("В качестве аргумента функции erase передан итератор, не имеющий "
                                     "отношения к списку, для которого была вызвана функция");
        }
        elem = elem->succ;
    }
    
    elem->prev->succ = elem->succ;
    if (elem->succ) {
        elem->succ->prev = elem->prev;
        iterator it = iterator(elem);
        ++it;
        delete elem;
        return it;
    } else
    {
        elem->prev->succ = nullptr;
        delete elem;
        return iterator(nullptr);
    }
}

template<typename Elem>
void list<Elem>::push_back(const Elem& v)
{
    Link<Elem>* newNode = new Link<Elem>(v);
    if (first == nullptr)
    {
        first = newNode;
        return;
    }
    Link<Elem>* elem = first;
    while (elem->succ) {
        elem = elem->succ;
    }
    elem->succ = newNode;
    newNode->prev = elem;
}

template<typename Elem>
void list<Elem>::push_front(const Elem& v)
{
    Link<Elem>* newNode = new Link<Elem>(v);
    if (begin() == end())
    {
        first = newNode;
        return;
    }
    Link<Elem>* elem = first;
    elem->prev = newNode;
    newNode->succ = elem;
    first = newNode;
}

template<typename Elem>
void list<Elem>::pop_front()
{
    if (begin() == end()) {
        throw std::runtime_error("Вызов pop_front() для пустого объекта типа list");
    }
    Link<Elem>* elem = first->succ;
    delete first;
    first = elem;
    if (first && first->prev) {
        first->prev = nullptr;
    }
}

template<typename Elem>
void list<Elem>::pop_back()
{
    if (begin() == end()) {
        throw std::runtime_error("Вызов pop_back() для пустого объекта типа list");
    }
    Link<Elem>* elem = first;
    while (elem->succ) {
        elem = elem->succ;
    }
    if (elem == first) {
        first = nullptr;
    }
    else if (elem->prev) {
        elem->prev->succ = nullptr;
    }
    delete elem;
}

template<typename Elem>
Elem& list<Elem>::front()
{
    if (!(first)) {
        throw std::runtime_error("Вызов front() для пустого объекта типа list");
    }
    return first->val;
}

template<typename Elem>
Elem& list<Elem>::back()
{
    Link<Elem>* elem = first;
    if (elem == nullptr) {
        throw std::runtime_error("Вызов back() для пустого объекта типа list");
    }
    while (elem->succ) {
        elem = elem->succ;
    }
    return elem->val;
}
