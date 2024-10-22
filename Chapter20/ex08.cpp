/*
    Напишите функцию, подсчитывающую количество символов в объекте класса Document.

    Как я понял, нужно подсчитать количество символов, не включая пробелы и символы перехода на новую строку.
*/

#include <iostream>
#include <vector>
#include <list>

using Line = std::vector<char>;

// ------------------------------

class TextIterator
{
private:
    // Отслеживает строку и позицию символа в строке
    std::list<Line>::iterator ln;
    Line::iterator pos;
public:
    // Устанавливает итератор на позицию pp в ll-й строке
    TextIterator(std::list<Line>::iterator ll, Line::iterator pp)
        : ln{ll}, pos{pp} {}
    char& operator*() { return *pos; }
    TextIterator& operator++();
    
    bool operator==(const TextIterator& other) const
    {
        return ln==other.ln && pos == other.pos;
    }
    bool operator!=(const TextIterator& other) const
    {
        return !(*this==other);
    }
    
    Line& GetLine() const { return *ln; }
    Line::iterator GetPos() const { return pos; }
};

TextIterator& TextIterator::operator++()
{
    ++pos;                      // Переход к новому символу
    if (pos==(*ln).end())
    {
        ++ln;                   // Переход на новую строку
        pos = (*ln).begin();
    }
    return *this;
}

// ------------------------------

class Document
{
private:
    std::list<Line> line;
public:
    Document() { line.push_back(Line{}); }
    
    TextIterator begin()
    {
        return TextIterator(line.begin(), (*line.begin()).begin());
    }
    
    TextIterator end()
    {
        std::list<Line>::iterator first = line.end();
        first--; // Вот этой строчки в примере из книги не было,
                 // но без неё код не работает
        std::vector<char>::iterator last = (*first).end();
        return TextIterator(first, last);
    }
    
    std::list<Line>& GetText() { return line; }
    
    void SearchAndReplace(const std::string& s, const std::string& r);
};

std::istream& operator>>(std::istream& is, Document& d)
{
    for (char ch; is.get(ch); )
    {
        d.GetText().back().push_back(ch);    // Добавление символа
        if (ch == '\n') {
            d.GetText().push_back(Line{});   // Добавление строки
        }
    }
    if (d.GetText().back().size()) {         // Добавление последней
        d.GetText().push_back(Line{});       // пустой строки
    }
    return is;
}

// ------------------------------

template<typename Iter1, typename Iter2>
bool Match(Iter1 f1, Iter1 e1, Iter2 f2, Iter2 e2)
{
    while (f1 != e1 && f2 != e2)
    {
        if (*f1 != *f2) {
            return false;
        }
        ++f1;
        ++f2;
    }
    return true;
}

TextIterator FindTxt(TextIterator first, TextIterator last, const std::string& s)
{
    if (s.size() == 0) return last;
    char firstChar = s[0];
    while (true)
    {
        auto p = std::find(first,last,firstChar);
        if (p == last || Match(p,last,s.begin(),s.end())) return p;
        first = ++p;
    }
}

// for ex06
void Document::SearchAndReplace(const std::string& s, const std::string& r)
{
    TextIterator entry = FindTxt(begin(),end(),s);
    if (entry == end())
    {
        std::cout << "Вхождение не найдено!\n";
        return;
    } else
    {
        Line& entryLine = entry.GetLine();
        
        const int diff = int(r.length() - s.length());
        if (diff > 0 && (entryLine.size() + diff) > entryLine.capacity())
        {
            entryLine.reserve(entryLine.size()+diff);
            // Повторно находим вхождение после перераспределения памяти
            entry = FindTxt(begin(),end(),s);
        }
         
        Line::iterator it = entry.GetPos();
        
        entryLine.erase(it,it+s.size());
        
        for (std::string::const_iterator its = r.cbegin(); its != r.cend(); ++its, ++it)
        {
            entryLine.insert(it,*its);
        }
    }
}

// ------------------------------

// for ex08

// По-хорошему, здесь должно быть const Document& d,
// но для этого нужно создавать отдельный константный итератор
uint32_t CountOfLetters(Document& d)
{
    uint32_t countOfLetters = 0;
    for (auto l : d)
    {
        if (!(isspace(l)))
        {
            countOfLetters++;
        }
    }
    return countOfLetters;
}

// ------------------------------

int main()
{
    Document d;
    std::cin >> d;
    
    std::cout << "----------\n";
    for (auto l : d) { std::cout << l; }
    std::cout << "----------\n";
    
    d.SearchAndReplace("dog", "doggy");
    
    for (auto l : d) { std::cout << l; }
    std::cout << "----------\n";
    
    std::cout << CountOfLetters(d) << '\n';
    
    return 0;
}
