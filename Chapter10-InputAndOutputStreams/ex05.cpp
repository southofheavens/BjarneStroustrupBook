/*
    Напишите функцию print_year(), упомянутую в разделе 10.11.2.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> monthes = {
    "jan", "feb", "mar", "apr", "may", "jun",
    "jul", "aug", "sep", "oct", "nov", "dec"
};

constexpr int NOT_A_READING = -7777; // ниже абсолютного нуля
constexpr int NOT_A_MONTH = -1; // не месяц
constexpr int IMPLAUSIBLE_MIN = -200;
constexpr int IMPLAUSIBLE_MAX = 200;

struct Day
{
    std::vector<double> hour {std::vector<double>(24, NOT_A_READING)};
};

struct Month
{
    int month {NOT_A_MONTH}; // [0,11] (январю соответствует 0)
    std::vector<Day> day {32}; // [1,31] по одному вектору на день
};

struct Year
{
    int year; // положительное значение
    std::vector<Month> month{12}; // [0, 11] (январю соответствует 0)
};

struct Reading
{
    int day;
    int hour;
    double temperature;
};

std::istream& operator>>(std::istream& is, Reading& r)
// считываем показания температуры из потока is в r
// формат: (3 4 9.7)
// проверяем формат, но не корректность данных
{
    char ch1;
    if (is >> ch1 && ch1 != '(')
    {
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }
    char ch2;
    int d;
    int h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2 != ')')
    {
        std::cout << "Плохая запись!\n";
        exit(1);
    }
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

int MonthToInt(std::string month)
{
    for (int i = 0; i < monthes.size(); ++i)
    {
        if (monthes[i] == month) return i;
    }
    return -1;
}

void EndOfLoop(std::istream& ist, char term, const std::string& message)
{
    if (ist.fail())
    {
        ist.clear();
        char ch;
        if (ist >> ch && ch == term) return; // Все хорошо
        std::cout << message << '\n';
        exit(5);
    }
}

bool IsValid(const Reading& r)
{
    if (r.day < 1 || 31 < r.day) return false;
    if (r.hour < 0 || 23 < r.hour) return false;
    if (r.temperature < IMPLAUSIBLE_MIN ||
        IMPLAUSIBLE_MAX < r.temperature)
    {
        return false;
    }
    return true;
}

std::istream& operator>>(std::istream& is, Month& m)
// считываем объект класса Month из потока is в объект m
// формат: { month feb ... }
{
    char ch = 0;
    if (is >> ch && ch != '{')
    {
        is.unget();
        is.clear(std::ios_base::failbit); // ошибка ввода Month
        return is;
    }
    
    std::string monthMarker;
    std::string mm;
    is >> monthMarker >> mm;
    if (!is || monthMarker != "month")
    {
        std::cout << "Неверное начало Month\n";
        exit(2);
    }
    m.month = MonthToInt(mm);
    
    int duplicates = 0;
    int invalids = 0;
    for (Reading r; is >> r; )
    {
        if (IsValid(r))
        {
            if (m.day[r.day].hour[r.hour] != NOT_A_READING)
            {
                ++duplicates;
            }
            m.day[r.day].hour[r.hour] = r.temperature;
        }
        else
        {
            ++invalids;
        }
    }
    if (invalids)
    {
        std::cout << "Неверные данные в Month, всего " << invalids << '\n';
        exit(3);
    }
    if (duplicates)
    {
        std::cout << "Повторяющиеся показания в Month, всего " << duplicates << '\n';
        exit(4);
    }
    EndOfLoop(is, '}', "Неправильный конец Month");
    return is;
}

std::istream& operator>>(std::istream& is, Year& y)
// считываем объект класса Year из потока is в объект y
// формат: { year 1972 ... }
{
    char ch;
    is >> ch;
    if (ch != '{')
    {
        is.unget();
        is.clear(std::ios_base::failbit);
        return is;
    }
    
    std::string yearMarker;
    int yy;
    is >> yearMarker >> yy;
    if (!is || yearMarker != "year")
    {
        std::cout << "Неправильное начало Year\n";
        exit(6);
    }
    y.year = yy;
    while(true) {
            Month m;        // get a clean m each time around
            if (!(is >> m)) break;
            y.month[m.month] = m;
        }
    
    EndOfLoop(is, '}', "Неправильный конец Year");
    return is;
}

int main()
{
    std::fstream ifs;
    ifs.open("data", std::ios_base::in);
    // генерация исключения в случае состояния bad()
    ifs.exceptions(ifs.exceptions() | std::ios_base::failbit);
    
    std::fstream ofs;
    ofs.open("result", std::ios_base::out);
    
    std::vector<Year> ys;
    while(true)
    {
        Year y;
        if (!(ifs >> y)) break;
        ys.push_back(y);
    }
    
    
    return 0;
}
