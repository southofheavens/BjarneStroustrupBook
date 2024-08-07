/*
    Определите класс Roman_int для хранения римских цифр (как чисел типа int) с операторами
    << и >>. Включите в класс Roman_int функцию as_int(), возвращающую значение типа int,
    так, чтобы, если объект r имеет тип Roman_int, мы могли написать
    cout << "Римское " << r << " равно " << r.as_int() << '\n';.
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
    std::vector<std::string> unacceptable = {"IL", "IC", "ID", "IM", "VV", "VX", "VL", "VC",
        "VD", "VM", "XD", "XM", "LL", "LC", "LD", "LM", "DD", "DM"};
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
            if ((coincidences == 3 && !state) || (coincidences == 1 && state))
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

int main()
{
    while (std::cin)
    try
    {
        Roman romanNumber;
        std::cin >> romanNumber;
        std::cout << "Римское " << romanNumber << " равно " << romanNumber.AsInt() << '\n';
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
