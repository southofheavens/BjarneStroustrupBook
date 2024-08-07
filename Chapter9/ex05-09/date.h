#include <string>
#include <vector>

enum class Month {jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
enum class Day {sunday=1, monday, tuesday, wednesday, thursday, friday, saturday}; // (1970,1,1) - Thursday

class Date
{
public:
    class Invalid{}; // используется для исключения
    Date(int y, Month m, int d);
    Date(); // конструктор по умолчанию
    
    void AddDay(int n); // добавляет к текущему числу n дней
    void AddMonth(int n); // добавляет к текущему числу n месяцев
    void AddYear(int n); // добавляет к текущему числу n лет
            
private:
    int64_t daysFromZeroDay {0};
    
    int GetYear() const;
    Month GetMonth() const;
    int GetDay() const;
    int64_t GetDaysFromZeroDay() const;
    
    friend bool operator==(const Date& a, const Date& b);
    friend bool operator!=(const Date& a, const Date& b);
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    
    friend Day DayOfWeek(const Date& d); // возвращает день недели
    friend Date NextMonday(const Date& d); // возвращает следующий понедельник
    friend Date NextWeekday(const Date& d); // возвращает следующий выходной день
    friend Date NextWorkday(const Date& d); // возвращает следующий рабочий день
    friend int WeekOfYear(const Date& d); // возвращает номер месяца в году
};


bool LeapYear(int y); // true для високосного года
bool IsValid(int y, Month m, int d); // проверяет дату на корректность
bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);
std::ostream& operator<<(std::ostream& os, const Date& date);
std::istream& operator>>(std::istream& is, Date& dd);
