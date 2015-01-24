#include "game.h"
#include "graphic.h"
#include "input.h"
#include "sprite.h"
#include "sound.h"
#include "backdrop.h"
#include "cannonball.h"
#include "castle.h"
#include "map.h"
#include "mountain.h"
#include "cannon.h"
#include "button.h"
#include "king.h"
#include "startmenu.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <iostream>

const int kFramesPerSecond = 60;
int Game::kScreenWidth = 640;
int Game::kScreenHeight = 360;
bool Game::running = true;
bool Game::menuRunning = true;

Game::Game()
{
    SDL_WM_SetCaption("Ballerburg! <3", NULL);
    if (SDL_Init(SDL_INIT_EVERYTHING) != -1) gameLoop();
}

Game::~Game()
{
    SDL_Quit();
}

void Game::gameLoop()
{
    Graphic graphics;
    Input input;
    SDL_Event event;

    background.reset(new Backdrop(graphics));
    map.reset(Map::createMap(graphics));
    cannon.reset(new Cannon(graphics, 70, 235));
    sounds.reset(new Sound());
    menu.reset(new StartMenu(graphics));

    // StartMenu
    runStartMenu(input, event, graphics);

    // actual Game
    int lastUpdatedTime = SDL_GetTicks();
    while (Game::running)
    {
        const int startTime = SDL_GetTicks();
        input.beginNewFrame();

        //Input Handling: Initialisation
        while(SDL_PollEvent(&event))
        {
            input.checkInput(event);
            input.moveCannonball(*cannon, graphics);
        }

        //exit game
        if (input.wasKeyPressed(SDLK_ESCAPE) || event.type == SDL_QUIT) running = false;

        const int curTime = SDL_GetTicks();
        const unsigned int elapsedTime = curTime - lastUpdatedTime;

        update(elapsedTime, *map);
        lastUpdatedTime = curTime;

        draw(graphics);

        //Frame Cap

        const int msPerFrame = 1000 / kFramesPerSecond;
        const int elapsedTimeMS = SDL_GetTicks() - startTime;

        if (elapsedTimeMS < msPerFrame) {
            SDL_Delay(msPerFrame - elapsedTimeMS );
        }
    }
}

void::Game::update(int elapsedTime, Map& mapParam)
{
    background->update(elapsedTime);
    map->update();
    cannon->update(elapsedTime, mapParam);
}

void Game::draw(Graphic &graphics)
{
    graphics.cleanUp();
    background->draw(graphics);
    cannon->draw(graphics);
    map->draw(graphics);
    graphics.flip();
}

void Game::runStartMenu(Input& input, SDL_Event& event, Graphic &graphics)
{
    // StartMenu
    while (Game::menuRunning) {
        input.beginNewFrame();

        while(SDL_PollEvent(&event))
        {
            input.checkInput(event);
        }
        const int startTime2 = SDL_GetTicks();
        menu->update(input);
        graphics.cleanUp();
        menu->draw(graphics);
        graphics.flip();
        const int msPerFrame2 = 1000 / kFramesPerSecond;
        const int elapsedTimeMS2 = SDL_GetTicks() - startTime2;

        if (elapsedTimeMS2 < msPerFrame2) {
            SDL_Delay(msPerFrame2 - elapsedTimeMS2 );
        }
    }
}
