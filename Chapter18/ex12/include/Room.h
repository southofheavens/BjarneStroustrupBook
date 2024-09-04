enum class Enemies {None, Vampus, Bat, Pit};

class Room
{
public:
    Room(unsigned int n, Room* prev = nullptr)  // Номер комнаты и указатель на предыдущую комнату
    : firstRoom{nullptr}, secondRoom{nullptr}, thirdRoom{prev},
    numOfRoom{n}, enemy{Enemies::None} {}
        
    void SetFirst(Room* r) { firstRoom = r; }
    void SetSecond(Room* r) { secondRoom = r; }
    void SetThird(Room* r) { thirdRoom = r; }
    void SetEnemy(Enemies en) { enemy = en; }
    
    Room* GetFirst() const { return firstRoom; }
    Room* GetSecond() const { return secondRoom; }
    Room* GetThird() const { return thirdRoom; }
    unsigned int GetNumOfRoom() const { return numOfRoom; }
    Enemies GetEnemy() const { return enemy; }
private:
    Room* firstRoom;
    Room* secondRoom;
    Room* thirdRoom;
    
    unsigned int numOfRoom;
    Enemies enemy;
};
