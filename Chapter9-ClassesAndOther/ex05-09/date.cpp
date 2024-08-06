#include <iostream>
#include "date.h"

std::vector<std::string> const months {"January", "February", "March", "April", "May", "June",
                                "Jule", "August", "September", "October", "November", "December"};



Date::Date(int y, Month m, int d)
{
    if (!IsValid(y, m, d)) throw Invalid{};
    daysFromZeroDay += (y - 1970) * 365;
    for (int i = 1970; i <= y; ++i)
    {
        if (LeapYear(i))
        {
            daysFromZeroDay++;
        }
    }
    switch (m)
    {
        case Month::dec: daysFromZeroDay += 30;
        case Month::nov: daysFromZeroDay += 31;
        case Month::oct: daysFromZeroDay += 30;
        case Month::sep: daysFromZeroDay += 31;
        case Month::aug: daysFromZeroDay += 31;
        case Month::jul: daysFromZeroDay += 30;
        case Month::jun: daysFromZeroDay += 31;
        case Month::may: daysFromZeroDay += 30;
        case Month::apr: daysFromZeroDay += 31;
        case Month::mar: daysFromZeroDay += 28;
        case Month::feb: daysFromZeroDay += 31;
        case Month::jan: //LeapYear(y) ? daysFromZeroDay += d - 2 : daysFromZeroDay += d - 1;
            if ((int)m == 2 && LeapYear(y))
            {
                daysFromZeroDay += d - 2;
            }
            else
            {
                daysFromZeroDay += d - 1;
            }
    }
    
}

Date::Date() {}

int Date::GetYear() const
{
    int year = 1970;
    int64_t thisDaysFromZeroDay = GetDaysFromZeroDay();
    while (thisDaysFromZeroDay > 365)
    {
        if (!LeapYear(year)) { thisDaysFromZeroDay-=365; }
        else { thisDaysFromZeroDay-=366; }
        
        year++;
    }
    return year;
}

Month Date::GetMonth() const
{
    int year = 1970;
    int64_t thisDaysFromZeroDay = GetDaysFromZeroDay();
    while (thisDaysFromZeroDay > 365)
    {
        if (!LeapYear(year)) { thisDaysFromZeroDay-=365; }
        else { thisDaysFromZeroDay-=366; }
        year++;
    }
    int month = 0;
    for (int i = 1; i <= 12; ++i)
    {
        switch (i)
        {
            case 2: 
                LeapYear(year) ? thisDaysFromZeroDay -= 29 : thisDaysFromZeroDay -= 28;
                break;

            case 4: case 6: case 9: case 11: 
                thisDaysFromZeroDay -= 30;
                break;
                
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                thisDaysFromZeroDay -= 31;
                break;
        }
        month++;
        if (month == 13) { month = 1; }
        if (thisDaysFromZeroDay < 0) { break; }
        else if (thisDaysFromZeroDay == 0) { month++; if (month == 13) { month = 1; } break; }
    }
    return (Month)month;
}

int Date::GetDay() const
{
    int year = 1970;
    int64_t thisDaysFromZeroDay = GetDaysFromZeroDay();
    while (thisDaysFromZeroDay > 365)
    {
        if (!LeapYear(year)) { thisDaysFromZeroDay-=365; }
        else { thisDaysFromZeroDay-=366; }
        year++;
    }
    for (int i = 1; i <= 12; ++i)
    {
        switch (i)
        {
            case 2:
                LeapYear(year) ? thisDaysFromZeroDay -= 29 : thisDaysFromZeroDay -= 28;
                if (thisDaysFromZeroDay < 0)
                {
                    if (LeapYear(year))
                    {
                        return (int)thisDaysFromZeroDay + 30;
                    }
                    else
                    {
                        return (int)thisDaysFromZeroDay + 29;
                    }
                }
                else if (thisDaysFromZeroDay == 0)
                {
                    return 1;
                }
                break;

            case 4: case 6: case 9: case 11:
                thisDaysFromZeroDay -= 30;
                if (thisDaysFromZeroDay < 0)
                {
                    return (int)thisDaysFromZeroDay + 31;
                }
                else if (thisDaysFromZeroDay == 0)
                {
                    return 1;
                }
                break;
                
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                thisDaysFromZeroDay -= 31;
                if (thisDaysFromZeroDay < 0)
                {
                    return (int)thisDaysFromZeroDay + 32;
                }
                else if (thisDaysFromZeroDay == 0)
                {
                    return 1;
                }
                break;
        }
    }
    return 0;
}

int64_t Date::GetDaysFromZeroDay() const { return daysFromZeroDay; }


