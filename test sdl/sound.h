#pragma once
#include <SDL_mixer.h>
#include <string>
#include "lib.h"

using namespace std;

class sound
{
public:
    bool init();

    void Free();

    void playBreath();

    void playHit();

    void pauseMusic();

    void resumeMusic();

    void renderSound();

private:
    LTexture lTexture;
    bool isPlay = 0;
    Mix_Chunk* breath = NULL;
    Mix_Chunk* hit = NULL;
    Mix_Music* music = NULL;
    SDL_Rect Active ;
};
