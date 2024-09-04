#include "../include/Game.h"

// Было бы лучше, если бы я сделал отдельный класс для пещеры и поместил эту переменную туда,
// но в целом и так нормально
bool run = true;

Room* CaveGen()
{
    Room* room = new Room{1}; // Первая комната
    Room* firstRoom = room;   // Для связки первой комнаты с двадцатой
    
    room = new Room{2, room};   // 2 -> 1
    room->GetThird()->SetFirst(room);   // 1 -> 2
    
    room = new Room{3, room};   // 3 -> 2
    room->GetThird()->SetSecond(room);   // 2 -> 3
    room->SetFirst(room->GetThird()->GetThird());   // 3 -> 1
    room->GetFirst()->SetThird(room);  // 1 -> 3
    
    room = new Room{4,room->GetThird()};    // 4 -> 2
    room->GetThird()->SetFirst(room);   // 2 -> 4
    
    for(unsigned int i = 5; i <= 20; ++i)
    {
        if(i % 2 == 1)
        {
            room = new Room{i, room};
            room->GetThird()->SetSecond(room);
            room->SetFirst(room->GetThird()->GetThird()->GetSecond());
            room->GetFirst()->SetSecond(room);
        }
        else
        {
            room = new Room{i,room->GetThird()};
            room->GetThird()->SetFirst(room);
        }
    }
    
    room->SetFirst(room->GetThird()->GetSecond());  // 20 -> 19
    room->GetFirst()->SetSecond(room);  // 19 -> 20
    room->SetSecond(firstRoom); // 20 -> 1
    firstRoom->SetSecond(room); // 1 -> 20
    
    room = firstRoom;
    
    return room;
}

bool FindRoom(const std::vector<RoomEnemy>& vec, int numOfRoom)
{
    for (RoomEnemy el : vec) {
        if (el.numOfRoom == numOfRoom) { return true; }
    }
    return false;
}

std::vector<RoomEnemy> EnemiesGen()
{
    // Первый элемент - вампус, второй и третий - ямы,
    // четвертый и пятый - летучие мыши.
    std::vector<RoomEnemy> enemies(5);
    for (int i = 0; i < enemies.size(); ++i)
    {
        unsigned int numOfRoom = rand() % 20 + 1;
        while(FindRoom(enemies,numOfRoom)) {
            numOfRoom = rand() % 20 + 1;
        }
        switch(i)
        {
            case 0:
                enemies[i] = {Enemies::Vampus, numOfRoom};
                break;
            case 1: case 2:
                enemies[i] = {Enemies::Bat, numOfRoom};
                break;
            case 3: case 4:
                enemies[i] = {Enemies::Pit, numOfRoom};
                break;
        }
    }
    return enemies;
}

void CaveInit(Room* firstRoom)
{
    std::vector<RoomEnemy> enemies = EnemiesGen();
    // Проходимся по каждой из комнат пещеры, чтобы расставить там врагов
    for(int i = 0; i < enemies.size(); ++i)
    {
        for(int j = 0; j < 20; ++j)
        {
            if (enemies[i].numOfRoom == firstRoom->GetNumOfRoom())
            {
                firstRoom->SetEnemy(enemies[i].enemy);
            }
            firstRoom = firstRoom->GetFirst();
        }
    }
}

Room* StartRoom()
{
    Room* firstRoom = CaveGen();
    CaveInit(firstRoom);
    while(true)
    {
        unsigned int numOfRoom = rand() % 20 + 1;
        for (int i = 0; i < 20; ++i)
        {
            if(firstRoom->GetNumOfRoom() == numOfRoom
               && (int)firstRoom->GetEnemy() == 0)
            {
                return firstRoom;
            }
            else if(firstRoom->GetNumOfRoom() == numOfRoom
                    && (int)firstRoom->GetEnemy() != 0)
            {
                break;
            }
            firstRoom = firstRoom->GetFirst();
        }
    }
}

Enemies CheckEnemy(Room* room)
{
    switch(room->GetEnemy())
    {
        case Enemies::Vampus:
            return Enemies::Vampus;
            break;
        case Enemies::Bat:
            return Enemies::Bat;
            break;
        case Enemies::Pit:
            return Enemies::Pit;
            break;
        case Enemies::None:
            return Enemies::None;
            break;
    }
}

