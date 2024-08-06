/*
    Разработайте вариант калькулятора из главы 7, который работал бы не с арабскими,
    а с римскими цифрами, например XXI + CIV == CXXV.
*/

#include <iostream>
#include <string>
#include <vector>

enum class RomanNums {I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000};

class Roman
{
public:
    Roman();
    Roman(const std::string romanNumber);
    int AsInt() const;
    
private:
    int number;
    std::string romanNumber;
    int FromCharRomanToInt(const char r);
    int FromStringRomanToInt();
    bool CheckCorrect(); // проверка на корректность введённого числа
    
    friend std::ostream& operator<<(std::ostream& os, Roman& r);
    friend Roman operator+(const Roman& first, const Roman& second);
    friend Roman operator-(const Roman& first, const Roman& second);
};

std::string FromIntToRoman(const int num);
std::istream& operator>>(std::istream& is, Roman& r);

Roman::Roman() {}

Roman::Roman(std::string romanNumber) : romanNumber{romanNumber}
{
    if (CheckCorrect())
    {
        number = FromStringRomanToInt();
    }
    else
    {
        throw std::invalid_argument("Введено некорректное римское число!");
    }
}

int Roman::AsInt() const
{
    return number;
}

int Roman::FromCharRomanToInt(char r)
{
    switch(r)
    {
        case 'I':
            return (int)RomanNums::I;
        case 'V':
            return (int)RomanNums::V;
        case 'X':
            return (int)RomanNums::X;
        case 'L':
            return (int)RomanNums::L;
        case 'C':
            return (int)RomanNums::C;
        case 'D':
            return (int)RomanNums::D;
        default:
            return (int)RomanNums::M;
    }
}

int Roman::FromStringRomanToInt()
{
    int previousNumber = FromCharRomanToInt(romanNumber[romanNumber.length() - 1]);
    int result = previousNumber;
    for (int i = (int)romanNumber.length() - 2; i >= 0; --i)
    {
        int num = FromCharRomanToInt(romanNumber[i]);
        if (previousNumber == num)
        {
            result += num;
        }
        else if (previousNumber > num)
        {
            result -= num;
        }
        else
        {
            result += num;
        }
        previousNumber = num;
    }
    return result;
}

bool Roman::CheckCorrect()
{
    std::vector<std::string> unacceptable = {"IL", "IC", "ID", "IM", "VX", "VL", "VC",
        "VD", "VM", "XD", "XM", "LC", "LD", "LM", "DM"};
    bool state = false; // false при >=, true при <
    int coincidences = 0; // количество совпавших символов
    for (int i = 0; i < romanNumber.length() - 1; ++i)
    {
        int firstNum = FromCharRomanToInt(romanNumber[i]);
        int secondNum = FromCharRomanToInt(romanNumber[i + 1]);
        char num1 = romanNumber[i];
        char num2 = romanNumber[i + 1];
        char str[3] = {num1, num2, '\0'};
        for (int i = 0; i < unacceptable.size(); ++i)
        {
            if (str == unacceptable[i])
            {
                return false;
            }
        }
        if (firstNum == secondNum)
        {
            coincidences++;
            if ((coincidences == 3 && !state) || (coincidences == 1 && state)
                || (coincidences == 1 && firstNum == (int)RomanNums::V && secondNum == (int)RomanNums::V)  // Запись VV недопустима
                || (coincidences == 1 && firstNum == (int)RomanNums::L && secondNum == (int)RomanNums::L) // Запись LL недопустима
                || (coincidences == 1 && firstNum == (int)RomanNums::D && secondNum == (int)RomanNums::D)) // Запись DD недопустима
            {
                return false;
            }
        }
        else if (firstNum > secondNum)
        {
            state = false;
            coincidences = 0;
        }
        else
        {
            if (coincidences == 1)
            {
                return false;
            }
            state = true;
            coincidences = 0;
        }
    }
    return true;
}

std::istream& operator>>(std::istream& is, Roman& r)
{
    std::string inputRomanNumber;
    is >> inputRomanNumber;
    if (!is)
    {
        return is;
    }
    for (int i = 0; i < inputRomanNumber.length(); ++i)
    {
        if (inputRomanNumber[i] == 'I' || inputRomanNumber[i] == 'V'
            || inputRomanNumber[i] == 'X' || inputRomanNumber[i] == 'L'
            || inputRomanNumber[i] == 'C' || inputRomanNumber[i] == 'D'
            || inputRomanNumber[i] == 'M')
        {
            continue;
        }
        else
        {
            is.clear(std::ios_base::failbit);
            return is;
        }
    }
    r = Roman(inputRomanNumber);
    return is;
}

