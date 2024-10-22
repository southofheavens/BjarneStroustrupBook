// for ex16
#include <cstdint>

template<typename P>
class ovector
{
private:
    P* elem;
    uint32_t sz;
    uint32_t space;
    
public:
    using size_type = uint32_t;
    using value_type = P;

    ovector() : sz{0}, elem{nullptr}, space{0} {}
    explicit ovector(uint32_t s) : sz{s}, elem{new P[s]}, space{s} {}
    ~ovector();
    
    class iterator;     // Тип - член класса: iterator
    // class const_iterator; 
    iterator begin() { return iterator(elem); }
    iterator end() { return iterator(elem+sz); }
    
    // Копирующие конструктор и присваивание:
    // ovector(pvector& arg);
    // ovector& operator=(pvector& arg);
        
    // Перемещающие конструктор и присваивание:
    // ovector(pvector&& arg);
    // ovector& operator=(pvector&& arg);
    
    decltype(*elem[0]) operator[](uint32_t n) {
        return *(elem[n]);
    }
    const decltype(*elem[0]) operator[](uint32_t n) const {
        return *(elem[n]); 
    }
    
    size_type size() const { return sz; }
    size_type capacity() const { return space; }
    void reserve(uint32_t newalloc);
    void resize(uint32_t newsize, P val = P());
    void push_back(const P& el);
};

// ------------------------------

template<typename P>
class ovector<P>::iterator
{
private:
    P* curr;   // Текущий узел
        
public:
    iterator(P* p) : curr{p} {}
        
    // Вперед:
    iterator& operator++() { curr++; return *this; }
        
    // Назад:
    iterator& operator--() { curr--; return *this; }
        
    // Разыменование (получение значения):
    decltype(*elem[0]) operator*() { return **curr; }
        
    bool operator==(const iterator& b) const
        { return curr == b.curr; }
    bool operator!=(const iterator& b) const
        { return curr != b.curr; }
};

// ------------------------------

template<typename P>
ovector<P>::~ovector()
{
    for (uint32_t i = 0; i < sz; ++i)
    {
        delete elem[i];
    }
    delete[] elem;
}

template<typename P>
void ovector<P>::reserve(uint32_t newalloc)
{
    if (newalloc <= space) {
        return;
    }
    P* p = new P[newalloc]; // Выделяем новую память
    // Копирование:
    for (int i = 0; i < sz; ++i) {
        p[i] = elem[i];
    }
    // Уничтожение:
    delete[] elem;
    elem = p;
    space = newalloc;
}

template<typename P>
void ovector<P>::resize(uint32_t newsize, P val)
{
    reserve(newsize);
    // Создаём:
    for (int i = sz; i < newsize; ++i) {
        elem[i] = val;
    }
    sz = newsize;
}

template<typename P>
void ovector<P>::push_back(const P& el)
{
    if (space == 0) {
        reserve(8);
    }
    else if (sz == space) {
        reserve(2*space);
    }
    elem[sz] = el;
    ++sz;
}
