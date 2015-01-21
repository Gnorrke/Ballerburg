#ifndef CIRCLE_H
#define CIRCLE_H

/*!
 * \brief Dies ist eine kleine Klasse, die einen einfachen Kreis realisiert
 */

class Circle
{
public:
    Circle(int offsetX, int offsetY, int radius) : x(offsetX), y(offsetY), r(radius) {}

    int x, y; /*!< Offset von der Mitte des Kreises */
    int r; /*!< Radius des Kreises */
};

#endif // CIRCLE_H
