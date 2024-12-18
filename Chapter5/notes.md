# Контрольные вопросы

#### 1. Назовите четыре основные разновидности ошибок и кратко опишите их. 
- Ошибки времени компиляции - ошибки, обнаруженные компилятором 
- Ошибки времени редактирования связей - ошибки, обнаруженные редактором связей при попытке объединить объектные файлы в выполнимый модуль 
- Ошибки времени выполнения - ошибки, обнаруженные проверками в работающей программе 
- Логические ошибки - ошибки, найденные программистом в поисках неправильных результатов.

#### 2. Какие виды ошибок можно игнорировать в студенческих программах? 
Мы не должны беспокоиться о некорректном поведении аппаратного обеспечения и системного ПО, а также студенческая программа может завершить работу после обнаружения ошибки.

#### 3. Что должен гарантировать любой законченный проект?
Любой законченный проект должен гарантировать то, что он будет давать желаемые результаты для всех допустимых входных данных и выводить разумные сообщения об ошибках для некорректных входных данных. 

#### 4. Перечислите три подхода, которые можно предпринять для устранения ошибок в программе и разработки правильного программного обеспечения. 
- Организовать программное обеспечение так, чтобы минимизировать количество ошибок;
- Исключить большинство сделанных ошибок в ходе отладки и тестирования;
- Убедиться, что оставшиеся ошибки не серьезны.

#### 5. Почему мы ненавидим отладку?
Потому, что отладка - это утомительная и сложная часть разработки программного обеспечения. 

#### 6. Что такое синтаксическая ошибка? Приведите пять примеров. 
Синтаксическая ошибка - это ошибка, говорящая о том, что фрагмент нашего кода не соответствует грамматике языка C++.
```C++
int s1 = area(7;
int s2 = area(7)
Int s3 = area(7);
int s4 = area('7);
int s5 = area(7):
``` 

#### 7. Что такое ошибка типа? Приведите пять примеров.
Ошибка типа - это ошибка, говорящая о несоответствиях между объявленными типами переменных, функций и так далее и типами значений и выражений, которые мы им присваиваем, передаем в качестве аргументов и т.д.
```C++
int x0 = arena(7);          // Ошибка: необъявленная функция
int x1 = area(7);           // Ошибка: неверное кол-во аргументов
int x2 = area("seven",2);   // Ошибка: первый аргумент имеет неверный тип
int x3 = "hello";           // Ошибка: попытка присвоить переменной типа int
                            // значение типа std::string
int x4 += "5";              // Ошибка: несовместимость типов при операции сложения
```

#### 8. Что такое ошибка времени редактирования связей? Приведите три примера.
Ошибка времени редактирования связей - это ошибка, которая возникает во время этапа связывания (linking) программы, когда компилятор пытается объединить различные модули (объектные файлы) в единое исполняемое приложение. 
```C++
double area(double x, double y) { }   // Не "наша" area 
int area(int x, int y, char unit) { } // Не "наша" area
int area(int length, int width);      // функция area не определена в другом исходном файле 
                                      // и не связана с кодом, сгенерированным из нашего файла => ошибка
int main()
{
    int x = area(2,3);  // Ошибка времени редактирования связей
}
```

#### 9. Что такое логическая ошибка? Приведите три примера. 
Логическая ошибка - это ошибка в алгоритме или логике программы, которая приводит к неправильному результату.
```C++
int x4 = area(10,-7);       // ОК, но что это за прямоугольник?
                            // с отрицательной шириной?
int x5 = area(10.7,9.3);    // ОК, но будет вызвана area(10,9)
char x6 = area(100,9999);   // ОК, но результат будет усечён
```

#### 10. Перечислите четыре потенциальных источника ошибок, рассмотренные в тексте. 
- Плохая спецификация 
- Непредусмотренные аргументы
- Непредусмотренные входные данные
- Логические ошибки

#### 11. Как распознать правдоподобные результаты? Какие методы используются для ответа на вопросы такого рода?
Необходимо выполнить прикидочные вычисления. Это можно сделать, используя листок бумаги и карандаш.

