#pragma once

#include "lib.h"
#include <vector>

using namespace std;

class land
{
public:
    bool init();

    void Free();

    void render();

    void update();

private:
    LTexture lTexture;
    position posLand;
};
