#include "../include/RightTriangle.h"

RightTriangle::RightTriangle(Point rightAngle, Point secondAngle, Point thirdAngle)
{
    add(rightAngle);
    add(secondAngle);
    add(thirdAngle);
    double firstCathetus = sqrt(pow(point(1).x - point(0).x, 2) + pow(point(1).y - point(0).y, 2));
    double secondCathetus = sqrt(pow(point(2).x - point(0).x, 2) + pow(point(2).y - point(0).y, 2));
    double hypotenuse = sqrt(pow(point(1).x - point(2).x, 2) + pow(point(1).y - point(2).y, 2));
    if (firstCathetus + secondCathetus < hypotenuse
        || firstCathetus + hypotenuse < secondCathetus
        || hypotenuse + secondCathetus < firstCathetus
        || rightAngle == secondAngle
        || secondAngle == thirdAngle
        || thirdAngle == rightAngle)
    {
        throw std::invalid_argument("Треугольника с введёнными точками не существует.");
    }
    double firstSin = firstCathetus / hypotenuse;
    double secondSin = secondCathetus / hypotenuse;
    int angle = (asin(firstSin) + asin(secondSin)) * 180 / 3.14;
    if (angle != 90)
    {
        throw std::invalid_argument("Треугольник с введёнными точками не является прямоугольным.");
    }
}

void RightTriangle::draw_lines() const
{
    Polygon p;
    p.add({point(0).x, point(0).y});
    p.add({point(1).x, point(1).y});
    p.add({point(2).x, point(2).y});
    if (fill_color().visibility()) // fill
    {
        int intColor = fill_color().as_int();
        p.set_fill_color(intColor);
    }
    if (!color().visibility())
    {
        p.set_color(Color::Transparency::invisible);
    }
    p.draw_lines();
}
