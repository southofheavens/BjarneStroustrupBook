/*
    Определите класс Order (заказ), члены которого содержат имя клиента, его адрес, дату рождения и контейнер
    vector<Purchase>. Класс Purchase должен содержать поля name, unit_price и count, характеризующие товар.
    Определите механизм чтения из файла и записи в файл объектов класса Order. Определите механизм для вывода
    на экран объектов класса Order. Создайте файл, содержащий по крайней мере десять объектов класса Order,
    считайте его в контейнер vector<Order>, отсортируйте по имени клиента и запишите обратно в файл.
    Создайте другой файл, содержащий по крайней мере десять объектов класса Order, примерно треть из которых
    хранится в первом файле, считайте их в контейнер list<Order>, отсортируйте по адресам (клиента) и запишите
    обратно в файл. Объедините эти два файла в третий, используя функцию std::merge().
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <list>
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

std::ofstream& operator<<(std::ofstream& ofs, const Order& ord)
{
    ofs << "{ " << ord.name << ' ' << ord.address << ' ' << ord.dateOfBirth << ' ';
    ofs << "\n\t[ ";
    for (const Purchase& pur : ord.purchases)
    {
        ofs << "{ " << pur.name << ' ' << pur.unitPrice << ' ' << pur.count << " } ";
    }
    ofs << "] }\n";
    return ofs;
}

std::ostream& operator<<(std::ostream& os, const Order& ord)
{
    os << ord.name << ' ' << ord.address << ' ' << ord.dateOfBirth << ' ';
    os << "\n\t";
    for (const Purchase& pur : ord.purchases)
    {
        os << pur.name << ' ' << pur.unitPrice << ' ' << pur.count << "\n\t";
    }
    return os;
}

int main()
{
    std::ifstream ifs{"data.txt"};
    std::vector<Order> ordersVec;
    
    while(true)
    {
        Order ord;
        if (!(ifs >> ord)) break;
        ordersVec.push_back(ord);
    }
    ifs.close();
    
    std::sort(ordersVec.begin(),ordersVec.end(),[](Order f, Order s){return f.name < s.name;});
    
    std::ofstream ofs{"data.txt"};
    for (Order ord : ordersVec) {
        ofs << ord;
    }
    ofs.close();
    
    ifs.open("data2.txt");
    std::list<Order> ordersList;
    
    while(true)
    {
        Order ord;
        if (!(ifs >> ord)) break;
        ordersList.push_back(ord);
    }
    ifs.close();
    
    ordersList.sort([](Order f, Order s){return f.address < s.address;});
    
    ofs.open("data2.txt");
    for (Order ord : ordersList) {
        ofs << ord;
    }
    ofs.close();
    
    std::vector<Order> merged(ordersVec.size()+ordersList.size());
    std::merge(ordersVec.begin(),ordersVec.end(),ordersList.begin(),ordersList.end(),merged.begin());
    
    ofs.open("mergeDatas.txt");
    for (Order ord : merged)
    {
        std::cout << ord << '\n';
        ofs << ord;
    }
    ofs.close();
    
    return 0;
}
