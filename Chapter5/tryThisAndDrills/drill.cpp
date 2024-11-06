/*
 * Ниже приведены двадцать пять фрагментов кода. Каждый из них предназначен для вставки в определенное место
 * следующей программы.
 * 
 * #include "std_lib_facilities.h"
 * 
 * int main()
 * try {
 *      << Здесь будет вставлен ваш код >>
 *      keep_window_open();
 *      return 0;
 * }
 * catch (exception& e) {
 *      cerr << "Ошибка: " << e.what() << '\n';
 *      keep_window_open();
 *      return 1;
 * }
 * catch (...) {
 *      cerr << "Неизвестное исключение!\n";
 *      keep_window_open();
 *      return 2;
 * }
 * 
 * В некоторых из них есть ошибки, а в некоторых - нет. Ваша задача - найти и устранить все ошибки. Если все
 * ошибки будут устранены, программа будет успешно компилироваться и при запуске выводить на экран слово 
 * "Success!" Даже если вы считаете, что нашли все ошибки, вставьте в программу исходный (неисправленный)
 * вариант и протестируйте его: может быть, ваша догадка об ошибке была неверной или в фрагменте их несколько.
 * Кроме того, одной из целей этого задания является анализ реакции компилятора на разные виды ошибок.
 * Не вводите всю программу двадцать пять раз - можно просто использовать методику "скопировать и вставить"
 * или иную подобную. Не устраняйте проблемы, удаляя инструкции; исправляйте их путем изменения, добавления
 * или удаления небольшого количества символов.
 * 
 * 1. Cout << "Success!\n";
 * 2. cout << "Success!\";
 * 3. cout << "Success" << !\n"
 * 4. cout << success << '\n';
 * 5. string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
 * 6. vector<int> v(10); v(5) = 7; if (v(5) != 7) cout << "Success!\n";
 * 7. if (cond) cout << "Success!\n"; else cout << "Fail!\n";
 * 8. bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n"; 
 * 9. string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n";
 * 10. string s = "ape"; if (s=="fool") cout << "Success!\n";
 * 11. string s = "ape"; if (s=="fool") cout < "Success!\n";
 * 12. string s = "ape"; if (s+"fool") cout < "Success!\n";
 * 13. vector<char> v(5); for (int i=0; 0<v.size(); ++i); cout << "Success!\n";
 * 14. vector<char> v(5); for (int i=0; i<=v.size(); ++i); cout << "Success!\n";
 * 15. string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i];
 * 16. if (true) then cout << "Success!\n"; else cout << "Fail!\n";
 * 17. int x = 2000; char c = x; if (c=2000) cout << "Success!\n";
 * 18. string s = "Success!\n"; for(int i=0; i<10; ++i) cout << s[i];
 * 19. vector v(5); for (int i = 0; i<=v.size(); ++i); cout << "Success!\n";
 * 20. int i=0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n";
 * 21. int x = 2; double d = 5/(x-2); if (d==2*x+0.5) cout << "Success!\n";
 * 22. string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i];
 * 23. int i=0; while (i<10) ++j; if (j<i) cout << "Success!\n";
 * 24. int x = 4; double d = 5/(x-2); if (d=2*x+0.5) cout << "Success!\n";
 * 25. cin << "Success!\n";
 * 
 * Лень это выполнять, слишком длинное, но при этом очень простое задание.
 */
