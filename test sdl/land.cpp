#include "land.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

bool land::init()
{
    posLand.getPos(0, lTexture.SCREEN_HEIGHT - lTexture.LAND_HEIGHT);
    string land_path = "image/land.png";
    if (lTexture.isNULL())
    {
        if ( lTexture.Load( land_path.c_str(), 1 ) )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

void land::Free()
{
    lTexture.free();
}

void land::render()
{
    if (posLand.x > 0)
    {
        lTexture.Render(posLand.x, posLand.y);
    }
    else if (posLand.x > -lTexture.SCREEN_WIDTH && posLand.x <= 0)
    {
        lTexture.Render(posLand.x, posLand.y);
        lTexture.Render(posLand.x + lTexture.SCREEN_WIDTH, posLand.y, 0, NULL);
    }
    else
    {
        posLand.getPos(0, lTexture.SCREEN_HEIGHT - lTexture.LAND_HEIGHT);
        lTexture.Render(posLand.x, posLand.y);
    }
}

void land::update()
{
    posLand.x -= 3;
}

