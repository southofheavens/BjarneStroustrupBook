/*
    Задание
    1. Определите класс template<typename T> struct S {T val};
    2. Добавьте конструктор, чтобы можно было инициализировать его типом T.
    3. Определите переменные типов S<int>, S<char>, S<double>, S<string> и S<vector<int>>;
    инициализируйте их значениями по своему выбору.
    4. Прочитайте эти значения и выведите их на экран.
    5. Добавьте шаблонную функцию get(), возвращающую ссылку на переменную val.
    6. Разместите функцию get() за пределами класса.
    7. Сделайте член val закрытым.
    8. Выполните п. 4, используя функцию get().
    9. Добавьте шаблонную функцию set(), чтобы можно было изменять значение члена val.
    10. Замените функцию set() оператором S<T>::operator=(const T&). Указание: это гораздо
    проще, чем в разделе 19.2.5.
    11. Напишите константную и неконстантную версии функции get().
    12. Определите функцию template<typename T> read_val(T&v), выполняющую ввод данных из
    потока cin в переменную v.
    13. Используйте функцию read_val(), чтобы считать данные в каждую из переменных,
    перечисленных в п. 3, за исключением переменной S<vector<int>>.
    14. Бонус: определите операторы ввода и вывода (>> и <<) для vector<T>. И для ввода,
    и для вывода используйте формат {val, val, val}. Это позволит функции read_val()
    работать с переменной S<vector<int>>.
    Не забудьте выполнить тестирование после каждого этапа.
*/

#include <iostream>
#include <string>
#include <vector>

template<typename T> 
struct S
{
    S() {}
    explicit S(T vv) : val{vv} {}
            
    T& Get();
    
    const T& Get() const;
        
    S& operator=(const T& newVal);
    
private:
    T val;
};

template<typename T> 
T& S<T>::Get()
{
    return val;
}

template<typename T> 
const T& S<T>::Get() const
{
    return val;
}

template<typename T> 
S<T>& S<T>::operator=(const T& newWal)
{
    val = newWal;
    return *this;
}

template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec)
{
    char ch;
    T var;
    is >> ch;
    for (T var; is >> var;)
    {
        vec.push_back(var);
        is >> ch;
        if (ch != ',') {
            is.clear(std::ios_base::failbit);
            return is;
        }
    }
    is >> ch;
    if (ch != '}') {
        is.clear(std::ios_base::failbit);
        return is;
    }
    return is;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    os << '{';
    for (int i = 0; i < vec.size(); ++i)
    {
        os << vec[i];
        i != vec.size() - 1 ? os << ',' : os << '}';
    }
    return os;
}

template<typename T>
void ReadVal(T& v)
{
    std::cin >> v;
}

int main()
{
    /*
    S<int> intVar{19};
    S<char> charVar{'s'};
    S<double> doubleVar{57.5};
    S<std::string> stringVar{"Kerry"};
    S<std::vector<int>> vec{{1,2,3}};
    
    std::cout << intVar.Get() << '\n';
    std::cout << charVar.Get() << '\n';
    std::cout << doubleVar.Get() << '\n';
    std::cout << stringVar.Get() << '\n';
    for (int i = 0; i < vec.Get().size(); ++i)
    {
        std::cout << vec.Get()[i];
        i != vec.Get().size() - 1 ? std::cout << ' ' : std::cout << '\n';
    }
    
    intVar = 25;
    std::cout << intVar.Get() << '\n';
    */
    
    S<int> intVar;
    int someInt;
    ReadVal(someInt);
    intVar = someInt;
    
    S<char> charVar;
    char someChar;
    ReadVal(someChar);
    charVar = someChar;
    
    S<double> doubleVar;
    double someDouble;
    ReadVal(someDouble);
    doubleVar = someDouble;
    
    S<std::string> stringVar;
    std::string someString;
    ReadVal(someString);
    stringVar = someString;
    
    S<std::vector<int>> vec;
    std::vector<int> someVec;
    ReadVal(someVec);
    vec = someVec;
    
    std::cout << intVar.Get() << ' ' << charVar.Get() << ' ';
    std::cout << doubleVar.Get() << ' ' << stringVar.Get() << '\n';
    std::cout << vec.Get() << '\n';
    
    return 0;
}
