#include <string>

struct Link
{
    struct Link* prev;
    struct Link* succ;
};

struct Name
{
    struct Link lnk;
    std::string n;
    
    Name(std::string nn) : n{nn} {}
};

Name* MakeName(std::string n);

class List
{
private:
    Link* head;
    Link* tail;
    
public:
    List();
    ~List();
    
    Link* Head() { return head; }
    
    void PushBack(Link* p);
    Link* Erase(Link* p);
};
