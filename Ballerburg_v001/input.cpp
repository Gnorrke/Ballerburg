#include "input.h"
#include "SDL/SDL.h"
#include "cannon.h"

#include <iostream>

void Input::beginNewFrame()
{
    pressedKeys.clear();
    releasedKeys.clear();

    mouseButtonWasPressed = false;
}

void Input::keyDownEvent(const SDL_Event &event)
{
     pressedKeys[event.key.keysym.sym] = true;
     heldKeys[event.key.keysym.sym] = true;
}

void Input::keyUpEvent(const SDL_Event &event)
{
     releasedKeys[event.key.keysym.sym] = true;
     heldKeys[event.key.keysym.sym] = false;
 }

void Input::mouseEvent(const SDL_Event &event)
{
    offsetX = event.motion.x;
    offsetY = event.motion.y;
}

bool Input::wasLeftMouseButtonPressed()
{
    return mouseButtonWasPressed;
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

void Input::checkInput(SDL_Event& event)
{    
    switch (event.type) {
    case SDL_KEYDOWN:
        keyDownEvent(event);
        break;

    case SDL_KEYUP:
        keyUpEvent(event);
        break;

    case SDL_MOUSEMOTION:
        mouseEvent(event);
        break;

    case SDL_MOUSEBUTTONDOWN:
        if(event.button.button == SDL_BUTTON_LEFT){
            mouseButtonWasPressed = true;
            std::cout << "Left Mouse Button was pressed!" << std::endl;
        }
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

void Input::moveCannonball(SDL_Event& event, Cannon &ball, Graphic& graphics)
{
    if (event.button.button == SDL_BUTTON_LEFT) {
        mouseButtonWasPressed = true;
        ball.shoot(graphics, ball.getPosY(), ball.getPosX(), this->getoffsetY(), this->getoffsetX());

    }
}

int Input::getoffsetX()const
{
    return offsetX;
}

int Input::getoffsetY()const
{
    return offsetY;
}


