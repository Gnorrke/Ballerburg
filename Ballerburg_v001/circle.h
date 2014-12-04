#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
    Circle(int offsetX, int offsetY, int radius) : offsetX(offsetX), offsetY(offsetY), radius(radius) {}

    int offsetX, offsetY, radius; //Offset von der Mitte des Kreises
};

#endif // CIRCLE_H
