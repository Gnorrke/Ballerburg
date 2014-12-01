#include "game.h"
#include "graphic.h"
#include "input.h"
#include "sprite.h"
#include "sound.h"
#include "backdrop.h"

#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <iostream>

const int kFramesPerSecond = 60;
int Game::kScreenWidth = 640;
int Game::kScreenHeight = 360;

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
    testblock.reset(new Sprite(graphics, "img/rock.bmp", 0, 0, 20, 20));

    backgroundMusic.reset(new Sound());
    bool running = true;

    int lastUpdatedTime = SDL_GetTicks();

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

        const int curTime = SDL_GetTicks();
        const unsigned int elapsedTime = curTime - lastUpdatedTime;

        update(elapsedTime);
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

void::Game::update(int elapsedTime)
{
    background->update(elapsedTime);
}

void Game::draw(Graphic &graphics)
{
    graphics.cleanUp();
    background->draw(graphics);
    testblock->draw(graphics,260,340);
    testblock->draw(graphics,280,340);
    testblock->draw(graphics,300,340);
    testblock->draw(graphics,320,340);
    testblock->draw(graphics,340,340);
    testblock->draw(graphics,280,320);
    testblock->draw(graphics,300,320);
    testblock->draw(graphics,320,320);
    testblock->draw(graphics,290,300);
    graphics.flip();
}
