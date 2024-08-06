class Rational
{
public:
    class Invalid{};
    Rational();
    Rational(int n, int d);
    double ConvertToDouble();
    
private:
    int numerator;
    int denominator;
    
    friend std::ostream& operator<<(std::ostream& os, const Rational& rational);
    friend std::istream& operator>>(std::istream& is, Rational& rational);
    friend void ConvertNumber(Rational& number);
    friend Rational operator+(const Rational& first, const Rational& second);
    friend Rational operator-(const Rational& first, const Rational& second);
    friend Rational operator*(const Rational& first, const Rational& second);
    friend Rational operator/(const Rational& first, const Rational& second);
    friend bool operator==(const Rational& first, const Rational& second);
};
