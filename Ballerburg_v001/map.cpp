#include "map.h"
#include "castle.h"
#include "mountain.h"
#include "graphic.h"
#include "input.h"
#include "sound.h"
#include "sprite.h"
#include <iostream>

Map* Map::createMap(Graphic& graphics)
{
    Map* newMap = new Map();

    newMap->testcastle.reset(new Castle(graphics, 50));
    newMap->testcastle2.reset(new Castle(graphics, 420));
    newMap->mountain.reset(new Mountain(graphics));

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

    return newMap;
}

void Map::draw(Graphic &graphics)
{
    testcastle->draw(graphics);
    testcastle2->draw(graphics);
    mountain->draw(graphics);
}

void Map::update(Input &input, Sound &sound)
{
    testcastle->update(input, sound);
    testcastle2->update(input, sound);
    mountain->update(input, sound);
}

void Map::deleteBlock(int index)
{
    mapCollision.erase(mapCollision.begin() + index);

    int sizeMountain = mountain->getMap().size() - 1;
    int sizeTestCastle = testcastle->getMap().size() - 1;
    int sizeTestCastle2 = testcastle2->getMap().size() - 1;

    if (0 <= index && index < sizeMountain) mountain->deleteBlock(index - (sizeTestCastle - sizeTestCastle2));
    else if (sizeMountain <= index && index < sizeMountain + sizeTestCastle) testcastle->deleteBlock(index - (sizeTestCastle2));
    else if (sizeMountain + sizeTestCastle <= index && index < sizeTestCastle + sizeMountain + sizeTestCastle2) testcastle2->deleteBlock(index - (sizeMountain - sizeTestCastle));

    std::cout << mapCollision.size() << std::endl;
    std::cout << mountain->getMap().size() + testcastle->getMap().size() + testcastle2->getMap().size()<< std::endl;

}


