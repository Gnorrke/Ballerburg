#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <string>
#include <map>


class SDL_Surface;
class SDL_Rect;

/*!
 * \brief Die Klasse Graphic dient als zentrales Objekt, wenn es um das
 * Laden und Darstellen von Sprites geht.
 *
 * Alle Grafiken werden in einer Map organisiert und mit Hilfe
 * der blitSurface Methode auf dem Screen angebracht
 *
 * \see sprite.h
 * \see animatedSprite.h
 *
 * \author Max Niederauer
 */

class Graphic
{
public:
    typedef SDL_Surface* SurfaceID;

    Graphic();
    ~Graphic();

    /*!
     * \brief Lädt eine Datei und setzt einen ColorKey (entfernt RGB: 255, 0, 255)
     * \param filePath  - Dateipfad zu der Datei, die geladen werden soll
     * \return gibt das Surface zurück auf welches die Datei geladen wurde
     */
    SurfaceID loadImage(const std::string& filePath);

    /*!
     * \brief zeichnet ein Surface auf den Screen
     * \param src - Surface, welches auf den Screen gezeichnet werden soll
     * \param src_rectangle - definiert wo und wie groß das Surface gezeichnet werden soll (beinhaltet das Surface)
     * \param dest_rectangle - das engültige Ziel des Surfaces
     */
    void blitSurface(SurfaceID src,
                     SDL_Rect* src_rectangle,
                     SDL_Rect* dest_rectangle);

    /*!
     * \brief Säubert den Screen nach jedem Frame, indem er alles löscht. Dies verhindert
     * Artefakte aus dem letzten Frame im neuen Frame
     */
    void cleanUp();

    /*!
     * \brief Da der Screen als doppelter Puffer in SDL realisiert wird
     * muss der Screen "umgedreht" werden
     * \see SDL/SDL.h
     */
    void flip();

private:
    typedef std::map<std::string, SDL_Surface*> SpriteMap; /*!< Definition eines eigenen Types SpriteMap*/

    SpriteMap spriteSheets; /*!< std::map, die die Sprites organisiert */
    SDL_Surface* screen; /*!< Der Screen auf den alle Surfaces gezeichnet werden */
};

#endif // GRAPHIC_H
