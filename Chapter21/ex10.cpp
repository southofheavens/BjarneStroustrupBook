/*
    Вычислите общую сумму заказов в двух файлах из предыдущего упражнения. Значения для отдельного объекта
    класса Purchase (разумеется) равно unit_price*count.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <cstdint>

const std::map<uint8_t,uint8_t> daysInMonth {
    {1,31}, {2,28}, {3,31}, {4,30}, {5,31}, {6,30},
    {7,31}, {8,31}, {9,30}, {10,31}, {11,30}, {12,31} };

struct Purchase
{
    std::string name;
    double unitPrice;
    uint32_t count;
};

struct Order
{
    std::string name;
    std::string address;
    std::string dateOfBirth; // формат dd-mm-yyyy
    std::vector<Purchase> purchases;
    
    bool operator<(const Order& other) const {
        return name < other.name;
    }
};

std::ifstream& operator>>(std::ifstream& ifs, Purchase& pur)
{
    char ch;
    ifs >> ch;
    if (ch != '{')
    {
        ifs.unget();
        ifs.clear(std::ios_base::failbit);
        return ifs;
    }
    
    std::string n;
    double u;
    uint32_t c;
    ifs >> n >> u >> c;
    pur.name = n;
    pur.unitPrice = u;
    pur.count = c;
    
    ifs >> ch;
    if (ch != '}')
    {
        std::cout << "Неправильное окончание ввода!\n";
        exit(1);
    }
    
    return ifs;
}

bool LeapYear(uint16_t year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    }
    return false;
}

bool CorrectDate(const std::string& date)
{
    if (!(date.length() == 10 && date[2] == '-' && date[5] == '-'))
    {
        return false;
    }
    // Убираем символы '-' из нашей даты
    std::string newDate = date.substr(0,2) + ' ' + date.substr(3,2) + ' ' + date.substr(6,4);
    std::stringstream ss{newDate};
    uint16_t day;
    uint16_t month;
    uint16_t year;
    ss >> day >> month >> year;
    
    if (month == 0 || month > 12 || day == 0
        || !((month == 2 && LeapYear(year) && day <= ((*daysInMonth.find(month)).second + 1))
        || (day <= (*daysInMonth.find(month)).second)))
    {
        return false;
    }
    
    return true;
}

std::ifstream& operator>>(std::ifstream& ifs, Order& order)
{
    char ch;
    ifs >> ch;
    if (ch != '{')
    {
        ifs.unget();
        ifs.clear(std::ios_base::failbit);
        return ifs;
    }
    
    std::string n;
    std::string a;
    std::string d;
    
    ifs >> n >> a >> d;
    order.name = n;
    order.address = a;
    order.dateOfBirth = d;
    
    // Функция для обработки dateOfBirth
    if (!CorrectDate(d))
    {
        std::cout << "Некорректная дата!\n";
        exit(1);
    }
    
    if (!ifs)    // Разобрать случаи, когда такое может произойти
    {
        std::cout << "Некорректные данные!\n";
        exit(1);
    }
    
    ifs >> ch;
    if (ch != '[')
    {
        std::cout << "Некорректное начало ввода!\n";
        exit(1);
    }
    
    while(true)
    {
        Purchase p;
        if (!(ifs >> p)) { break; }
        order.purchases.push_back(p);
    }
    
    if (ifs.fail()) {
        ifs.clear();
    }
    ifs >> ch;
    if (ch != ']') {
        std::cout << "Некорректное окончание ввода!\n";
        exit(1);
    }
    ifs >> ch;
    if (ch != '}') {
        std::cout << "Некорректное окончание ввода!\n";
        exit(1);
    }
    
    return ifs;
}

int main()
{
    double total = 0;
    std::vector<Order> orders;

    std::ifstream ifs{"data.txt"};
    while(true)
    {
        Order ord;
        if (!(ifs >> ord)) break;
        orders.push_back(ord);
    }
    ifs.close();
    ifs.open("data2.txt");
    while(true)
    {
        Order ord;
        if (!(ifs >> ord)) break;
        orders.push_back(ord);
    }
    ifs.close();
    
    for (Order ord : orders)
    {
        for (Purchase pur : ord.purchases)
        {
            total += pur.unitPrice*pur.count;
        }
    }
    
    std::cout << "Общая сумма заказов: " << total << '\n';
    
    return 0;
}
