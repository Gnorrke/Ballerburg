#ifndef INPUT_H
#define INPUT_H

#include <map>
#include <SDL/SDL.h>

class Player;

class Input
{
public:
    void beginNewFrame();

    void keyUpEvent(const SDL_Event& event);
    void keyDownEvent(const SDL_Event& event);

    bool wasKeyPressed(SDLKey key);
    bool wasKeyReleased(SDLKey key);
    bool isKeyHeld(SDLKey key);

    bool wasButtonPressed(Uint8 button);
    bool wasButtonReleased(Uint8 button);
    bool isButtonHeld(Uint8 button);

    void checkInput(SDL_Event &event);

    void initController();

private:
    bool controllerIsActive = false;
    SDL_Joystick *stick = NULL;

    std::map<SDLKey, bool> heldKeys;
    std::map<SDLKey, bool> pressedKeys;
    std::map<SDLKey, bool> releasedKeys;

    std::map<Uint8, bool> heldButtons;
    std::map<Uint8, bool> pressedButtons;
    std::map<Uint8, bool> releasedButtons;
};

#endif // INPUT_H
