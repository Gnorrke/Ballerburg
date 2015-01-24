#ifndef BLOCK_H
#define BLOCK_H

#include <memory>

class Graphic;
class Input;
class Sprite;
class Sound;
class SDL_Rect;


/*!
 * \brief Die Block Klasse bildet die Grundlage für die CastleBlock und MountainBlock Klassen.
 */
class Block
{
public:
    Block(int posX, int posY);

    /*!
     * \brief update - zerstört den Block, falls "hit" true ist
     */
    void update();

    /*!
     * \brief draw - zeichnet den BLock
     * \param graphics - das Graphic Objekt welches zur Darstellung aller Grafiken dient
     */
    void draw(Graphic& graphics);

    /*!
     * \brief destroy - Zerstört das Objekt
     */
    void destroy() { delete this; }

    /*!
     * \brief getCollisionRectangle - Gibt das Rechteck für die Kollisionsabfrage zurück
     * \return SDL_Rect&
     */
    SDL_Rect &getCollisionRectangle();

    int posX, posY; /*!< X und Y Position des Blocks */
    bool hit; /*!< Wurde de Block getroffen oder nicht */

    std::unique_ptr<Sprite> blockSprite; /*!< Hält das Sprite für den Block */
    std::unique_ptr<SDL_Rect> collisionRectangle; /*!< Das Rechteck für die Kollisionsabfrage */

};

#endif // BLOCK_H
