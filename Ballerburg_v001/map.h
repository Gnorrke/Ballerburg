#ifndef MAP_H
#define MAP_H

#include <vector>
#include <memory>

class SDL_Rect;
class Graphic;
class Input;
class Sound;
class Graphic;
class Castle;
class Block;
class Mountain;
class King;

class Map
{
public:
    static Map* createMap(Graphic &graphics);

    void draw(Graphic& graphics);
    void update(Input& input, Sound& sound);

    void deleteBlock(int index);

    std::vector<SDL_Rect>& getCollisionMap() { return mapCollision; }

    std::vector<SDL_Rect> mapCollision;
    std::vector<Block> mapBlocks;

    std::unique_ptr<Castle> testcastle;
    std::unique_ptr<Castle> testcastle2;
    std::unique_ptr<Mountain> mountain;

    std::unique_ptr<King> king1;
    std::unique_ptr<King> king2;

};

#endif // MAP_H
