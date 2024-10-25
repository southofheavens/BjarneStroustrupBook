/*
 * Напишите программу, которая ничего не делает, а просто объявляет ряд переменных с допустимыми 
 * и недопустимыми именами (например, int double = 0;), и посмотрите на реакцию на них компилятора.
 * 
 * int double = 0;
 * char 1variable = 'm';
 * double variable = 5.5;
 * bool b = true;
 * bool second b = false;
 * 
 * semyonzhuravlev@MacBook-Air Chapter3 % clang++ -std=c++14 ex03.cpp
 * ex03.cpp:6:9: error: cannot combine with previous 'int' declaration specifier
 *   int double = 0;
 *       ^
 * ex03.cpp:6:16: error: expected unqualified-id
 *   int double = 0;
 *              ^
 * ex03.cpp:7:10: error: expected unqualified-id
 *   char 1variable = 'm';
 *        ^
 * ex03.cpp:10:16: error: expected ';' after top level declarator
 *   bool second b = false;
 *              ^
 *              ;
 * 4 errors generated.
 *
 */
