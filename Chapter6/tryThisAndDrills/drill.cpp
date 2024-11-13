/*
 * Это задание связано с рядом модификаций программы с ошибками, которые превратят довольно бесполезный
 * код в полезную программу.
 *
 * 1. Откройте файл calculator02buggy.cpp. Скомпилируйте его. Найдите и исправьте несколько ошибок.
 * Этих ошибок в тексте книги нет. Найдите три логические ошибки, специально вставленные в calculator02buggy.cpp,
 * и удалите их, чтобы калькулятор давал верные результаты.
 *
 * 2. Измените символ команды выхода с q на x.
 *
 * 3. Измените символ команды вывода с ; на =.
 *
 * 4. Добавьте в функцию main() приветствие.
 * "Добро пожаловать в программу-калькулятор!
 * Вводите выражения с числами с плавающей точкой."
 *
 * 5. Усовершенствуйте это приветствие, указав, какие операторы можно использовать, как выводить результаты
 * на экран и как выйти из программы.
 */

//#include "../std_lib_facilities.h"
#include <iostream>

//------------------------------------------------------------------------------

class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) //error("putback() into a full buffer");
    {
        std::cout << "putback() into a full buffer\n";
        exit(-1);
    }
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    std::cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '9':
    {
        std::cin.putback(ch);         // put digit back into the input stream
        double val;
        std::cin >> val;              // read a floating-point number
        return Token('8', val);   // let '8' represent "a number"
    }
    default:
        //error("Bad token");
        std::cout << "Bad token\n";
        exit(-1);
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback()

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') //error("')' expected);
        {
            std::cout << "')' expected\n";
            exit(-1);
        }
        return d;
    }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        //error("primary expected");
        std::cout << "primary expected\n";
        exit(-1);
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) //error("divide by zero");
            {
                std::cout << "divide by zero\n";
                exit(-1);
            }
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    std::cout << "Добро пожаловать в программу-калькулятор!\n";
    std::cout << "Вводите выражения с числами с плавающей точкой.\n";
    std::cout << "Вы можете использовать такие операторы, как: +, -, * и /.\n";
    std::cout << "Для вывода результата введите '=', для выхода введите 'x'\n";
    while (std::cin) {
        double val = expression();
        Token t = ts.get();

        if (t.kind == 'x') break; // 'x' for quit
        if (t.kind == '=')        // '=' for "print now"
            std::cout << "=" << val << '\n';
        else
            ts.putback(t);
    }
    //keep_window_open();
}
catch (std::exception& e) {
    std::cerr << "error: " << e.what() << '\n';
    //keep_window_open();
    return 1;
}
catch (...) {
    std::cerr << "Oops: unknown exception!\n";
    //keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------
