#ifndef BUTTON_H
#define BUTTON_H

#include "memory"
#include "SDL/SDL.h"
#include "sprite.h"
#include <string>

class Graphic;
class Input;

/*!
 * \brief Die Button Klasse stellt eine einfache Klasse dar, mit deren Hilfe
 * man Button erstellen kann. Diese reagieren auf Aktionen der Maus.
 */

class Button
{
public:
    Button(int x, int y, int w, int h, Graphic &graphics, const std::string filepath);

    /*!
     * \brief handleEvents - Kümmert sich um die Events des Maus und
     * setzt die Region des Sprites in der die Maus interagieren kann
     */
    bool handleEvents(Input& in);

    /*!
     * \brief draw - Zeichnet den Button
     * \param graphics - Das Grafik Objekt auf dem der Button gezeichnet wird
     */
    void draw(Graphic& graphics);

private:
    std::unique_ptr<SDL_Rect> box; /*!< Die Attribute des Buttons */
    std::unique_ptr<Sprite> sprite; /*!< Das Sprite des Buttons */
};

#endif // BUTTON_H
