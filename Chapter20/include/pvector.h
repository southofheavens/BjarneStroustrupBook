// for ex15
#include <cstdint>

template<typename P>
class pvector
{
private:
    P* elem;
    uint32_t sz;
    uint32_t space;
    
public:
    using size_type = uint32_t;
    using value_type = P;

    pvector() : sz{0}, elem{nullptr}, space{0} {}
    explicit pvector(uint32_t s) : sz{s}, elem{new P[s]}, space{s} {}
    ~pvector();

    using iterator = P*;
    using const_iterator = const P*;
    iterator begin() { return elem; };
    const const_iterator cbegin() const { return elem; }
    iterator end() { return elem+sz; };
    const const_iterator cend() const { return elem+sz; }
    
    // Копирующие конструктор и присваивание:
    // pvector(pvector& arg);
    // pvector& operator=(pvector& arg);
        
    // Перемещающие конструктор и присваивание:
    // pvector(pvector&& arg);
    // pvector& operator=(pvector&& arg);
    
    P& operator[ ](uint32_t n) { return elem[n]; }
    const P& operator[ ](uint32_t n) const { return elem[n]; }
        
    size_type size() const { return sz; }
    size_type capacity() const { return space; }
    void reserve(uint32_t newalloc);
    void resize(uint32_t newsize, P val = P());
    void push_back(const P& el);
};

template<typename P>
pvector<P>::~pvector()
{
    for (uint32_t i = 0; i < sz; ++i)
    {
        delete elem[i];
    }
    delete[] elem;
} 

template<typename P>
void pvector<P>::reserve(uint32_t newalloc)
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
void pvector<P>::resize(uint32_t newsize, P val)
{
    reserve(newsize);
    // Создаём:
    for (int i = sz; i < newsize; ++i) {
        elem[i] = val;
    }
    sz = newsize;
}

template<typename P>
void pvector<P>::push_back(const P& el)
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
