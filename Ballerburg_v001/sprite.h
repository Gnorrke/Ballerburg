#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL/SDL.h>

class Graphic;

/*!
 * \brief Die Sprite Klasse hält ein Bild, welches bei Bedarf auf den Screen gezeichnet werden kann
 */
class Sprite
{
public:
    /*!
     * \brief Legt ein neues Sprite an
     * \param graphics object
     * \param filepath - Der Dateipfad des zu ladenen Bildes
     * \param src_x - Der X-Offset der auf das Sprite angelegt wird
     * \param src_y - Der Y-Offset der auf das Sprite angelegt wird
     * \param width - Legt die Weite des Sprites fest
     * \param height - Legt die Höhe des Sprites fest
     */
    Sprite(Graphic &graphics,
           const std::string& filepath,
           int src_x, int src_y,
           int width, int height);

    virtual void update(int) {}
    /*!
     * \brief Das Sprite wird auf den im graphics Objekt enthaltenen Screen gezeichnet
     * \param graphics - Auf dieses graphic Objekt wird das Sprite gezeichnet
     * \param x - Die X-Position des Sprites auf dem Screen
     * \param y - Die Y-Position des Sprites auf dem Screen
     */
    void draw(Graphic& graphics, int x, int y);

protected:
    SDL_Rect srcRect; /*!< Legt die Abmessungen, Höhe und Weite des Sprites fest */

private:
    SDL_Surface* spriteSheet; /*!< Enthält das Bild */
};

#endif // SPRITE_H