void WarnAboutEnemies(const std::vector<Room*>& nearbyRooms)
{
    bool wasVampus = false;
    bool wasBat = false;
    bool wasPit = false;
    for (int i = 0; i < nearbyRooms.size(); ++i)
    {
        switch(CheckEnemy(nearbyRooms[i]))
        {
            case Enemies::Vampus:
                if (!wasVampus)
                {
                    std::cout << "\nЯ ЧУВСТВУЮ ОТВРАТИТЕЛЬНЫЙ ЗАПАХ...\n";
                    wasVampus = true;
                }
                break;
            case Enemies::Bat:
                if (!wasBat)
                {
                    std::cout << "\nЯ СЛЫШУ ЛЕТУЧУЮ МЫШЬ...\n";
                    wasBat = true;
                }
                break;
            case Enemies::Pit:
                if (!wasPit)
                {
                    std::cout << "\nЯ ЧУВСТВУЮ СКВОЗНЯК...\n";
                    wasPit = true;
                }
                break;
            case Enemies::None:
                break;
        }
    }
    std::cout << '\n';
}

Room* MessAboutEnemy(Room* room)
{
    Enemies enemy = CheckEnemy(room);
    if (enemy == Enemies::Vampus)
    {
        std::cout << "*** ВЫ ЗАШЛИ В КОМНАТУ С ВАМПУСОМ И РАЗБУДИЛИ ЕГО ***\n";
        std::cout << "*** ОН ВИДИТ ВАС, НАБРАСЫВАЕТСЯ И ПОЖИРАЕТ ***\n\n";
        run = false;
    }
    else if (enemy == Enemies::Bat)
    {
        std::cout << "*** ВЫ ЗАШЛИ В КОМНАТУ С ЛЕТУЧЬЕЙ МЫШЬЮ ***\n";
        std::cout << "*** ОНА ВИДИТ ВАС, НАБРАСЫВАЕТСЯ И ПЕРЕТАСКИВАЕТ В СОСЕДНЮЮ КОМНАТУ ***\n\n";
        unsigned int r = rand() % 3;
        if (r == 0) {
            room = room->GetFirst();
        } else if (r == 1){
            room = room->GetSecond();
        } else {
            room = room->GetThird();
        }
        room = MessAboutEnemy(room);
    }
    else if (enemy == Enemies::Pit)
    {
        std::cout << "*** ВЫ ЗАШЛИ В КОМНАТУ С ЯМОЙ И ПРОВАЛИЛИСЬ В НЕЁ ***\n\n";
        run = false;
    }
    return room;
}

Room* Walking(Room* room)
{
    std::cout << "ВВЕДИТЕ НОМЕР КОМНАТЫ \t";
    std::string num;
    std::cin >> num;
    std::cout << '\n';
    std::istringstream iss{num};
    unsigned int numOfRoom;
    iss >> numOfRoom;
    while((!iss)
          || (numOfRoom != room->GetFirst()->GetNumOfRoom()
          && numOfRoom != room->GetSecond()->GetNumOfRoom()
          && numOfRoom != room->GetThird()->GetNumOfRoom()))
    {
        std::cout << "НОМЕР КОМНАТЫ ВВЕДЁН НЕКОРРЕКТНО\n";
        std::cout << "ПОПРОБУЙТЕ ВВЕСТИ ЗАНОВО \t";
        std::cin >> num;
        std::cout << '\n';
        iss.clear();
        iss.str(num);
        iss >> numOfRoom;
    }
    if (room->GetFirst()->GetNumOfRoom() == numOfRoom)
    {
        room = room->GetFirst();
    }
    else if (room->GetSecond()->GetNumOfRoom() == numOfRoom)
    {
        room = room->GetSecond();
    }
    else if (room->GetThird()->GetNumOfRoom() == numOfRoom)
    {
        room = room->GetThird();
    }
    room = MessAboutEnemy(room);
    return room;
}

