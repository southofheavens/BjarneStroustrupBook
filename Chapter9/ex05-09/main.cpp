/*
    Упражнение 5: Для выполнения этого и нескольких следующих упражнений необходимо разработать и реализовать
    класс Book, который является частью программного обеспечения библиотеки. Класс Book должен иметь члены
    для хранения кода ISBN, названия, фамилии автора и даты регистрации авторских прав. Кроме того, он должен
    хранить данные о том, выдана книга на руки или нет. Создайте функции, возвращающие эти данные. Создайте
    функции, проверяющие, выдана книга на руки или нет. Предусмотрите простую проверку данных, которые вводятся
    в объект класса Book; например, код ISBN допускается только в форме n-n-n-x, где n - целое число; x - цифра
    или буква. Храните код ISBN как string.

    Упражнение 6: Добавьте операторы в класс Book. Пусть оператор == проверяет, совпадают ли коды ISBN у двух
    книг. Пусть оператор != также сравнивает коды ISBN, а оператор << выводит в поток название, фамилию автора
    и код ISBN в отдельных строках.

    Упражнение 7: Создайте перечисление для класса Book с именем Genre. Предусмотрите типы для фантастики,
    прозы, периодических изданий, биографий и детской литературы. Отнесите каждую книгу к определенному жанру
    Genre и внесите соответствующие изменения в конструктор класса Book и его функции-члены.

    Упражнение 8: Создайте класс Patron для библиотеки. Этот класс должен содержать имя пользователя, номер
    библиотечной карточки, а также размер членского взноса. Предусмотрите функции, имеющие доступ к этим
    членам, а также функцию, устанавливающую размер членского взноса. Предусмотрите вспомогательный метод,
    возвращающий булево значение (bool), указывающее, заплатил ли пользователь членские взносы.

    Упражнение 9: Создайте класс Library. Включите в него векторы классов Book и Patron. Включите также 
    структуру Transaction и предусмотрите в ней члены классов Book, Patron и класс Date из текста
    данной главы. Создайте вектор объектов класса Transaction. Создайте функции, добавляющие записи о книгах
    и клиентах библиотеки, а также о состоянии книг (выдана ли книга читателю). Если пользователь взял книгу,
    библиотека должна быть уверена, что пользователь является ее клиентом, а книга принадлежит её фондам.
    Если эти условия не выполняются, выдайте сообщение об ошибке. Проверьте также, нет ли у пользователя
    задолженности по уплате членских взносов. Если задолженность есть, выдайте сообщение об ошибке. 
    Если нет, создайте объект класса Transaction и поместите его в вектор объектов класса Transaction.
    Напишите также функцию, возвращающую вектор, содержащий имена всех клиентов, имеющих задолженность.
*/

#include <iostream>
#include "library.h"

int main()
{
    try
    {
        Book book{"1-2-3-Z", "Евгений Онегин", "Пушкин", Date(1970,Month::feb,1), false, Genre::Проза};
        std::cout << book << '\n';
    }
    catch (Date::Invalid)
    {
        std::cerr << "Invalid\n";
        exit(1);
    }
    return 0;
}
