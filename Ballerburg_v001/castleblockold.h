#ifndef CASTLEBLOCK_H
#define CASTLEBLOCK_H

#include <memory>

class Graphic;
class Input;
class Sprite;
class Sound;

class CastleblockOLD
{
public:
    CastleblockOLD(Graphic& graphics, int posX, int posY, const std::string& filePath);
    ~CastleblockOLD();

    //onHit erkennt, ob der entsprechende Block angeklickt wurde; muss in späteren Sprints entfernt werden
    void onHit(Input &in, Sound &sound);
    void draw(Graphic& draw);


private:
    //isHit kann später entfernt werden, da Kollisionserkennung über Cannonball realisiert wird
    bool isHit(Input& in);
    //wird hit auf true gesetzt, wird der entsprechende Block nicht mehr gezeichnet
    bool hit;

    int x,y;

    std::unique_ptr<Sprite> cblock;
};

#endif // MOUNTAINBLOCK_H
