#ifndef BACKLOG_H
#define BACKLOG_H

#include <memory>

class Sprite;
class Graphic;

/*!
 * \brief Die Backdrop Klasse dient dazu alle Elemente
 * des Hintergrunds zusammenzufassen.
 */

class Backdrop
{
public:
    Backdrop(Graphic& graphics);

    /*!
     * \brief draw - zeichnet alle Elemente
     * \param graphics - das Graphic Objekt welches zur Darstellung aller Grafiken dient
     */
    void draw(Graphic& graphics);
    /*!
     * \brief update - updated die Position der Wolken
     * \param elapsedTime - Zeit seit dem letzten Frame
     */
    void update(int elapsedTime);

private:
    bool direction; /*!< Die Richtung des Wolke */
    float posCloudX, posCloudY; /*!< Die Position der Wolke */

    std::unique_ptr<Sprite> background; /*!< Das Sprite des Hintergrunds */
    std::unique_ptr<Sprite> backgroundCloud; /*!< Das Sprite der Wolke */
};

#endif // BACKLOG_H
