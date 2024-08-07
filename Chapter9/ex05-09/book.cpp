#include <iostream>
#include "book.h"

constexpr int REQUIRED_LENGTH_OF_ISBN = 7;

bool CheckCorrectOfISBN(const std::string& ISBNcode);

Book::Book(std::string ISBNcode, std::string nameOfBook, std::string surnameOfAuthor,
           Date dateOfRegistration, bool handedOut, Genre genre)
    : ISBNcode{ISBNcode}, nameOfBook{nameOfBook}, surnameOfAuthor{surnameOfAuthor}, dateOfRegistration{dateOfRegistration},
    handedOut{handedOut}, genre{genre}
{
    try
    {
        std::vector<std::string> resultOfSplit;
        bool correct = CheckCorrectOfISBN(ISBNcode);
        if (!correct) throw std::invalid_argument("Введён некорректный ISBN код!");
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << '\n';
        exit(1);
    }
}

std::string Book::GetISBNcode() const { return ISBNcode; }
std::string Book::GetNameOfBook() const { return nameOfBook; }
std::string Book::GetSurnameOfAuthor() const { return surnameOfAuthor; }
Date Book::GetDateOfRegistration() const { return dateOfRegistration; }
bool Book::GetHandedOut() const { return handedOut; }
Genre Book::GetGenre() const { return genre; }

bool CheckCorrectOfISBN(const std::string& ISBNcode)
{
    if (ISBNcode.length() != REQUIRED_LENGTH_OF_ISBN)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < REQUIRED_LENGTH_OF_ISBN; ++i)
        {
            switch(i)
            {
                case 0: case 2: case 4:
                    if (!(ISBNcode[i] >= '0' && '9' >= ISBNcode[i]))
                    {
                        return false;
                    }
                    break;

                case 1: case 3: case 5:
                    if (ISBNcode[i] != '-')
                    {
                        return false;
                    }
                    break;

                case 6:
                    if (!((ISBNcode[i] >= 'a' && 'z' >= ISBNcode[i])
                    || (ISBNcode[i] >= 'A' && 'Z' >= ISBNcode[i])
                    || (ISBNcode[i] >= '0' && '9' >= ISBNcode[i])))
                    {
                        return false;
                    }
                    break;
            }
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, Book book)
{
    os << "Название книги: " << book.GetNameOfBook() << '\n'
    << "Фамилия автора: " << book.GetSurnameOfAuthor() << '\n'
    << "ISBN код: " << book.GetISBNcode();
    return os;
}

bool operator==(const Book& firstBook, const Book& secondBook)
{
    return firstBook.GetISBNcode() == secondBook.GetISBNcode();
}

bool operator!=(const Book& firstBook, const Book& secondBook)
{
    return !(firstBook==secondBook);
}
