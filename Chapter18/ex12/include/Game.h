#include "Room.h"
#include <ctime>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

struct RoomEnemy
{
    Enemies enemy;
    unsigned int numOfRoom;
};

// Генерирует пещеру из 20 комнат и возвращает указатель на первую комнату
Room* CaveGen();

// Вспомогательная функция для генерации врагов
bool FindRoom(const std::vector<RoomEnemy>& vec, int numOfRoom);

// Генерирует вектор с пятью врагами (1 вампус, 2 мыши и 2 ямы)
std::vector<RoomEnemy> EnemiesGen();

// Инициализирует пещеру врагами
void CaveInit(Room* firstRoom);

// Возвращает указатель на случайную комнату(без Вампуса/летучей мыши/ямы),
// с которой начинается игра.
Room* StartRoom();

// Возвращает название врага, если он есть в комнате, или Enemies::None
Enemies CheckEnemy(Room* room);

// Выводит сообщения о находящихся в соседних комнатах врагах (при их наличии)
void WarnAboutEnemies(const std::vector<Room*>& nearbyRooms);

// Если мы попадаем в комнату с врагом, то данная функция выводит некоторое
// сообщение (в зависимости от врага)
Room* MessAboutEnemy(Room* room);

// Функция для передвижения по пещере
Room* Walking(Room* room);

// Обработка ввода для пути полёта стрелы.
std::vector<unsigned int> PathProcessing();

// Проверка на корректность пути. Если мы убили Вампуса, то run = false.
void ShootingProcessing(Room* room);

// Поиск новой комнаты для Вампуса, в которую он перейдет, если проснется
void NewRoomForVamp(Room* room);

// Функция для стрельбы из лука. Если мы убили Вампуса или он нас сожрал,
// то run = false. Будит Вампуса при совершенном выстреле
Room* Shooting(Room* room, unsigned int& countOfArrows);

// Освобождает память, которая была выделена для комнат пещеры
void Deallocate(Room* room);

// Функция, запускающая игру
void StartOfTheGame();