std::vector<unsigned int> PathProcessing()
{
    std::string rooms;
    std::cin >> rooms;
    std::cout << '\n';
    std::istringstream iss{rooms};
    unsigned int first;
    unsigned int second;
    unsigned int third;
    char ch1;
    char ch2;
    iss >> first >> ch1 >> second >> ch2 >> third;
    while((!iss) || (ch1 != '-' || ch2 != '-'))
    {
        std::cout << "ВВЕДЁННАЯ ВАМИ СТРОКА НЕ СООТВЕТСТВУЕТ ФОРМАТУ\n";
        std::cout << "ПОПРОБУЙТЕ ВВЕСТИ ЗАНОВО \t";
        std::cin >> rooms;
        std::cout << '\n';
        iss.clear();
        iss.str(rooms);
        iss >> first >> ch1 >> second >> ch2 >> third;
    }
    std::vector<unsigned int> numOfRooms {first,second,third};
    return numOfRooms;
}

void ShootingProcessing(Room* room)
{
    Room* shootRoom = room;
    std::vector<unsigned int> numOfRooms = PathProcessing();
    for (int i = 0; i < numOfRooms.size(); ++i)
    {
        if(shootRoom->GetFirst()->GetNumOfRoom() == numOfRooms[i])
        {
            shootRoom = shootRoom->GetFirst();
        }
        else if(shootRoom->GetSecond()->GetNumOfRoom() == numOfRooms[i])
        {
            shootRoom = shootRoom->GetSecond();
        }
        else if(shootRoom->GetThird()->GetNumOfRoom() == numOfRooms[i])
        {
            shootRoom = shootRoom->GetThird();
        }
        else
        {
            if (i == 0) {
                std::cout << "СТРЕЛА ВРЕЗАЛАСЬ В СТЕНУ И СЛОМАЛАСЬ\n\n";
            }
            else
            {
                std::cout << "СТРЕЛА ПРОЛЕТЕЛА ЧЕРЕЗ КОМНАТУ(Ы) С НОМЕРОМ(АМИ) ";
                for (int j = 0; j < i; ++j)
                {
                    std::cout << numOfRooms[j];
                    j != i - 1 ? std::cout << ' ' : std::cout << ',';
                }
                std::cout << " ВРЕЗАЛАСЬ В СТЕНУ И СЛОМАЛАСЬ\n\n";
            }
            return;
        }
        if (CheckEnemy(shootRoom) == Enemies::Vampus)
        {
            std::cout << "ТОЧНО В ЦЕЛЬ! ВЫ УБИЛИ ВАМПУСА!\n\n";
            run = false;
            return;
        }
        if (i == numOfRooms.size() - 1) {
            std::cout << "ВЫ НЕ ПОПАЛИ\n\n";
        }
    }
}

void NewRoomForVamp(Room* room)
{
    bool vampFound = false;
    while(!vampFound)  // Ищем комнату с Вампусом
    {
        room = room->GetFirst();
        if (CheckEnemy(room) == Enemies::Vampus)
        {
            vampFound = true;
            room->SetEnemy(Enemies::None);
            Room* oldVampRoom = room;   // Комната, в которой спал Вампус до перехода в новую
            
            // Случай, когда Вампус "окружён" ямами и мышами
            if (room->GetFirst()->GetEnemy() != Enemies::None
                && room->GetSecond()->GetEnemy() != Enemies::None
                && room->GetThird()->GetEnemy() != Enemies::None)
            {
                unsigned int nextRoom = rand() % 3;
                if (nextRoom == 0) {
                    room = room->GetFirst();
                } else if (nextRoom == 1) {
                    room = room->GetSecond();
                } else {
                    room = room->GetThird();
                }
            }
            while(true)
            {
                unsigned int nextRoom = rand() % 3;
                if (nextRoom == 0 && room->GetFirst() != oldVampRoom
                    && room->GetFirst()->GetEnemy() == Enemies::None)
                {
                    room->GetFirst()->SetEnemy(Enemies::Vampus);
                    break;
                }
                else if (nextRoom == 1 && room->GetSecond() != oldVampRoom
                         && room->GetSecond()->GetEnemy() == Enemies::None)
                {
                    room->GetSecond()->SetEnemy(Enemies::Vampus);
                    break;
                }
                else if (nextRoom == 2 && room->GetThird() != oldVampRoom
                         && room->GetThird()->GetEnemy() == Enemies::None)
                {
                    room->GetThird()->SetEnemy(Enemies::Vampus);
                    break;
                }
            }
        }
    }
}

