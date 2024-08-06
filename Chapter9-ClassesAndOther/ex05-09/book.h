#include <string>
#include <vector>
#include "date.h"

enum class Genre {Фантастика, Проза, Периодические_Издания, Биография, Детская_Литература};

class Book
{
public:
    Book(std::string ISBNcode, std::string nameOfBook, std::string surnameOfAuthor,
               Date dateOfRegistration, bool handedOut, Genre genre);
    std::string GetISBNcode() const;
    std::string GetNameOfBook() const;
    std::string GetSurnameOfAuthor() const;
    Date GetDateOfRegistration() const;
    bool GetHandedOut() const;
    Genre GetGenre() const;
    
private:
    std::string nameOfBook;
    std::string surnameOfAuthor;
    Date dateOfRegistration;
    std::string ISBNcode;
    Genre genre;
    bool handedOut;
};

std::ostream& operator<<(std::ostream& os, Book book);
bool operator==(const Book& firstBook, const Book& secondBook);
bool operator!=(const Book& firstBook, const Book& secondBook);
