#include "game.h"
#include "graphic.h"
#include "input.h"
#include "sprite.h"
#include "SDL/SDL.h"

#include <iostream>

const int kFramesPerSecond = 60;
int Game::kScreenWidth = 640;
int Game::kScreenHeight = 400;

Game::Game()
{
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

    background.reset(new Sprite(graphics, "img/background1.bmp", 0, 0, 640, 400));
    bool running = true;

    while (running)
    {
        const int startTime = SDL_GetTicks();
        input.beginNewFrame();

        //Input Handling: Initialisation
        while(SDL_PollEvent(&event))
        {
            input.checkInput(event);
        }

        //exit game
        if (input.wasKeyPressed(SDLK_ESCAPE) || event.type == SDL_QUIT) running = false;

        update();

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
    background->draw(graphics, 0, 0);
    graphics.flip();
}
