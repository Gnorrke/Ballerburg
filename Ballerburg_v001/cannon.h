#ifndef CANNON_H
#define CANNON_H

#include <memory>
#include <vector>

class Graphic;
class Cannonball;
class Block;
class Sprite;
class SDL_Rect;
class Map;
class Input;

/*!
 * \brief Die Kanonen Klasse implementiert die Kanone eines jeden Spielers und erzeugt
 * eine Kanonenkugel (\see Cannonball) in die gewünschte Richtung
 */
class Cannon
{
public:
    /*!
     * \brief Cannon - erzeugt eine Kanone
     * \param graphics - Das Grafikobjekt auf dem die Kanone gezeichnet wird
     * \param posX - die X Koordinate der Kanone
     * \param posY - die Y Koordinate der Kanone
     */
    Cannon(Graphic &graphics, int posX, int posY);

    /*!
     * \brief draw - zeichnet die Kanone
     * \param graphics - Das Grafikobjekt auf dem die Kanone gezeichnet wird
     */
    void draw(Graphic& graphics);

    /*!
     * \brief update - ruft die update-Methode der dazugehörigen Kanonenkugel auf
     * \param elapsedTime - die vergangene Zeit seit dem letztem Frame
     * \param map - Die Map, welche auf Kollisionen mit der Kanonenkugel geprüft werden soll
     */
    void update(int elapsedTime, Map &map);

    /*!
     * \brief moveLeft - lenkt die Kanone nach links (-x)
     */
    void moveLeft(int x);
    /*!
     * \brief moveRight - lenkt die Kanone nach rechts (+x)
     */
    void moveRight(int x);
    /*!
     * \brief moveUp - lenkt die Kanone nach oben (-y)
     */
    void moveUp(int x);
    /*!
     * \brief moveDown - lenkt die Kanone nach unten (+y)
     */
    void moveDown(int x);

    /*!
     * \brief shoot - erzeugt eine Kanonenkugel und feuert diese ab
     * \param graphics - das Grafikobjekt auf dem die Kanonenkugel gezeichnet wird
     */
    void shoot(Graphic &graphics, int x1, int x2, int y1, int y2);

    int getPosX() { return posX + 15; }
    int getPosY() { return posY + 12; }

    int calculateAngle(int x1, int x2, int y1, int y2);
    int calculatePower(int x1, int x2, int y1, int y2);

private:
    float posX, posY; /*!< Die X- und Y-Koordinaten der Kanone */

    std::unique_ptr<Cannonball> ball; /*!< Das Smartpointer, der die erzeugte Kanonenkugel hält */
    std::unique_ptr<Sprite> cannon; /*!< Das Sprite der Kanone */
};

#endif // CANNON_H
