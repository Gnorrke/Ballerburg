#ifndef SOUND_H
#define SOUND_H

#include <memory>
#include "sdl/SDL_mixer.h"
class Sound
{
public:
    Sound();
    ~Sound();

private:
    Mix_Music* backgroundMusic = NULL;
};

#endif // SOUND_H
