#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include "mountainblock.h"
#include <memory>
#include <vector>

class Sprite;
class Graphic;
class Input;
class Sound;
class SDL_Rect;

/*!
 * \brief Die Klasse Mountain stellt das Spielobjekt des Berges dar.
 * Diese besteht aus mehreren Blöcken, welche in einem vector verwaltet werden
 *
 * \author Max Niederauer
 */
class Mountain
{
public:
    Mountain(Graphic& graphics);
    void draw(Graphic& graphics);

    std::vector<SDL_Rect> getMap();

    void deleteBlock(int index);

private:
    std::vector<std::unique_ptr<MountainBlock>> mblocks;
};

#endif // MOUNTAIN_H
