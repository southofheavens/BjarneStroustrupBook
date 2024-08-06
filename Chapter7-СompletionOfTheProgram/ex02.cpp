/*
Простой калькулятор
 
Эта программа реализует основные выражения калькулятора.
 
Ввод осуществляется из потока std::cin; вывод - в поток std::cout.

--- Грамматика ---
Вычисление:
    Инструкция
    Вывод
    Выход
    Вычисление Инструкция
Инструкция:
    Объявление
    Выражение
Объявление:
    "let" Имя "=" Выражение
Присваивание:
    Имя "=" Выражение
Вывод:
    ;
Выход:
    q
 
Выражение:
    Терм
    Выражение "+" Терм
    Выражение "-" Терм
Терм:
    Вторичное_выражение
    Терм "*" Вторичное_выражение
    Терм "/" Вторичное_выражение
    Терм "%" Вторичное_выражение
Вторичное_выражение:
    Первичное_выражение "!"
Первичное_выражение:
    Число
    Переменная
    "(" Выражение ")"
    "{" Выражение "}"
    "-" Первичное_выражение
    "+" Первичное_выражение
    sqrt(Выражение)
    pow(Выражение, Выражение)
Число:
    Литерал_с_плавающей_точкой
 
Ввод из потока std::cin через TokenStream с именем ts.
 
Упражнение: 
    Реализуйте оператор присваивания =, чтобы можно было изменять значение переменной
    после её объявления с помощью инструкции let. Подумайте, почему эта возможность может быть
    полезной и к каким проблемам она может привести.
*/

#include <iostream>
#include <string>
#include <cmath> // для функции fmod()
#include <vector>

constexpr char number = '8'; // t.kind==number означает, что t - число
constexpr char quit = 'q'; // t.kind==quit означает, что t - лексема выхода
constexpr char print = ';'; // t.kind==print означает, что t - лексема печати
//const std::string prompt = "> "; // Используется для приглашения
//const std::string result = "= "; // Используется при выводе результата
constexpr char name = 'a'; // Лексема Имя
constexpr char let = 'L'; // Лексема let
const std::string declkey = "let"; // Ключевое слово let
constexpr char sqrtLex = 's'; // Лексема sqrt
const std::string sqrtWord = "sqrt"; // Ключевое слово sqrt
constexpr char powLex = 'p'; // Лексема pow
const std::string powWord = "pow"; // Ключевое слово pow


struct Token // Структура для считывания лексем
{
    char kind;
    double value;
    std::string name;
    
    // Инициализирует kind символом ch
    Token(char ch) : kind{ch} {}
    
    // Инициализирует kind и value
    Token(char ch, double val) : kind{ch}, value{val} {}
    
    // Инициализирует kind и name
    Token(char ch, std::string n) : kind{ch}, name{n} {}
};

struct Variable // Структура для переменных
{
    std::string name;
    double value;
    Variable(std::string n, double v) : name{n}, value{v} { }
};

std::vector<Variable> varTable; // Сомнительно, что вектор глобальный

double GetValue(std::string s)
// Возвращает значение переменной с именем s
{
    for (const Variable& v : varTable)
    {
        if (v.name == s)
        {
            return v.value;
        }
    }
    throw std::invalid_argument("Неопределенная переменная!");
}

void SetValue(std::string s, double d)
// Присваивает объекту s типа Variable значение d
{
    for (Variable& v : varTable)
    {
        if (v.name == s)
        {
            v.value = d;
            return;
        }
    }
    throw std::invalid_argument("Неопределенная переменная!");
}

class TokenStream
{
public:
    TokenStream() : full(0), buffer(0) {}
    Token Get(); // Получает объект Token из потока
    void PutBack(Token t); // Возвращает Token обратно в поток
    void Ignore(char c); // Отбрасывает символы до символа c включительно
private:
    bool full{false}; // Имеется ли лексема в буфере?
    Token buffer; // Здесь хранится лексема после возврата с помощью PutBack()
};

Token TokenStream::Get()
{
    if (full) // Есть готовый объект Token? Убираем его из буфера и возвращаем
    {
        full = false;
        return buffer;
    }
    char ch;
    std::cin >> ch; // Заметим, что оператор >> пропускает пробельные символы
    switch(ch)
    {
        case print: // Для рассчёта результата выражения
        case quit: // Для выхода
        case '(': 
        case ')':
        case '{':
        case '}':
        case '+':
        case '-':
        case '*':
        case '/':
        case '!':
        case '%':
        case '=':
        case ',':
            return Token{ch}; // Символ представляет сам себя
            
        case '.': // Число с плавающей точкой может начинаться с точки
        // Числовой литерал
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            std::cin.putback(ch); // Возвращаем цифру во входной поток
            double val;
            std::cin >> val; // Считываем число с плавающей точкой
            return Token{number, val};
        }
        default:
            if (isalpha(ch))
            {
                std::string s;
                s += ch;
                while(std::cin.get(ch) && // get работает как >>, но не пропускает пробелы
                      (isalpha(ch) || isdigit(ch) || ch == '_'))
                {
                    s += ch;
                }
                std::cin.putback(ch);
                if (s == declkey)
                {
                    return Token{let}; // Ключевое слово объявления
                }
                else if (s == sqrtWord)
                {
                    return Token{sqrtLex};
                }
                else if (s == powWord)
                {
                    return Token{powLex};
                }
                return Token{name, s};
            }
            throw std::invalid_argument("Неверная лексема!");
    }
}

