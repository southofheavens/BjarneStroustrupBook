/*
 * Попытайтесь скопировать объект класса Shape. Что произошло?
 * 
 * Мы получим предупреждение от компилятора: "На функцию "Graph_lib::Circle::Circle(const Graph_lib::Circle &)"
 * (объявлено неявно) нельзя ссылаться, так как эта функция удалена".
 */

#include "../include/Graph.h"

using namespace Graph_lib;

int main()
{
    Circle c{{150,150},50};
    // Circle c2 = c;

    return 0;
}
