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
    const int randMin = -343;
    const int randMax = lTexture.SCREEN_HEIGHT - lTexture.LAND_HEIGHT - lTexture.PIPE_DISTANCE - 403;
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