void TokenStream::PutBack(Token t)
{
    if (full) // Если буфер заполнен
    {
        throw std::invalid_argument("Буфер заполнен!");
    }
    buffer = t; // Копируем t в буфер
    full = true; // Буфер заполнен
}

void TokenStream::Ignore(char c)
// Символ c представляет разновидность лексем
{
    // Сначала проверяем буфер
    if (full && c == buffer.kind)
    {
        full = false;
        return;
    }
    full = false;
    
    // Теперь проверяем входные данные
    char ch;
    while(std::cin >> ch)
    {
        if (ch == c)
        {
            return;
        }
    }
}

TokenStream ts; // Предоставляет Get(), PutBack() и Ignore()

double Declaration();
double Expression();

double Statement()
{
    Token t = ts.Get();
    switch(t.kind)
    {
        case let:
            return Declaration();
        default:
            ts.PutBack(t);
            return Expression();
    }
}

bool IsDeclared(std::string var)
// Есть ли переменная var в векторе varTable?
{
    for (const Variable& v : varTable)
    {
        if (v.name == var)
        {
            return true;
        }
    }
    return false;
}

double DefineName(std::string var, double val)
// Добавляем пару (var,val) в вектор varTable
{
    if (IsDeclared(var))
    {
        throw std::invalid_argument("Повторное объявление!");
    }
    varTable.push_back(Variable{var, val});
    return val;
}

double Declaration()
// Считаем, что мы уже встретили ключевое слово "let"
// Обрабатываем: Имя = Выражение
// Объявление переменной с Именем с начальным значением,
// заданымм выражением
{
    Token t = ts.Get();
    if (t.kind != name)
    {
        throw std::invalid_argument("В объявлении ожидается имя переменной!");
    }
    std::string varName = t.name;
    Token t2 = ts.Get();
    if (t2.kind != '=')
    {
        throw std::invalid_argument("Пропущен символ = в объявлении!");
    }
    double d = Expression();
    DefineName(varName, d);
    return d;
}

double Term();
double Secondary();
double Primary();

double Expression()
// Выражение. Работает с операциями + и -.
// Вызывает функции Term() и Get().
{
    double left = Term(); // Считываем и вычисляем Терм
    Token t = ts.Get(); // Получаем следующую лексему
    while(true)
    {
        switch(t.kind)
        {
            case '+':
                t = ts.Get();
                if (t.kind == '+' || t.kind == '-')
                {
                    throw std::invalid_argument("Некорректное выражение!");
                }
                ts.PutBack(t);
                left += Term(); // Вычисляем Терм и выполняем операцию сложения
                t = ts.Get();
                break;
            case '-':
                t = ts.Get();
                if (t.kind == '+' || t.kind == '-')
                {
                    throw std::invalid_argument("Некорректное выражение!");
                }
                ts.PutBack(t);
                left -= Term(); // Вычисляем Терм и выполняем операцию вычитания
                t = ts.Get();
                break;
            default:
                ts.PutBack(t); // Возврат t в поток лексем
                return left; // Конец: символов + и - нет. Возвращаем ответ.
        }
    }
}

int64_t Factorial(int num)
{
    int result = 1;
    for (int i = 1; i <= num; ++i)
    {
        result *= i;
    }
    return result;
}

double Term()
// Терм. Работает с операциями * и /.
// Вызывает функции Secondary() и Get().
{
    double left = Secondary(); // Считываем и вычисляем вторичное выражение
    Token t = ts.Get(); // Получаем следующую лексему
    while(true)
    {
        switch(t.kind)
        {
            case '*':
                left *= Secondary(); // Вычисляем первичное выражение и выполняем операцию умножения
                t = ts.Get(); // Получаем следующую лексему
                break;
            case '/':
            {
                double d = Secondary();
                if (d == 0)
                {
                    throw std::invalid_argument("Деление на ноль запрещено!");
                }
                left /= d; // Вычисляем первичное выражение и выполняем операцию деления
                t = ts.Get(); // Получаем следующую лексему
                break;
            }
            case '%':
            {
                double d = Secondary();
                if (d == 0)
                {
                    throw std::invalid_argument("Деление на ноль запрещено!");
                }
                left = fmod(left, d);
                t = ts.Get();
                break;
            }
            default:
                ts.PutBack(t); // Возврат t в поток лексем
                return left; // Конец: символов * и / нет. Возвращаем ответ.
        }
    }
}

