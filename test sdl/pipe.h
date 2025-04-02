#pragma once

#include "lib.h"
#include <iostream>
#include <vector>

using namespace std;

extern vector<position> posPipe;

class pipe
{
private:
    LTexture lTexture;
    const short int randMin = -373 + 30;
    const short int randMax = lTexture.SCREEN_HEIGHT - lTexture.LAND_HEIGHT - 373 - lTexture.PIPE_DISTANCE - 30;
public:
    bool init();

    void Free();

    void render();

    void update();

    short int width()
    {
        return lTexture.getWidth();
    }

    short int height()
    {
        return lTexture.getHeight();
    }
};
