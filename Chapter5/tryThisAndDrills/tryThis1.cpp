/*
 * Попробуйте скомпилировать приведенные примеры и проанализируйте сообщения компилятора.
 * 
 * Полученные сообщения об ошибках:
 * semyonzhuravlev@MacBook-Air Chapter5 % clang++ -std=c++14 tryThis1.cpp
 * tryThis1.cpp:15:20: error: expected ')'
 *   int s1 = area(7;
 *                  ^
 * tryThis1.cpp:15:18: note: to match this '('
 *   int s1 = area(7;
 *                ^
 * tryThis1.cpp:16:9: error: cannot initialize a variable of type 'int' with an rvalue of type 'void'
 *   int s2 = area(7)
 *       ^    ~~~~~~~
 * tryThis1.cpp:16:21: error: expected ';' at end of declaration
 *   int s2 = area(7)
 *                   ^
 *                   ;
 * tryThis1.cpp:18:19: warning: missing terminating ' character [-Winvalid-pp-token]
 *   int s4 = area('7);
 *                 ^
 * tryThis1.cpp:18:19: error: expected expression
 * tryThis1.cpp:20:2: error: expected ';' at end of declaration
 * }
 *  ^
 *  ;
 * tryThis1.cpp:20:2: error: expected '}'
 * tryThis1.cpp:14:1: note: to match this '{'
 * {
 * ^
 * 1 warning and 6 errors generated.
 */

/*
void area(int i) { }

int main()
{
    int s1 = area(7;
    int s2 = area(7)
    Int s3 = area(7);
    int s4 = area('7);
    return 0;
}
*/