Room* Shooting(Room* room, unsigned int& countOfArrows)
{
    std::cout << "СТРЕЛА ЛЕТИТ ЧЕРЕЗ 3 КОМНАТЫ\n";
    std::cout << "ВВЕДИТЕ НОМЕРА КОМНАТ В ФОРМАТЕ *-*-*\n";
    std::cout << "ГДЕ СИМВОЛ '*' ОЗНАЧАЕТ НЕКОТОРОЕ ЧИСЛО \t";
    ShootingProcessing(room);
    if (run)
    {
        std::cout << "ЗВУКОМ ВЫСТРЕЛА ВЫ БУДИТЕ ВАМПУСА";
        unsigned int probability = rand() % 100 + 1;
        if (probability <= 25)
        {
            std::cout << ", НО, К ВАШЕМУ СЧАСТЬЮ, ОН СНОВА ЗАСЫПАЕТ\n\n";
        }
        else
        {
            std::cout << " И ОН ПЕРЕХОДИТ В СОСЕДНЮЮ КОМНАТУ\n\n";
            NewRoomForVamp(room);
            if (room->GetEnemy() == Enemies::Vampus)
            {
                std::cout << "ЭТОЙ КОМНАТОЙ ОКАЗАЛАСЬ ТА, В КОТОРОЙ НАХОДИЛИСЬ ВЫ\n";
                std::cout << "ВАМПУС ВИДИТ ВАС, НАБРАСЫВАЕТСЯ И ПОЖИРАЕТ\n\n";
                run = false;
                return room;
            }
        }
        countOfArrows--;
        std::cout << "СТРЕЛ ОСТАЛОСЬ: " << countOfArrows << "\n\n";
        if (countOfArrows == 0)
        {
            std::cout << "У ВАС НЕ ОСТАЛОСЬ СТРЕЛ\n\n";
            run = false;
            return room;
        }
    }
    return room;
}

void Deallocate(Room* room)
{
    while(room->GetNumOfRoom() != 1) {
        room = room->GetFirst();
    }
    for (int i = 0; i < 20; ++i)
    {
        room = room->GetFirst();
        if (i < 10) {
            delete room->GetThird();
        }
        else if (i >= 10 && i < 19) {
            delete room->GetSecond();
        }
        if (i == 18) {
            i++; delete room;
        }
    }
}

void StartOfTheGame()
{
    std::cout << "*** HUNT THE WAMPUS ***\n\n";
    Room* room = StartRoom(); // Комната, с которой начинается игра
    unsigned int countOfArrows = 5;
    
    while (run)
    {
        std::cout << "ВЫ НАХОДИТЕСЬ В КОМНАТЕ \t" << room->GetNumOfRoom() << '\n';
        std::vector<Room*> nearbyRooms{room->GetFirst(), room->GetSecond(), room->GetThird()};
        WarnAboutEnemies(nearbyRooms);
        std::cout << "ТОННЕЛИ ВЕДУТ В КОМНАТЫ \t" << nearbyRooms[0]->GetNumOfRoom();
        std::cout << '\t' << nearbyRooms[1]->GetNumOfRoom();
        std::cout << '\t' << nearbyRooms[2]->GetNumOfRoom() << '\n';
        std::cout << "ИДТИ ИЛИ СТРЕЛЯТЬ (И-С)? \t";
        std::string choice;
        std::cin >> choice;
        std::cout << '\n';
        while(choice != "И" && choice != "С")
        {
            std::cout << "ВВЕДЕНА НЕВЕРНАЯ КОМАНДА\n";
            std::cout << "ПОПРОБУЙТЕ ВВЕСТИ ЗАНОВО \t";
            std::cin >> choice;
            std::cout << '\n';
        }
        if (choice == "И")
        {
            room = Walking(room);
        }
        else if (choice == "С")
        {
            room = Shooting(room,countOfArrows);
        }
    }
    std::cout << "ИГРА ОКОНЧЕНА\n";
    Deallocate(room);
}
