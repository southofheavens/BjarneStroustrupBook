/*
    Добавьте в программу возможность обработки скобок {} и (), чтобы выражение {(4+5)*6}/(3+4) стало 
    корректным.

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
        case '+': case '-': case '*': case '/':
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
// Вызывает функции Primary() и Get().
{
    double left = Primary(); // Считываем и вычисляем первичное выражение
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

double Primary()
// Первичное выражение. Работает с числами и скобками.
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
    Первичное_выражение
    Терм "*" Первичное_выражение
    Терм "/" Первичное_выражение
Первичное_выражение:
    Число
    "(" Выражение ")"
    "{" Выражение "}"
Число:
    Литерал_с_плавающей_точкой
*/

