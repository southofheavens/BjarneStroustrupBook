#include "book.h"
#include "patron.h"

struct Transaction
{
    Book book;
    Patron patron;
    Date date;
};

class Library
{
public:
    void AddBook(std::string ISBNcode, std::string nameOfBook, std::string surnameOfAuthor,
               Date dateOfRegistration, bool handedOut, Genre genre);
    void AddPatron(std::string username, int numOfLibCard, int membershipFeeAmount);
    bool IsBookBusy(std::string ISBNcode);
private:
    std::vector<Book> books;
    std::vector<Patron> patrons;
    std::vector<Transaction> transactions;
};
