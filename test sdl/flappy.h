#pragma once

#include "lib.h"
#include "pipe.h"

using namespace std;

class flappy
{
public:
    bool init();

    void render();

    void Free();

    void resetTime()
    {
        time = 0;
    }

    void fall();

    void update(int pipeWidth,int pipeHeight);
private:
    LTexture lTexture;
    int angle,time,x0;
    int ahead = 0;
    string saved_path = "";
    position posFlappy;
};

