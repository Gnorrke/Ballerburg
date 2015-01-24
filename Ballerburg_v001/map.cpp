#include "map.h"
#include "castle.h"
#include "mountain.h"
#include "graphic.h"
#include "input.h"
#include "sound.h"
#include "animatedsprite.h"
#include "king.h"
#include "sprite.h"
#include <iostream>

Map* Map::createMap(Graphic& graphics)
{

    Map* newMap = new Map();

    newMap->testcastle.reset(new Castle(graphics, 50));
    newMap->testcastle2.reset(new Castle(graphics, 420));
    newMap->mountain.reset(new Mountain(graphics));
    newMap->king1.reset(new King(graphics,120,314));
    newMap->king2.reset(new King(graphics,490,314));

    newMap->mapCollision = std::vector<SDL_Rect>(0);
    std::vector<SDL_Rect> mapmountain(newMap->mountain->getMap().size());
    std::vector<SDL_Rect> maptestcastle1(newMap->testcastle->getMap().size());
    std::vector<SDL_Rect> maptestcastle2(newMap->testcastle2->getMap().size());

    mapmountain = newMap->mountain->getMap();
    maptestcastle1 = newMap->testcastle->getMap();
    maptestcastle2 = newMap->testcastle2->getMap();
    newMap->mapCollision.insert(newMap->mapCollision.end(), mapmountain.begin(), mapmountain.end() );
    newMap->mapCollision.insert(newMap->mapCollision.end(), maptestcastle1.begin(), maptestcastle1.end() );
    newMap->mapCollision.insert(newMap->mapCollision.end(), maptestcastle2.begin(), maptestcastle2.end() );

    newMap->mapCollision.insert(newMap->mapCollision.end(), newMap->king1->getCollisionRectangle());
    newMap->mapCollision.insert(newMap->mapCollision.end(), newMap->king2->getCollisionRectangle());

    return newMap;
}

void Map::draw(Graphic &graphics)
{
    testcastle->draw(graphics);
    testcastle2->draw(graphics);
    mountain->draw(graphics);
    king1->draw(graphics);
    king2->draw(graphics);
}

void Map::update()
{
    testcastle->update();
    testcastle2->update();
}

void Map::deleteBlock(int index)
{
    mapCollision.erase(mapCollision.begin() + index);

    int sizeMountain = mountain->getMap().size();
    int sizeTestCastle = testcastle->getMap().size();
    int sizeTestCastle2 = testcastle2->getMap().size();

    if (0 <= index && index < sizeMountain) mountain->deleteBlock(index);
    else if (sizeMountain <= index && index < sizeMountain + sizeTestCastle) {

        //exploPosX = testcastle->getBlock(index - sizeMountain).posX;
        testcastle->deleteBlock(index - sizeMountain);
    }
    else if (sizeMountain + sizeTestCastle <= index && index < sizeTestCastle + sizeMountain + sizeTestCastle2) testcastle2->deleteBlock(index - (sizeMountain + sizeTestCastle));
    else if ((int) mapCollision.size() - 1 == index) king1->disable();
    else if ((int) mapCollision.size() == index) king2->disable();
    std::cout << mapCollision.size() << std::endl;
    std::cout << mountain->getMap().size() + testcastle->getMap().size() + testcastle2->getMap().size()<< std::endl;
}

