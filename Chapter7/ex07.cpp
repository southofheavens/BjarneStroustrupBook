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
    Измените команды q и h на quit и help соответственно.
*/

#include <iostream>
#include <string>
#include <cmath> // для функции fmod()
#include <vector>

constexpr char number = '8'; // t.kind==number означает, что t - число
constexpr char quit = 'q'; // t.kind==quit означает, что t - лексема выхода
const std::string quitWord = "quit"; // Ключевое слово quit
constexpr char print = ';'; // t.kind==print означает, что t - лексема печати
constexpr char name = 'a'; // Лексема Имя
constexpr char let = 'L'; // Лексема let
const std::string declkey = "let"; // Ключевое слово let
constexpr char sqrtLex = 's'; // Лексема sqrt
const std::string sqrtWord = "sqrt"; // Ключевое слово sqrt
constexpr char powLex = 'p'; // Лексема pow
const std::string powWord = "pow"; // Ключевое слово pow
constexpr char constLex = 'c'; // Лексема const
const std::string constWord = "const"; // Ключевое слово const
constexpr char space = ' '; // Лексема пробела
constexpr char help = 'h'; // Лексема подсказки
const std::string helpWord = "help"; // Ключевое слово help


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
    bool isLet;
    Variable(std::string n, double v, bool l) : name{n}, value{v}, isLet{l} { }
};

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
    std::cin.get(ch); // Заметим, что оператор >> пропускает пробельные символы
    if (isspace(ch))
    {
        if (ch == '\n')
        {
            return Token{print};
        }
        while (ch == ' ')
        {
            std::cin.get(ch);
        }
    }
    ch = tolower(ch);
    switch(ch)
    {
        case print: // Для рассчёта результата выражения
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
                else if (s == constWord)
                {
                    return Token{constLex};
                }
                else if (s == quitWord)
                {
                    return Token{quit};
                }
                else if (s == helpWord)
                {
                    return Token{help};
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

class SymbolTable
{
public:
    double GetValue(std::string s);
    void SetValue(std::string s, double d);
    bool IsDeclared(std::string var);
    double DefineName(std::string var, double val, bool isLet);
private:
    std::vector<Variable> varTable;
};

double SymbolTable::GetValue(std::string s)
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

void SymbolTable::SetValue(std::string s, double d)
// Присваивает объекту s типа Variable значение d
{
    for (Variable& v : varTable)
    {
        if (v.name == s)
        {
            if (v.isLet)
            {
                v.value = d;
                return;
            }
            throw std::invalid_argument("Попытка присвоить новое значение константе!");
        }
    }
    throw std::invalid_argument("Неопределенная переменная!");
}

bool SymbolTable::IsDeclared(std::string var)
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

double SymbolTable::DefineName(std::string var, double val, bool isLet)
// Добавляем пару (var,val) в вектор varTable
{
    if (IsDeclared(var))
    {
        throw std::invalid_argument("Повторное объявление!");
    }
    varTable.push_back(Variable{var, val, isLet});
    return val;
}

SymbolTable symbolTab; // Предоставляет доступ к GetValue(), SetValue() и др.

double Declaration();
double Expression();

double Statement()
{
    Token t = ts.Get();
    switch(t.kind)
    {
        case let: case constLex:
            ts.PutBack(t);
            return Declaration();
        default:
            ts.PutBack(t);
            return Expression();
    }
}

double Declaration()
// Обрабатываем: let Имя = Выражение или const Имя = Выражение
// Объявление переменной с Именем с начальным значением,
// заданымм выражением
{
    bool isLet;
    Token t = ts.Get();
    t.kind == let ? isLet = true : isLet = false;
    
    t = ts.Get();
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
    symbolTab.DefineName(varName, d, isLet);
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
    while (t.kind == space)
    {
        t = ts.Get();
    }
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
            if(symbolTab.IsDeclared(t.name))
            {
                std::string nameOfVariable = t.name;
                t = ts.Get();
                if (t.kind == '=')
                {
                    double newValue = Expression();
                    symbolTab.SetValue(nameOfVariable, newValue);
                    return newValue;
                }
                else
                {
                    ts.PutBack(t);
                    return symbolTab.GetValue(nameOfVariable);
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
        else if (t.kind == help)
        {
            std::cout << "Список доступных операций: +, -, *, /, !, %. \n";
            std::cout << "Для определения переменной введите let 'имя переменной' = 'значение переменной'.\n";
            std::cout << "Чтобы изменить значение переменной, введите 'имя переменной' = 'новое значение переменной'.\n";
            std::cout << "Для определения константы введите const 'имя константы' = 'значение константы'.\n";
        }
        else
        {
            ts.PutBack(t);
            std::cout << Statement() << '\n';
        }
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
        CleanUpMess();
    }
}

int main()
{
    std::cout << "Добро пожаловать в программу-калькулятор! Чтобы увидеть справку, введите 'h'.\n";
    std::cout << "Пример выражения: 1+2*(3/4);. Для выхода введите 'q'. \n";
    Calculate();
    return 0;
}