/*
    Разработайте и реализуйте указатель counted_ptr<T>, владеющий указателем на объект типа T, и указатель
    на "счетчик ссылок" (типа int), совместно используемый всеми указателями на один и тот же объект типа T.
    Счетчик ссылок должен содержать количество указателей, указывающих на данный объект типа T. Конструктор
    counted_ptr должен размещать в динамической памяти объект типа T и счетчик ссылок. Конструктор
    counted_ptr должен получать аргумент, используемый в качестве начального значения указателя на элемент
    типа T. После уничтожения последнего объекта counted_ptr для данного объекта типа T его деструктор должен
    удалить этот объект. Предусмотрите в классе counted_ptr операции, позволяющие использовать его как
    указатель. Это пример так называемого "интеллектуального указателя", который используется для того, чтобы
    гарантировать, что объект не будет уничтожен, пока последний пользователь не закончит его использовать.
    Напишите набор тестов для класса counted_ptr, используя его объекты в качестве аргументов при вызове
    функций, в качестве элементов контейнеров и т.д.
*/

#include <iostream>
#include <vector>

template <typename T>
class CountedPtr
{
public:
    CountedPtr();
    
    explicit CountedPtr(T* p);
    
    ~CountedPtr();
    
    int UseCount() { return *counter; }
    
    T& operator *() { return *p; }
    
    T* operator->() { return p; }
        
    CountedPtr(CountedPtr& other);              // Копирующий конструктор
    CountedPtr& operator=(CountedPtr& other);   // Копирующее присваивание
    
    CountedPtr(CountedPtr&& other);             // Перемещающий конструктор
    CountedPtr& operator=(CountedPtr&& other);  // Перемещающее присваивание
    
private:
    T* p;
    int* counter;
};

template <typename T>
CountedPtr<T>::CountedPtr()
{
    p = new T;
    counter = new int{1};
    //std::cout << "Объект " << counter << " успешно создан!\n";
}

template <typename T>
CountedPtr<T>::CountedPtr(T* p) : p{p}
{
    counter = new int{1};
    //std::cout << "Объект " << counter << " успешно создан!\n";
}

template <typename T>
CountedPtr<T>::~CountedPtr()
{
    --(*counter);
    if (*counter == 0)
    {
        delete p;
        delete counter;
        //std::cout << "Объект " << counter << " успешно удалён!\n";
    }
}

template <typename T>
CountedPtr<T>::CountedPtr(CountedPtr& other) : p{other.p}, counter{other.counter}
{
    ++(*counter);
}

template <typename T>
CountedPtr<T>& CountedPtr<T>::operator=(CountedPtr& other)
{
    if (this == &other) {
        return *this;
    }
    this->~CountedPtr<T>();
    p = other.p;
    counter = other.counter;
    ++(*counter);
    return *this;
}

template <typename T>
CountedPtr<T>::CountedPtr(CountedPtr&& other)
{
    //std::cout << "Перемещающий конструктор!\n";
    p = other.p;
    counter = other.counter;
    ++(*counter);
}

template <typename T>
CountedPtr<T>& CountedPtr<T>::operator=(CountedPtr&& other)
{
    //std::cout << "Перемещающее присваивание!\n";
    if (this == &other) {
        return *this;
    }
    this->~CountedPtr<T>();
    p = other.p;
    counter = other.counter;
    ++(*counter);
    return *this;
}

// -----------------------------------------------

template <typename T>
CountedPtr<T> Func(CountedPtr<T>& somePtr)
{
    return somePtr;
}

int main()
{
    CountedPtr<int> ptr1{new int(10)};      // counter1: 1
    std::cout << ptr1.UseCount() << '\n';
    
    CountedPtr<int> ptr2{ptr1};             // counter1: 2
    std::cout << ptr2.UseCount() << '\n';
    
    CountedPtr<int> ptr3;                   // counter?: 1
    ptr3 = ptr2;                            // ptr3->~CountedPtr<T>(); counter1: 3
    std::cout << ptr3.UseCount() << '\n';
    
    CountedPtr<int> ptr4{Func(ptr3)};       // counter1: 4
    std::cout << ptr4.UseCount() << '\n';
    
    CountedPtr<int> ptr5;                   // counter?: 1
    ptr5 = Func(ptr4);                      // ptr5->~CountedPtr<T>(); counter1: 5
    std::cout << ptr5.UseCount() << '\n' << "---\n";
    
    CountedPtr<int> ptr6{new int(11)};      // counter2: 1
    
    std::vector<CountedPtr<int> > someVec;
    someVec.push_back(std::move(ptr1));     // counter1: 6
    someVec.push_back(std::move(ptr2));     // counter1: 7
    someVec.push_back(std::move(ptr3));     // counter1: 8
    someVec.push_back(std::move(ptr4));     // counter1: 9
    someVec.push_back(std::move(ptr5));     // counter1: 10
    someVec.push_back(std::move(ptr6));     // counter2: 2
    
    for (int i = 0; i < someVec.size(); ++i) {
        std::cout << someVec[i].UseCount() << '\n';
    }
    
    return 0;
}