std::ostream& operator<<(std::ostream& os, Roman& r)
{
    os << r.romanNumber;
    return os;
}

std::string FromIntToRoman(int num);

Roman operator+(const Roman& first, const Roman& second)
{
    Roman result;
    int firstInt = first.AsInt();
    int secondInt = second.AsInt();
    int intOurResult = firstInt + secondInt;
    result.number = intOurResult;
    result.romanNumber = FromIntToRoman(intOurResult);
    return result;
}

Roman operator-(const Roman& first, const Roman& second)
{
    Roman result;
    int firstInt = first.AsInt();
    int secondInt = second.AsInt();
    int intOurResult = firstInt - secondInt;
    result.number = intOurResult;
    result.romanNumber = FromIntToRoman(intOurResult);
    return result;
}

std::string FromIntToRoman(int num)
{
    std::string result;
    std::vector<int> intNums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::vector<std::string> romanNums = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    if (num <= 0)
    {
        throw std::invalid_argument("Результат получается отрицательным, что недопустимо для римского числа!");
    }
    else if (num > 3999)
    {
        throw std::invalid_argument("Максимальное возможное римское число - MMMCMXCIX (3999 в арабской С.С.)!");
    }
    while(num != 0)
    {
        for (int i = 0; i < intNums.size(); ++i)
        {
            if (num - intNums[i] >= 0)
            {
                num -= intNums[i];
                result += romanNums[i];
                break;
            }
        }
    }
    return result;
}


constexpr char quit = 'q'; // t.kind==quit означает, что t - лексема выхода
constexpr char print = ';'; // t.kind==print означает, что t - лексема печати
constexpr char number = 'r'; // t.kind==number означает, что r - лексема римского числа

struct Token // Структура для считывания лексем
{
    char kind;
    Roman value;
    
    Token(char ch) : kind{ch} {}
    Token(char ch, Roman val) : kind{ch}, value{val} {}
};

class TokenStream
{
public:
    TokenStream() : full{0}, buffer{0} {}
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
    std::cin.get(ch); // Заметим, что get() НЕ пропускает пробельные символы
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
    switch(ch)
    {
        case print: // Для рассчёта результата выражения
        case quit: // Для выхода
        case '+':
        case '-':
            return Token{ch}; // Символ представляет сам себя
            
        case 'I': case 'V': case 'X':
        case 'L': case 'C': case 'D': case 'M':
        {
            std::string num;
            while(ch == 'I' || ch == 'V' || ch == 'X'
                  || ch == 'L' || ch == 'C' || ch == 'D' || ch == 'M')
            {
                num += ch;
                std::cin.get(ch);
            }
            std::cin.putback(ch); // Возвращаем цифру во входной поток
            Roman val{num};
            return Token{number, val};
        }
        default:
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

Roman Primary();

Roman Expression()
// Выражение. Работает с операциями + и -.
// Вызывает функции Primary() и Get().
{
    Roman left = Primary(); // Считываем и вычисляем первичное выражение
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
                left = left + Primary(); // Вычисляем первичное выражение и выполняем операцию сложения
                t = ts.Get();
                break;
            case '-':
                t = ts.Get();
                if (t.kind == '+' || t.kind == '-')
                {
                    throw std::invalid_argument("Некорректное выражение!");
                }
                ts.PutBack(t);
                left = left - Primary(); // Вычисляем первичное выражение и выполняем операцию вычитания
                t = ts.Get();
                break;
            default:
                ts.PutBack(t); // Возврат t в поток лексем
                return left; // Конец: символов + и - нет. Возвращаем ответ.
        }
    }
}

Roman Primary()
// Первичное выражение. Работает с числами, скобками и факториалом.
// Вызывает функции Expression() и Get().
{
    Token t = ts.Get();
    switch(t.kind)
    {
        case number:
            return t.value;
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
        Roman ex = Expression();
        std::cout << ex << '\n';
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
    std::cout << "Пример выражения: XII + V;. Для выхода введите 'q'. \n";
    Calculate();
    return 0;
}

