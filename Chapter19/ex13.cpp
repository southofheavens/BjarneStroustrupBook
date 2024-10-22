/*
    Напишите класс Tracer, в котором конструктор и деструктор выводят на экран строки. Передайте эти строки
    конструктору в качестве аргументов. Используйте этот пример для того, чтобы посмотреть, как работает
    идиома RAII (например, поэкспериментируйте с объектами класса Tracer в качестве локальных объектов,
    объектов-членов класса, глобальных объектов, объектов, размещенных в динамической памяти с помощью
    оператора new, и т.д. Затем добавьте копирующий конструктор и копирующее присваивание, чтобы можно
    было увидеть поведение объектов класса Tracer в процессе копирования).
*/

#include <iostream>
#include <string>

class Tracer
{
public:
    Tracer(const std::string& h, const std::string& b) : hello{h}, bye{b}
    {
        std::cout << hello << '\n';
    }
    
    ~Tracer()
    {
        std::cout << bye << '\n';
    }
    
    Tracer(Tracer& other) { hello = other.hello; bye = other.bye; }
    Tracer& operator=(Tracer& other) { hello = other.hello; bye = other.bye; return *this; }
    
private:
    std::string hello;
    std::string bye;
};

class Test
{
public:
    Test() : privateMember{"Class member capture", "Class member free"} {}
    
private:
    Tracer privateMember;
};

Tracer global("Global capture", "Global free");

int main()
{
    Tracer stack("Stack capture", "Stack free");
    Tracer* heap = new Tracer("Heap capture", "Heap free");
    Test t;
        
    // Copy check
    Tracer stack2(stack);
    Tracer stack3 = stack2;
        
    delete heap;
    return 0;
}