void Date::AddDay(int n)
{
    daysFromZeroDay += n;
}

void Date::AddMonth(int n)
{
    while (n != 0)
    {
        int month = (int)GetMonth();
        switch (month)
        {
            case 2:
                LeapYear(GetYear()) ? daysFromZeroDay += 29 : daysFromZeroDay += 28;
                n--;
                break;
                
            case 4: case 6: case 9: case 11:
                daysFromZeroDay += 30;
                n--;
                break;
            
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                daysFromZeroDay += 31;
                n--;
                break;
        }
    }
}

void Date::AddYear(int n)
{
    while (n != 0)
    {
        LeapYear(GetYear() + 1) ? daysFromZeroDay += 366 : daysFromZeroDay += 365;
        n--;
    }
}

Day DayOfWeek(const Date& d)
{
    int64_t dayOfWeek = d.daysFromZeroDay % 7;
    switch (dayOfWeek)
    {
        case 0: return Day::thursday;
        case 1: return Day::friday;
        case 2: return Day::saturday;
        case 3: return Day::sunday;
        case 4: return Day::monday;
        case 5: return Day::tuesday;
        default: return Day::wednesday;
    }
}

Date NextMonday(const Date& d)
{
    Day currDay = DayOfWeek(d);
    Date date = d;
    switch (currDay)
    {
        case Day::monday: date.AddDay(7); return date;
        case Day::tuesday: date.AddDay(6); return date;
        case Day::wednesday: date.AddDay(5); return date;
        case Day::thursday: date.AddDay(4); return date;
        case Day::friday: date.AddDay(3); return date;
        case Day::saturday: date.AddDay(2); return date;
        case Day::sunday: date.AddDay(1); return date;
    }
}

Date NextWeekday(const Date& d)
{
    Day currDay = DayOfWeek(d);
    Date date = d;
    switch (currDay)
    {
        case Day::monday: date.AddDay(5); return date;
        case Day::tuesday: date.AddDay(4); return date;
        case Day::wednesday: date.AddDay(3); return date;
        case Day::thursday: date.AddDay(2); return date;
        case Day::friday: date.AddDay(1); return date;
        case Day::saturday: date.AddDay(1); return date;
        case Day::sunday: date.AddDay(6); return date;
    }
}

Date NextWorkday(const Date& d)
{
    Day currDay = DayOfWeek(d);
    Date date = d;
    switch (currDay)
    {
        case Day::monday: date.AddDay(1); return date;
        case Day::tuesday: date.AddDay(1); return date;
        case Day::wednesday: date.AddDay(1); return date;
        case Day::thursday: date.AddDay(1); return date;
        case Day::friday: date.AddDay(3); return date;
        case Day::saturday: date.AddDay(2); return date;
        case Day::sunday: date.AddDay(1); return date;
    }
}

int WeekOfYear(const Date& d)
{
    int year = 1970;
    int64_t thisDaysFromZeroDay = d.GetDaysFromZeroDay();
    while (thisDaysFromZeroDay > 365)
    {
        if (!LeapYear(year)) { thisDaysFromZeroDay-=365; }
        else { thisDaysFromZeroDay-=366; }
        year++;
    }
    // вроде бы високосность учитывать не надо
    return (int)(thisDaysFromZeroDay / 7 + 1);
}

bool IsValid(int y, Month m, int d)
{
    if (y < 1970) return false; // наша эра
    if (d <= 0) return false; // d должно быть положительным
    if (m < Month::jan || Month::dec < m) return false;
    
    int daysInMonth; // в месяце не более 31 дня
    switch (m)
    {
        case Month::feb:
            daysInMonth = LeapYear(y) ? 29 : 28;
            break;
        case Month::apr: case Month::jun:
        case Month::sep: case Month::nov:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
            break;
    }
    if (d > daysInMonth) return false;
    return true;
}

bool LeapYear(int y) // true для високосного года
{
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0 && y % 100 == 0))
    {
        return true;
    }
    return false;
}

bool operator==(const Date& a, const Date& b)
{
    return a.GetDaysFromZeroDay() == b.GetDaysFromZeroDay();
}

bool operator!=(const Date& a, const Date& b)
{
    return !(a==b);
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    return os << '(' << date.GetYear()
        << ',' << months[int(date.GetMonth()) - 1]
        << ',' << date.GetDay() << ')';
}

std::istream& operator>>(std::istream& is, Date& dd)
{
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if (!is) return is;
    if (ch1 != '(' || ch2 != ',' ||
        ch3 != ',' || ch4 != ')')
    {
        is.clear(std::ios_base::failbit);
        return is;
    }
    dd = Date(y, Month(m), d);
    return is;
}
