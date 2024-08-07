# Объекты, типы и значения

Чтобы не писать std::cin и std::cout вместо cin и cout, вы можете написать
using namespace std;

Вместо #include <iostream>, #include <string> и т.д. вы можете подключить файл "std_lib_facilities.h".

В этом же файле подключено пространство имён using namespace std, поэтому если вы напишете 
в своей программе #include "std_lib_facilities.h", то после этого не нужно писать using namespace std;

Установить данный файл вы можете по ссылке https://www.stroustrup.com/Programming/std_lib_facilities.h.
