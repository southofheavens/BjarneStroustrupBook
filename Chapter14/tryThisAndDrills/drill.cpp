/*
 * К сожалению, мы не можем сформулировать задание, которое выявило бы понимание общих принципов
 * проектирования, поэтому решили сосредоточиться на свойствах языка, поддерживающих объектно-
 * ориентированное программирование.
 * 
 * 1. Определите класс B1 с виртуальной функцией vf() и невиртуальной функцией f(). Определите эти функции
 * в классе B1. Реализуйте каждую функцию так, чтобы она выводила свое имя (например, "B1::vf()"). Сделайте
 * эти функции открытыми. Создайте объект B1 и вызовите каждую из функций. 
 * 
 * 2. Определите класс D1, производный от класса B1, и перекройте в нем функцию vf(). Создайте объект класса
 * D1 и вызовите из него функции vf() и f().
 * 
 * 3. Определите ссылку на объект класса B1 (т.е. B1&) и инициализируйте ее только что созданным объектом
 * класса D1. Вызовите функции vf() и f() с помощью этой ссылки.
 * 
 * Результат: B1::Vf() B1::F() D1::Vf() B1::F() D1::Vf() B1::F() 
 * 
 * 4. Теперь определите функцию f() в классе D1 и повторите пп. 1-3. Объясните результаты.
 * 
 * Результат: B1::Vf() B1::F() D1::Vf() D1::F() D1::Vf() B1::F() 
 * 
 * Мы видим, что вызов метода F() из объекта d1 дал разные результаты (B1::F() и D1::F()). Произошло
 * это потому, что в первом случае была вызвана функция F() из класса B1 (наследование реализации),
 * т.к. эта функция не была определена в классе D1, а во втором случае была вызвана функция F() из
 * класса D1, т.к. эту функцию мы определили.
 * 
 * 5. Добавьте в класс B1 чисто виртуальную функцию pvf() и попытайтесь повторить пп. 1-4. Объясните
 * результат.
 * 
 * При попытке скомпилировать программу, мы получаем ошибки "использование объекта абстрактного типа
 * класса "B1" не допускается" и "использование объекта абстрактного типа класса "D1" не допускается".
 * Это очевидно. Происходит это потому, что при объявлении чисто виртуальной функции класс становится
 * абстрактным и мы не можем создать объект этого класса. А для того, чтобы создать объект класса D1, 
 * мы должны переопределить (перекрыть) в нём функцию Pvf().
 * 
 * 6. Определите класс D2, производный от класса D1, и перекройте в нем функцию pvf(). Создайте объект
 * класса D2 и вызовите из него функции f(), vf() и pvf().
 * 
 * 7. Определите класс B2 с чисто виртуальной функцией pvf(). Определите класс D21 с данным-членом
 * типа string и функцией-членом, перекрывающей функцию pvf(); функция D21::pvf() должна выводить 
 * значение упомянутого выше члена типа string. Определите класс D22, аналогичный классу D21, за 
 * исключением того, что его член имеет тип int. Определите функцию f(), получающую аргумент типа B2& 
 * и вызывающую функцию pvf() для этого аргумента. Вызовите функцию f() с аргументами D21 и D22.
 */

#include <iostream>
#include <string>

class B1
{
public:
    virtual void Vf() { std::cout << "B1::Vf() "; }
    void F() { std::cout << "B1::F() "; }
    virtual void Pvf() = 0;
};

class D1 : public B1
{
public:
    void Vf() override { std::cout << "D1::Vf() "; }
    void F() { std::cout << "D1::F() "; }
    virtual void Pvf() override { std::cout << "D1::Pvf() "; }
};

class D2 : public D1
{
public:
    void Pvf() override { std::cout << "D2::Pvf() "; }
};

class B2
{
public:
    virtual void Pvf() = 0;
};

class D21 : public B2
{
private:
    std::string str = "Hello";

public:
    void Pvf() override { std::cout << str << '\n'; }
};

class D22: public B2
{
private:
    int i = 500;

public:
    void Pvf() override { std::cout << i << '\n'; }
};

void F(B2& b2)
{
    b2.Pvf();
}

int main()
{
    /*
    B1 b1;
    b1.Vf();
    b1.F();
    */

    D1 d1;
    d1.Vf();
    d1.F();

    B1& b1r = d1;
    b1r.Vf();
    b1r.F();

    D2 d2;
    d2.F();
    d2.Vf();
    d2.Pvf();

    std::cout << '\n';

    D21 d21;
    F(d21);

    D22 d22;
    F(d22);

    return 0;
}
