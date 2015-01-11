#include "sound.h"
#include <iostream>
#include "SDL/SDL_mixer.h"

Sound::Sound()
{
    if (Mix_OpenAudio( 44000, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1) std::cout << "Fehler" << std::endl;
    backgroundMusic = Mix_LoadMUS("sounds/theme.mp3");
    explosionSound = Mix_LoadWAV("sounds/explosion.wav");
    winSound = Mix_LoadWAV("sounds/win.wav");

    Mix_FadeInMusic(backgroundMusic, 10, 2000 );
}

Sound::~Sound()
{
    Mix_FreeMusic(backgroundMusic);
    Mix_FreeChunk(explosionSound);
    Mix_CloseAudio();
}

void Sound::playSound(int soundNumber)
{
    switch (soundNumber) {
    case 1:
        Mix_PlayChannel(-1, explosionSound, 0);
        break;
    case 2:
            Mix_PlayChannel(-1,winSound,0);
            break;
    default:
        break;
    }
}