#### 12. Сравните обработку ошибки времени выполнения в вызывающей функции и в вызываемой функции.
Лучше всего проводить обработку ошибки времени выполнения в вызывающей функции потому, что обработка ошибки времени выполнения в вызываемой функции приводит к нарушению удобочитаемости и к хрупкости кода.

#### 13. Почему использование исключений лучше, чем возврат признака ошибки ("значения ошибки")? 
Потому, что использование исключений гарантирует, что ни одна выявленная ошибка не останется необработанной. Иначе говоря, исключения предоставляют механизм, позволяющий сочетать наилучшие подходы к обработке ошибок, исследованные нами до сих пор.

#### 14. Как выполнить тестирование при успешном вводе данных?
1. Необходимо подготовить данные, которые соответствуют ожидаемому формату и диапазонам значений для нашей программы.
2. Запустить программу с тестовыми данными.
3. Сравнить полученный результат с ожидаемым. Результат должен быть правильным и соответствовать заданным условиям.

#### 15. Опишите процесс генерации и перехвата исключений.
Если функция обнаруживает ошибку, которую не может обработать, она не выполняет оператор return, как обычно, а генерирует исключение с помощью инструкции throw, показывая, что произошло нечто неправильное. Любая функция, прямо или косвенно вызывающая данную функцию, может перехватить созданное исключение с помощью конструкции catch, т.е. указать, что следует делать, если вызываемый код вызывал инструкцию throw. Функция выражает свою заинтересованность в перехвате исключений с помощью блока try, перечисляя виды исключений, которые она планирует обрабатывать в своих разделах catch блока try. Если ни одна из вызывающих функций не перехватила исключение, то программа прекращает работу.

#### 16. Почему выражение v[v.size()] для вектора v приводит к ошибке диапазона? К чему может привести такой вызов? 
Потому, что мы обращаемся к несуществующему элементу вектора. По-хорошему, такой вызов должен сгенерировать исключение.

#### 17. Дайте определения предусловия и постусловия; приведите пример (который отличается от функции area() из данной главы); предпочтительно с вычислениями, требующими применения цикла.
Предусловия - правила, которые функция предъявляет к своим аргументам.  
Постусловия - правила, которые функция предъявляет к своему возвращаемому значению. 
Пред- и постусловия обеспечивают базовую проверку разумности кода.

Пример:
```C++
int Fib(int n) // Возвращает число Фибоначчи с порядковым номером n
{
    if (n <= 0) throw std::runtime_error("Неположительное значение аргумента n.");
    
    int first = 1;
    int second = 1;
    int auxiliary;
    for (int i = 2; i < n; ++i)
    {
        auxiliary = second;
        second += first;
        first = auxiliary;
    }
    
    // Произошло переполение переменной типа int
    if (second <= 0) throw std::runtime_error("Неположительное значение возвращаемого результата.");
    return second;
}
```

#### 18. Когда можно не проверять предусловие?
- Никто не может передать неправильные аргументы
- Проверка слишком сильно замедлит выполнение программы
- Проверка является слишком сложной

#### 19. Когда можно не проверять постусловие?
- Проверка чрезвычайно сложна или затратна по ресурсам
- Функция возвращает результат, не зависящий от входных данных

#### 20. Назовите этапы отладки программы.
1. Компилируем программу
2. Редактируем связи
3. Выполняем программу и проверяем, делает ли она то, для чего предназначена

#### 21. Почему комментарии могут помочь при отладке?
Потому, что с комментариями повышается удобочитаемость кода и мы можем быстро определить, что делает тот или иной фрагмент программы. Это особенно важно в больших программах.

#### 22. Чем тестирование отличается от отладки?
Отладка необходима для того, чтобы обнаружить ошибку в нашем коде, а тестирование необходимо для того, чтобы проверить наш код на самых различных входных данных и если для некоторых входных данных мы получаем не тот результат, который ожидали, необходимо выполнить отладку и устранить ошибки.