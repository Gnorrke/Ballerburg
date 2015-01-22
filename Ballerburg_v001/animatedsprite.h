#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "sprite.h"

class Graphic;
/*!
 * \brief Die AnimatedSprite Klasse ist abgeleitet von Sprite und
 * realisiert eine einfache Klasse, um Animationen mit Hilfe
 * von SpriteSheets darzustellen
 */

class AnimatedSprite : public Sprite
{
public:
    AnimatedSprite(Graphic &graphics, const std::string& filepath,
                   int src_x, int src_y,
                   int width, int height,
                   int fps, int numFrames);

    /*!
     * \brief update - wählt das aktuelle Sprite aus dem SpriteSheet aus
     * \param elapsedTimeMs - Zeit seit dem letzten Frame
     */
    void update(int elapsedTimeMs);

private:
    const int frameTime; /*!< Zeit, wie lange ein Sprite angezeigt werden soll */
    const int numFrames; /*!< Die Anzahl an Sprites aus denen die Animation besteht */
    int curFrame; /*!< Der aktuelle Frame */
    int elapsedTime; /*!< Die Zeit seit dem letzten Wechsel zwischen den Sprites/Frames */
};

#endif // ANIMATEDSPRITE_H
