#ifndef CANNONBALL_H
#define CANNONBALL_H

#include <vector>
#include <cmath>
#include <memory>
#include "circle.h"

class Map;
class Sprite;
class Graphic;
class SDL_Rect;
class Block;
class Map;

/*!
 * \brief Die Cannonball Klasse realisiert die von der Kanone (\see Cannon) abgefeuerte
 * Kanonenkugel und prüft die Kollision mit der Map (\see Map) in jedem Frame.
 */
class Cannonball
{
public:
    Cannonball(Graphic &graphic, int posX, int posY);

    /*!
     * \brief update - erneuert die Position der Kugel und prüft danach auf Kollisionen mit der Map
     * \param elapsedTime - die Zeit seit dem letzten Frame
     * \param map - die Map, welche auf Kollisionen mit der Kanonenkugel überprüft wird
     */
    void update(int elapsedTime, Map &map);
    /*!
     * \brief draw - zeichnet die Kanonenkugel
     * \param graphics - das Grafikobjekt auf dem die Kanonenkugel gezeichnet wird
     */
    void draw(Graphic& graphics);
    /*!
     * \brief moveRight - bewegt die Kugel eine Bewegungseinheit nach rechts
     */
    void moveRight();
    /*!
     * \brief moveLeft - bewegt die Kugel eine Bewegungseinheit nach links
     */
    void moveLeft();
    /*!
     * \brief moveUp - bewegt die Kugel eine Bewegungseinheit nach oben
     */
    void moveUp();
    /*!
     * \brief moveDown - bewegt die Kugel eine Bewegungseinheit nach unten
     */
    void moveDown();
    /*!
     * \brief stopMoving - stopt die Bewegung in x-Richtung
     */
    void stopMoving();
    /*!
     * \brief hasCollided - gibt zurück ob die Kanonenkugel kollidiert ist oder nicht
     * \return bool
     */
    bool hasCollided() { return collided; }

private:

    double distance(int x1, int y1, int x2, int y2); /*!< Gibt die Distanz zwischen 2 Punkten zurück */
    bool checkCollision(Circle& A, Map &B); /*!< überprüft, ob der Kollisionskreis mit einem Block aus der Map (\see) kollidiert ist */

    void updateX(int elapsedTime, Map &map);
    void updateY(int elapsedTime, Map &map);

    int posX, posY;
    bool collided;
    float velocityX, velocityY;
    float accelerationX;

    Circle collisionCircle;

    std::unique_ptr<Sprite> spriteDot;
};

#endif // CANNONBALL_H
