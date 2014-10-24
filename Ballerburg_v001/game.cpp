#include "game.h"
#include "graphic.h"
#include "input.h"
#include "timer.h"

#include "SDL/SDL.h"

#include <iostream>

const int kFramesPerSecond = 60;
int Game::kScreenWidth = 512;
int Game::kScreenHeight = 384;

const unsigned int kMaxFrameTime = 5 * 1000/ 60;

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    gameLoop();
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

    bool running = true;
    int lastUpdatedTime = SDL_GetTicks();

    while (running)
    {
        const int startTime = SDL_GetTicks();
        input.beginNewFrame();
        input.initController();

        //Input Handling: Initialisation
        while(SDL_PollEvent(&event))
        {
            input.checkInput(event);
        }

        //exit game
        if (input.wasKeyPressed(SDLK_ESCAPE)) running = false;

        const int curTime = SDL_GetTicks();

        update();
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

void::Game::update()
{
}

void Game::draw(Graphic &graphics)
{
    graphics.cleanUp();
    graphics.flip();
}
