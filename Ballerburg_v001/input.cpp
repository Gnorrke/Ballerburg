#include "input.h"
#include "SDL/SDL.h"

#include <iostream>

void Input::beginNewFrame()
{
    pressedKeys.clear();
    releasedKeys.clear();

    pressedButtons.clear();
    releasedButtons.clear();
}

void Input::keyDownEvent(const SDL_Event &event)
{
    if(controllerIsActive){
        pressedButtons[event.jbutton.button] = true;
        heldButtons[event.jbutton.button] = true;
    } else {
        pressedKeys[event.key.keysym.sym] = true;
        heldKeys[event.key.keysym.sym] = true;
    }
}

void Input::keyUpEvent(const SDL_Event &event)
{
    if(controllerIsActive){
        releasedButtons[event.jbutton.button] = true;
        heldButtons[event.jbutton.button] = false;
    } else {
        releasedKeys[event.key.keysym.sym] = true;
        heldKeys[event.key.keysym.sym] = false;
    }
}

bool Input::wasKeyPressed(SDLKey key)
{
    return pressedKeys[key];
}

bool Input::wasKeyReleased(SDLKey key)
{
    return releasedKeys[key];
}

bool Input::isKeyHeld(SDLKey key)
{
    return heldKeys[key];
}

bool Input::wasButtonPressed(Uint8 button)
{
    return pressedButtons[button];
}

bool Input::wasButtonReleased(Uint8 button)
{
    return releasedButtons[button];
}

bool Input::isButtonHeld(Uint8 button)
{
    return heldButtons[button];
}

void Input::checkInput(SDL_Event& event)
{    
    switch (event.type) {
    case SDL_KEYDOWN:
        keyDownEvent(event);
        break;

    case SDL_KEYUP:
        keyUpEvent(event);
        break;

    case SDL_JOYBUTTONDOWN:
        keyDownEvent(event);
        break;

    case SDL_JOYBUTTONUP:
        keyUpEvent(event);
        break;

    default:
        break;
    }
}

void Input::initController()
{
    if (SDL_NumJoysticks() < 1)
    {
        controllerIsActive = false;
    }
    stick = SDL_JoystickOpen(0);

    if (stick == NULL) {
        return;
    } else{
        controllerIsActive = true;
    }
}




