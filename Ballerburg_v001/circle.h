#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
    Circle(int offsetX, int offsetY, int radius) : x(offsetX), y(offsetY), r(radius) {}

    int x, y, r; //Offset von der Mitte des Kreises
};

#endif // CIRCLE_H
