# Контрольные вопросы

#### 1. Что такое предметная область?
Предметная область (также называемая доменной областью) — это совокупность знаний, понятий, правил и процессов, относящихся к конкретной области деятельности или отрасли. 

#### 2. Как выглядит идеальное именование?
Логически разные операции имеют разные имена. Если две операции схожи между собой, но на самом деле за ними кроется фундаментальная разница, то такие операции должны называться по-разному.

#### 3. Что такое имя?
Это идентификатор, который используется для обозначения различных элементов программы, таких как:
- Переменные
- Функции
- Классы
- Пространства имён  
и т.д.

#### 4. Какие возможности предоставляет класс Shape?
Этот класс представляет собой понятие, которое связывает графические объекты с нашей абстракцией Window, которая, в свою очередь, обеспечивает связь с ОС и физическим экраном. Также этот класс работает с цветом и стилем, используемыми при рисовании линий. Для этого он хранит члены классов Line_style и Color. Этот класс может хранить последовательности объектов класса Point и информацию о том, как их рисовать.

#### 5. Чем абстрактный класс отличается от классов, не являющихся абстрактными? 
Если класс абстрактный, то мы не можем определить объект этого класса. Можно определять только объекты классов-наследников от абстрактного класса.

#### 6. Как сделать класс абстрактным?
Добавить в него чисто виртуальную функцию.

#### 7. Как управлять доступом?
Язык C++ реализует простую модель доступа к членам класса. Члены класса могут быть закрытыми, защищенными или открытыми.

#### 8. Зачем нужен раздел private? 
Чтобы предотвратить прямой доступ к данным-членам и методам класса.

#### 9. Что такое виртуальная функция и чем она отличается от невиртуальных функций?
Виртуальная функция - это функция, которая может быть переопределена (в отличие от невиртуальной функции) в производном классе.

#### 10. Что такое базовый класс?
Это класс, от которого наследуется другой класс, называемый производным классом.

#### 11. Как объявляется производный класс?
class Название_класса : Модификатор_доступа Название_базового_класса {};

#### 12. Что мы подразумеваем под схемой объекта?
Схема объекта определяется членами класса: данные-члены хранятся в памяти один за другим.

#### 13. Что можно сделать, чтобы класс было легче тестировать?
Чтобы сделать класс легче для тестирования в C++, можно следовать нескольким простым рекомендациям:
1. Разделение ответственности: каждый класс должен выполнять одну конкретную задачу. 
2. Использование интерфейсов.
3. Минимизирование состояния объекта: чем меньше состояние у объекта (например, приватные поля), тем проще его тестировать. 
4. Создание отдельного метода для логики: если у нас есть большой метод с множеством операций, нужно разбить его на более мелкие методы. 

#### 14. Что такое диаграмма наследования?
Это диаграмма, отображающая некоторую иерархию классов.

#### 15. В чем заключается разница между защищенными и закрытыми членами класса?
К защищенным членам класса может обращаться как сам класс, так и производные от него классы, а к закрытым членам класса может обращаться только сам класс.

#### 16. К каким членам класса имеют доступ члены производного класса?
Зависит от модификатора доступа. 
- Если базовый класс для класса D является private, то имена его членов, объявленных как public и protected, могут использоваться только членами класса D.
- Если базовый класс для класса D является protected, то имена его членов, объявленных как public и protected, могут использоваться только членами класса D и члена классов, производных от класса D.
- Если базовый класс для класса D является public, то имена его членов, объявленных как public, могут использоваться любыми функциями.

#### 17. Чем чисто виртуальная функция отличается от других виртуальных функций?
Если функция чисто виртуальная, то она обязательно должна быть перекрыта в производном классе.

#### 18. Зачем делать функции-члены виртуальными?
Чтобы при необходимости была возможность переопределить функцию в производном классе.

#### 19. Зачем делать функции-члены чисто виртуальными?
Чтобы создать абстрактный класс и "обязывать" каждый производный класс определять чисто виртуальные функции.

#### 20. Что такое перекрытие?
Это переопределение виртуальной функции в производном классе.

#### 21. Чем наследование интерфейса отличается от наследования реализации?
- Наследование интерфейса: функция, ожидающая аргумент класса Shape, может принять аргумент класса Circle. При наследовании интерфейса мы создаем базовый класс, который содержит объявления чисто виртуальных функций. Это позволяет создавать классы-потомки, которые будут обязаны реализовать эти функции по-своему.
- Наследование реализации: определяя класс Circle и его функции-члены, мы можем использовать возможности, предоставляемые классом Shape. Когда класс наследует другой класс и получает его методы уже реализованными, то говорят о наследовании реализации. В этом случае потомок может использовать методы родителя "как есть" либо переопределять их под свои нужды.

#### 22. Что такое объектно-ориентированное программирование?
Это парадигма программирования, которая основывается на концепции "объектов" и использует такие эвристики, как наследование, полиморфизм времени выполнения и инкапсуляция.