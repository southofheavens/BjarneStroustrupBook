/*
    Добавьте оператор вычисления факториала: для его представления используйте восклицательный знак !.
    Например, выражение 7! означает 7*6*5*4*3*2*1. Присвойте оператору более высокий приоритет по
    сравнению с операторами * и /, т.е. 7*8! должно означать 7*(8!), а не (7*8)!. Начните с
    модификации грамматики, чтобы учесть оператор с более высоким приоритетом. Для согласования
    со стандартным математическим определением факториала значение 0! примите равным 1.
    Указание: калькулятор работает с числами типа double, но факториал определен только для
    целочисленных значений. Поэтому для вычисления x! присвойте значение x переменной типа int
    и вычисляйте факториал этой переменной.
 
    ВНИМАНИЕ!!! НА ДАННОМ ЭТАПЕ ПРОГРАММА НЕ РАБОТАЕТ, ЕСЛИ ПЕРВОЕ ЧИСЛО БУДЕТ СО ЗНАКОМ МИНУС.
    ПРИМЕР: -1+5;. ОЖИДАЕМЫЙ ОТВЕТ: =-4, ФАКТИЧЕСКИЙ ОТВЕТ "Требуется первичное выражение!"
    СКОРЕЕ ВСЕГО ЭТОТ СЛУЧАЙ БУДЕТ РАССМОТРЕН В ГЛАВЕ №7.
*/

#include <iostream>

struct Token // Структура для считывания лексем
{
    char kind;
    double value;
};

class TokenStream
{
public:
    Token Get(); // Получает объект Token из потока
    void PutBack(Token t); // Возвращает Token обратно в потока
private:
    bool full{false}; // Имеется ли лексема в буфере?
    Token buffer; // Здесь хранится лексема после возврата с помощью PutBack()
};

void TokenStream::PutBack(Token t)
{
    if(full) // Если буфер заполнен
    {
        std::cout << "Буфер заполнен!\n";
        exit(4);
    }
    buffer = t; // Копируем t в буфер
    full = true; // Буфер заполнен
}

Token TokenStream::Get()
{
    if(full) // Есть готовый объект Token? Убираем его из буфера и возвращаем
    {
        full = false;
        return buffer;
    }
    char ch;
    std::cin >> ch; // Заметим, что оператор >> пропускает пробельные символы
    switch(ch)
    {
        case ';': // Для рассчёта результата выражения
        case 'q': // Для выхода
        case '(': case ')': case '{': case '}':
        case '+': case '-': case '*': case '/': case '!':
            return Token{ch}; // Символ представляет сам себя
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            std::cin.putback(ch); // Возвращаем цифру во входной поток
            double val;
            std::cin >> val; // Считываем число с плавающей точкой
            return Token{'8', val}; // '8' означает лексему "число"
        }
        default:
            std::cout << "Неверная лексема!\n";
            exit(5);
    }
}

TokenStream ts; // Предоставляет Get() и PutBack()

double Expression();
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
                left += Term(); // Вычисляем Терм и выполняем операцию сложения
                t = ts.Get();
                break;
            case '-':
                left -= Term(); // Вычисляем Терм и выполняем операцию вычитания
                t = ts.Get();
                break;
            default:
                ts.PutBack(t); // Возврат t в поток лексем
                return left; // Конец: символов + и - нет. Возвращаем ответ.
        }
    }
}

double Term()
// Терм. Работает с операциями * и /.
// Вызывает функции Secondary() и Get().
{
    double left = Secondary(); // Считываем и вычисляем первичное выражение
    Token t = ts.Get(); // Получаем следующую лексему
    while(true)
    {
        switch(t.kind)
        {
            case '*':
                left *= Primary(); // Вычисляем первичное выражение и выполняем операцию умножения
                t = ts.Get(); // Получаем следующую лексему
                break;
            case '/':
            {
                double d = Primary();
                if (d == 0)
                {
                    std::cout << "Деление на нуль!\n";
                    exit(1);
                }
                left /= d; // Вычисляем первичное выражение и выполняем операцию деления
                t = ts.Get(); // Получаем следующую лексему
                break;
            }
            default:
                ts.PutBack(t); // Возврат t в поток лексем
                return left; // Конец: символов * и / нет. Возвращаем ответ.
        }
    }
}

int Factorial(int num)
{
    int result = 1;
    for (int i = 1; i <= num; ++i)
    {
        result *= i;
    }
    return result;
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
            if (left >= 0)
            {
                return Factorial((int)left);
            }
            else
            {
                std::cout << "Факториал от отрицательного значения не определён!\n";
                exit(7);
            }
        default:
            ts.PutBack(t);
            return left;
            break;
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
                std::cout << "Требуется ')'!\n";
                exit(2);
            }
            return d;
        }
        case '{': // Обработка '{' expression '}'
        {
            double d = Expression();
            t = ts.Get();
            if (t.kind != '}')
            {
                std::cout << "Требуется '}'!\n";
                exit(6);
            }
            return d;
        }
        case '8': // Используем '8' для представления числа
            return t.value;
        default:
            std::cout << "Требуется первичное выражение!\n";
            exit(3);
    }
}

int main()
try
{
    std::cout << "Добро пожаловать в программу-калькулятор!\n";
    std::cout << "Пример выражения: 1+2*(3/4);. Для выхода введите 'q'. \n";
    double val = 0;
    while(std::cin)
    {
        Token t = ts.Get();
        if (t.kind == 'q')
        {
            std::cout << "До свидания!\n";
            break;
        }
        if (t.kind == ';')
        {
            std::cout << "=" << val << '\n';
        }
        else
        {
            ts.PutBack(t);
        }
        val = Expression();
    }
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
    return 1;
}

/*
--- Грамматика ---
Выражение:
    Терм
    Выражение "+" Терм
    Выражение "-" Терм
Терм:
    Вторичное_выражение
    Терм "*" Первичное_выражение
    Терм "/" Первичное_выражение
Вторичное_выражение:
    Первичное_выражение "!"
Первичное_выражение:
    Число
    "(" Выражение ")"
    "{" Выражение "}"
Число:
    Литерал_с_плавающей_точкой
*/
