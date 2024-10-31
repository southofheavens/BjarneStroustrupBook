// for ex02

#include <assert.h>
#include <stdlib.h>

struct Link
{
    struct Link* prev;
    struct Link* succ;
};

struct List
{
    struct Link* first;
    struct Link* last;
};

struct Name
{
    struct Link lnk;    // Требуется для операций List
    char* n;            // Строка имени
};

struct Name* MakeName(char* n);

void Init(struct List* lst);         // Инициализируем lst
struct List* Create(void);           // Создает пустой список
void Clear(struct List* lst);        // Освобождает все элементы lst
void Destroy(struct List* lst);      // Удаляет все элементы lst, затем удаляет сам список lst

void PushBack(struct List* lst,      // Добавляет элемент p в конец списка lst
              struct Link* p);
struct Link* Erase(struct List* lst, // Удаляет узел p из списка lst, возвращает указатель
                   struct Link* p);  // на следующий узел

struct Link* Advance(struct Link* p, // Сдвигает указатель на n позиций
                     int n);
