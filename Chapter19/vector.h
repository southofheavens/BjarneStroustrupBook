// for ex08 and 09

#include <initializer_list>
#include <new>
#include <iostream>

// for ex08
template<typename T>
class allocator
{
public:
    // Выделение памяти для n объектов типа T
    T* allocate(int n) { return (T*)malloc(sizeof(T)*n); }
    
    // Вообще, в книге функция deallocate представлена следующим образом
    //
    // Освобождение памяти, занятой n объектами типа T с адреса p
    // void deallocate(T* p, int n);
    //
    // Мне кажется, что это то ли опечатка, то ли что-то в этом роде
    // Потому, что я без понятия, как освободить память, занятую n объектами,
    // начиная с адреса p
    
    // Освобождение памяти, занятой объектами типа T с адреса p
    void deallocate(T* p) { free(p); }
    
    // Создание объекта типа T со значением v по адресу p
    void construct(T* p, const T& v) { new (p) T(v); }
    
    // Уничтожение объекта T по адресу p
    void destroy(T* p) { p->~T(); }
};

// ----------------------------------------------------------------------

template<typename T, typename A = allocator<T>>
class vector
{
public:
    vector() : sz{0}, elem{nullptr}, space{0} {}
    
    explicit vector(int s) : sz{s}, elem{new T[s]}, space{s} {}
    
    vector(std::initializer_list<T> lst);
    
    ~vector() { delete[] elem; }
    
    // Копирующие конструктор и присваивание:
    vector(vector& arg);
    vector& operator=(vector& arg);
    
    // Перемещающие конструктор и присваивание:
    vector(vector&& arg);
    vector& operator=(vector&& arg);
    
    T& operator[ ](int n) { return elem[n]; }
    const T& operator[ ](int n) const { return elem[n]; }
    
    int size() const { return sz; }
    int capacity() const { return space; }
    
    void reserve(int newalloc);
    void resize(int newsize, T val = T());
    void push_back(const T& el);
    
private:
    A alloc;
    int sz;
    T* elem;
    int space;
};

template<typename T, typename A>
vector<T,A>::vector(std::initializer_list<T> lst) : sz{(int)lst.size()}, elem{new T[sz]}, space{sz}
{
    std::copy(lst.begin(), lst.end(), elem);
}

template<typename T, typename A>
vector<T,A>::vector(vector& arg) : sz{arg.sz}, elem{new T[arg.sz]}, space{arg.space}
{
    std::copy(arg.elem,arg.elem+sz,elem);
}

// for ex09
template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(vector& arg)
{
    if (this == &arg) {
        return *this;
    }
    
    if (arg.sz <= space)
    {
        for (int i = 0; i < arg.sz; ++i) {
            elem[i] = arg.elem[i];
        }
        sz = arg.sz;
        return *this;
    }
    
    T* p = alloc.allocate(arg.sz);
    for (int i = 0; i < arg.sz; ++i) {
        p[i] = arg.elem[i];
    }
    alloc.deallocate(elem);
    space = sz = arg.sz;
    elem = p;
    
    return *this;
}

template<typename T, typename A>
vector<T,A>::vector(vector&& arg) : sz{arg.sz}, elem{arg.elem}, space{arg.space}
{
    arg.elem = nullptr;
    arg.sz = 0;
    arg.space = 0;
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(vector&& arg)
{
    delete [] elem;
    elem = arg.elem;
    space = sz = arg.sz;
    arg.elem = nullptr;
    arg.sz = 0;
    arg.space = 0;
    return *this;
}

template<typename T, typename A>
void vector<T,A>::reserve(int newalloc)
{
    if (newalloc <= space) {
        return;
    }
    T* p = alloc.allocate(newalloc); // Выделяем новую память
    // Копирование:
    for (int i = 0; i < sz; ++i) {
        alloc.construct(&p[i],elem[i]);
    }
    // Уничтожение:
    for (int i = 0; i < sz; ++i) {
        alloc.destroy(&elem[i]);
    }
    alloc.deallocate(elem);   // Освобождаем старую память
    elem = p;
    space = newalloc;
}

template<typename T, typename A>
void vector<T,A>::resize(int newsize, T val)
{
    reserve(newsize);
    // Создаём:
    for (int i = sz; i < newsize; ++i) {
        alloc.construct(&elem[i],val);
    }
    // Уничтожаем:
    for (int i = newsize; i < sz; ++i) {
        alloc.destroy(&elem[i]);
    }
    sz = newsize;
}

template<typename T, typename A>
void vector<T,A>::push_back(const T& el)
{
    if (space == 0) {
        reserve(8);
    }
    else if (sz == space) {
        reserve(2*space);
    }
    alloc.construct(&elem[sz],el);
    ++sz;
}
