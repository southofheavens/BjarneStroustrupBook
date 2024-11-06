/*
 * Попробуйте скомпилировать приведенные примеры и проанализируйте сообщения компилятора. Придумайте еще
 * несколько ошибок и проверьте реакцию компилятора на них.
 * 
 * Полученные сообщения об ошибках:
 * semyonzhuravlev@MacBook-Air Chapter5 % clang++ -std=c++14 tryThis2.cpp
 * tryThis2.cpp:16:14: error: use of undeclared identifier 'arena'
 *   int x0 = arena(7);          // Ошибка: необъявленная функция
 *            ^
 * tryThis2.cpp:17:14: error: no matching function for call to 'area'
 *   int x1 = area(7);           // Ошибка: неверное кол-во аргументов
 *             ^~~~
 * tryThis2.cpp:9:5: note: candidate function not viable: requires 2 arguments, but 1 was provided
 *   int area(int x, int y)
 *       ^
 * tryThis2.cpp:18:14: error: no matching function for call to 'area'
 *   int x2 = area("seven",2);   // Ошибка: первый аргумент имеет неверный тип
 *            ^~~~
 * tryThis2.cpp:9:5: note: candidate function not viable: no known conversion from 'const char[6]' to 'int' for 1st argument
 *   int area(int x, int y)
 *       ^
 * tryThis2.cpp:19:9: error: cannot initialize a variable of type 'int' with an lvalue of type 'const char[6]'
 *   int x3 = "hello";           // Ошибка: попытка присвоить переменной типа int
 *       ^    ~~~~~~~
 * tryThis2.cpp:21:12: error: invalid '+=' at end of declaration; did you mean '='?
 *   int x4 += "5";              // Ошибка: несовместимость типов при операции сложения
 *          ^~
 *          =
 * tryThis2.cpp:21:9: error: cannot initialize a variable of type 'int' with an lvalue of type 'const char[2]'
 *   int x4 += "5";              // Ошибка: несовместимость типов при операции сложения
 *       ^     ~~~
 * 6 errors generated.
 */

/*
int area(int x, int y)
{
    return x*y;
}

int main()
{
    int x0 = arena(7);          // Ошибка: необъявленная функция
    int x1 = area(7);           // Ошибка: неверное кол-во аргументов
    int x2 = area("seven",2);   // Ошибка: первый аргумент имеет неверный тип
    int x3 = "hello";           // Ошибка: попытка присвоить переменной типа int
                                // значение типа std::string
    int x4 += "5";              // Ошибка: несовместимость типов при операции сложения

    return 0;
}
*/