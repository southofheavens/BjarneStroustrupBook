#include <iostream>
#include <cmath>
#include "rational.h"

Rational::Rational() {}
Rational::Rational(int n, int d) : numerator{n}, denominator{d} 
{
    if (d == 0)
    {
        throw Invalid{};
    }
    if (numerator <= 0 && denominator < 0)
    {
        numerator = abs(numerator);
        denominator = abs(denominator);
    }
}

double Rational::ConvertToDouble()
{
    double num = (double)numerator / denominator;
    return num;
}


std::ostream& operator<<(std::ostream& os, const Rational& rational)
{
    return os << rational.numerator << '/' << rational.denominator;
}

std::istream& operator>>(std::istream& is, Rational& rational)
{
    int n;
    int d;
    char ch;
    is >> n >> ch >> d;
    if (!is) return is;
    if (ch != '/')
    {
        is.clear(std::ios_base::failbit);
        return is;
    }
    rational = Rational{n, d};
    return is;
}

void ConvertNumber(Rational& number)
{
    while (number.denominator != 1)
    {
        bool anyOperation = false;
        for (int i = 2; i <= 100; ++i)
        {
            if (number.numerator % i == 0 && number.denominator % i == 0)
            {
                number.numerator /= i;
                number.denominator /= i;
                anyOperation = true;
            }
        }
        if (!anyOperation) break;
    }
    if (number.numerator <= 0 && number.denominator < 0)
    {
        number.numerator = abs(number.numerator);
        number.denominator = abs(number.denominator);
    }
}

Rational operator+(const Rational& first, const Rational& second)
{
    Rational number;
    if (first.denominator == second.denominator)
    {
        number.denominator = first.denominator;
        number.numerator = first.numerator + second.numerator;
    }
    else
    {
        number.numerator = first.numerator * second.denominator + second.numerator * first.denominator;
        number.denominator = first.denominator * second.denominator;
    }
    ConvertNumber(number);
    return number;
}

Rational operator-(const Rational& first, const Rational& second)
{
    Rational number;
    if (first.denominator == second.denominator)
    {
        number.denominator = first.denominator;
        number.numerator = first.numerator - second.numerator;
    }
    else
    {
        number.numerator = first.numerator * second.denominator - second.numerator * first.denominator;
        number.denominator = first.denominator * second.denominator;
    }
    ConvertNumber(number);
    return number;
}

Rational operator*(const Rational& first, const Rational& second)
{
    Rational number;
    number.numerator = first.numerator * second.numerator;
    number.denominator = first.denominator * second.denominator;
    ConvertNumber(number);
    return number;
}

Rational operator/(const Rational& first, const Rational& second)
{
    Rational number;
    number.numerator = first.numerator * second.denominator;
    number.denominator = second.numerator * first.denominator;
    ConvertNumber(number);
    return number;
}

bool operator==(const Rational& first, const Rational& second)
{
    Rational firstNumber = first;
    Rational secondNumber = second;
    ConvertNumber(firstNumber);
    ConvertNumber(secondNumber);
    if (firstNumber.numerator == secondNumber.numerator
        && firstNumber.denominator == secondNumber.denominator)
    {
        return true;
    }
    else
    {
        return false;
    }
}