double Secondary()
// Вторичное выражение. Работает с факториалом.
// Вызывает функции Primary() и Get()
{
    double left = Primary();
    Token t = ts.Get();
    switch(t.kind)
    {
        case '!':
            t = ts.Get();
            if (t.kind == '!')
            {
                throw std::invalid_argument("Некорректное выражение!");
            }
            ts.PutBack(t);
            if (left >= 0 && fmod(left, 1) == 0)
            {
                return Factorial((int)left);
            }
            else
            {
                throw std::invalid_argument("Попытка вычислить факториал от отрицательного значения \n"
                                            "или от числа типа double");
            }
        default:
            ts.PutBack(t);
            return left;
    }
}

double PowCalc()
{
    Token t = ts.Get();
    if (t.kind == '(')
    {
        double lval = Expression();
        double rval = 0;
        t = ts.Get();
        double result;
        if(t.kind == ',')
        {
            rval = Expression();
            if (fmod(rval, 1) == 0)
            {
                result = pow(lval, rval);
            }
            else
            {
                throw std::invalid_argument("Аргумент b, где pow(a,b), должен принимать значение int!");
            }
        }
        else
        {
            throw std::invalid_argument("Второй аргумент не указан!");
        }
        t = ts.Get();
        if (t.kind != ')')
        {
            throw std::invalid_argument("Требуется ')'!");
        }
        return result;
    }
    else
    {
        throw std::invalid_argument("Требуется '('!");
    }
}

double SqrtCalc()
{
    Token t = ts.Get();
    if (t.kind == '(')
    {
        double operand = Expression();
        t = ts.Get();
        if (t.kind != ')')
        {
            throw std::invalid_argument("Требуется ')'!");
        }
        if (operand >= 0)
        {
            return sqrt(operand);
        }
        else
        {
            throw std::invalid_argument("Квадратный корень от отрицательного числа не определён!");
        }
    }
    else
    {
        throw std::invalid_argument("Требуется '('!");
    }
}

double Primary()
// Первичное выражение. Работает с числами, скобками и факториалом.
// Вызывает функции Expression() и Get().
{
    Token t = ts.Get();
    switch(t.kind)
    {
        case '(': // Обработка '(' expression ')'
        {
            double d = Expression();
            t = ts.Get();
            if (t.kind != ')')
            {
                throw std::invalid_argument("Требуется ')'!");
            }
            return d;
        }
        case '{': // Обработка '{' expression '}'
        {
            double d = Expression();
            t = ts.Get();
            if (t.kind != '}')
            {
                throw std::invalid_argument("Требуется '}'!");
            }
            return d;
        }
        case number:
            return t.value;
        case name:
        {
            if(IsDeclared(t.name))
            {
                std::string nameOfVariable = t.name;
                t = ts.Get();
                if (t.kind == '=')
                {
                    double newValue = Expression();
                    for (Variable& elem : varTable)
                    {
                        if (elem.name == nameOfVariable)
                        {
                            elem.value = newValue;
                        }
                    }
                    return newValue;
                }
                else
                {
                    ts.PutBack(t);
                    for (const Variable& elem : varTable)
                    {
                        if (elem.name == nameOfVariable)
                        {
                            return elem.value;
                        }
                    }
                }
            }
            std::string mess = "Переменная " + t.name + " не определена";
            throw std::invalid_argument(mess);
        }
        case '-': // Унарный минус
            return - Primary();
        case '+': // Унарный плюс
            return Primary();
        case sqrtLex: // Квадратный корень
            return SqrtCalc();
        case powLex: // Возведение числа в степени
            return PowCalc();
        default:
            throw std::invalid_argument("Требуется первичное выражение!");
    }
}

void CleanUpMess()
{
    ts.Ignore(print);
}

void Calculate() // Цикл вычисления выражения
{
    while(std::cin)
    try
    {
        //std::cout << prompt;
        Token t = ts.Get();
        while(t.kind == print)
        {
            t = ts.Get(); // Съедает ';'
        }
        if (t.kind == quit)
        {
            std::cout << "До свидания!\n";
            exit(1);
        }
        ts.PutBack(t);
        std::cout << Statement() << '\n';
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
        CleanUpMess();
    }
}

int main()
{
    std::cout << "Добро пожаловать в программу-калькулятор!\n";
    std::cout << "Пример выражения: 1+2*(3/4);. Для выхода введите 'q'. \n";
    Calculate();
    return 0;
}
