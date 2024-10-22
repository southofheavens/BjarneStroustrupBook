// for ex12
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
    Link<Elem>* last;   // Узел, находящийся за последним узлом
    
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
    last = new Link<Elem>();
    first = last;
}

template<typename Elem>
list<Elem>::~list()
{
    while (first != last)
    {
        first = first->succ;
        delete first->prev;
    }
    delete last;
}

template<typename Elem>
typename list<Elem>::iterator list<Elem>::begin()
{
    return iterator(first);
}

template<typename Elem>
typename list<Elem>::iterator list<Elem>::end()
{
    return iterator(last);
}

template<typename Elem>
typename list<Elem>::iterator list<Elem>::insert(iterator p, const Elem& v)
{
    Link<Elem>* newNode = new Link<Elem>(v);
    
    if (p == begin())                       // Такая конструкция здесь нужна для того,
    {                                       // чтобы проверить итератор, который нам
        if (begin() == end())               // передали. Если вместо if () { if() {} else {} }
        {                                   // сделать просто if (begin() == end()) {} и список,
            newNode->succ = last;           // для которого вызывается данная функция, будет пуст,
            last->prev = newNode;           // то в случае передачи в качестве аргумента функции
            newNode->prev = nullptr;        // итератора на другой список (lst.insert(lst2.end(),elem)),
            first = newNode;                // функция корректно отработает и вставит элемент в список
            return iterator(newNode);
        }
        else
        {
            newNode->succ = first->succ;
            newNode->prev = first;
            first->succ->prev = newNode;
            first->succ = newNode;
            return iterator(newNode);
        }
    }
    else if (p == end())
    {
        last->prev->succ = newNode;
        newNode->prev = last->prev;
        newNode->succ = last;
        last->prev = newNode;
        return iterator(newNode);
    }
    
    Link<Elem>* elem = first;
    while (iterator(elem) != p)
    {
        if (!(elem->succ))
        {
            throw std::runtime_error("В качестве аргумента функции insert передан итератор, не имеющий "
                                     "отношения к списку, для которого была вызвана функция");
        }
        elem = elem->succ;
    }
    
    newNode->succ = elem->succ;
    newNode->prev = elem;
    newNode->succ->prev = newNode;
    elem->succ = newNode;
    return iterator(newNode);
}

template<typename Elem>
typename list<Elem>::iterator list<Elem>::erase(iterator p)
{
    if (begin() == end()) {
        throw std::runtime_error("Вызов функции erase для пустого списка");
    }
    else if (p == begin())
    {
        first = first->succ;
        delete first->prev;
        first->prev = nullptr;
        return iterator(first);
    }
    else if (p == end()) {
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
    
    iterator it = iterator(elem);
    elem->prev->succ = elem->succ;
    elem->succ->prev = elem->prev;
    
    ++it;
    delete elem;
    return it;
}

template<typename Elem>
void list<Elem>::push_back(const Elem& v)
{
    Link<Elem>* newNode = new Link<Elem>(v);
    
    if (begin() == end())
    {
        first = newNode;
        first->succ = last;
        last->prev = first;
        return;
    }
    
    last->prev->succ = newNode;
    newNode->prev = last->prev;
    newNode->succ = last;
    last->prev = newNode;
}

template<typename Elem>
void list<Elem>::push_front(const Elem& v)
{
    Link<Elem>* newNode = new Link<Elem>(v);
    
    if (begin() == end())
    {
        first = newNode;
        first->succ = last;
        last->prev = first;
        return;
    }
    
    newNode->succ = first;
    first->prev = newNode;
    first = newNode;
}

template<typename Elem>
void list<Elem>::pop_front()
{
    if (begin() == end()) {
        throw std::runtime_error("Вызов pop_front() для пустого объекта типа list");
    }
    
    first = first->succ;
    delete first->prev;
    first->prev = nullptr;
}

template<typename Elem>
void list<Elem>::pop_back()
{
    if (begin() == end()) {
        throw std::runtime_error("Вызов pop_back() для пустого объекта типа list");
    }
    
    Link<Elem>* reallyLast = last->prev;
    if (reallyLast == first)
    {
        reallyLast->succ->prev = nullptr;
        delete reallyLast;
        first = last;
        return;
    }
    
    reallyLast->prev->succ = reallyLast->succ;
    reallyLast->succ->prev = reallyLast->prev;
    delete reallyLast;
}

template<typename Elem>
Elem& list<Elem>::front()
{
    if (begin() == end()) {
        throw std::runtime_error("Вызов функции front() для пустого объекта типа list");
    }
    return first->val;
}

template<typename Elem>
Elem& list<Elem>::back()
{
    if (begin() == end()) {
        throw std::runtime_error("Вызов функции back() для пустого объекта типа list");
    }
    return last->prev->val;
}
