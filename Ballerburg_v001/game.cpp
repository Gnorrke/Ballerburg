#include "game.h"
#include "graphic.h"
#include "input.h"
#include "sprite.h"
#include "sound.h"
#include "backdrop.h"
#include "mountain.h"

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
    testcastle.reset(new Sprite(graphics, "img/castle_block1.bmp", 0, 0, 15, 8));
    testcastle2.reset(new Sprite(graphics, "img/castle_block2.bmp", 0, 0, 15, 8));
    testblock.reset(new Mountain(graphics));

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

    testblock->draw(graphics);

    testcastle->draw(graphics, 50, 343);
    testcastle->draw(graphics, 65, 343);
    testcastle->draw(graphics, 80, 343);
    testcastle->draw(graphics, 95, 343);

    testcastle2->draw(graphics, 50, 352);
    testcastle2->draw(graphics, 65, 352);
    testcastle2->draw(graphics, 80, 352);
    testcastle2->draw(graphics, 95, 352);

    testcastle2->draw(graphics, 50, 334);
    testcastle2->draw(graphics, 65, 334);
    testcastle2->draw(graphics, 80, 334);
    testcastle2->draw(graphics, 95, 334);

    graphics.flip();
}
