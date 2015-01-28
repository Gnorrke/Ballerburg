#ifndef INPUT_H
#define INPUT_H

#include <map>
#include <SDL/SDL.h>

class Player;
class Cannonball;
class Cannon;
class Graphic;

class Input
{
public:
    void beginNewFrame();

    void keyUpEvent(const SDL_Event& event);
    void keyDownEvent(const SDL_Event& event);

    void mouseEvent(const SDL_Event& event);
    bool wasLeftMouseButtonPressed();

    bool wasKeyPressed(SDLKey key);
    bool wasKeyReleased(SDLKey key);
    bool isKeyHeld(SDLKey key);

    void checkInput(SDL_Event &event);
    void moveCannonball(SDL_Event &event, Cannon &ball, Graphic &graphics);

    int getoffsetX()const;
    int getoffsetY()const;

private:
    int offsetX = 0;
    int offsetY = 0;

    bool mouseButtonWasPressed;

    std::map<SDLKey, bool> heldKeys;
    std::map<SDLKey, bool> pressedKeys;
    std::map<SDLKey, bool> releasedKeys;

};

#endif // INPUT_H
