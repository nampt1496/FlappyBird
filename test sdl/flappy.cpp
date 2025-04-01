#include "flappy.h"
#include <stdio.h>
#include <iostream>

bool flappy::init()
{
    string bird_path = "image/flappy.png";
    if (saved_path == bird_path)
    {
        posFlappy.getPos(75, lTexture.SCREEN_HEIGHT / 2 - 10);
        ahead = 0;
        angle = 0;
    }
    if (lTexture.isNULL() || saved_path != bird_path)
    {
        saved_path = bird_path;
        if ( lTexture.Load(bird_path.c_str() , 1) )
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

void flappy::Free()
{
    lTexture.free();
}

void flappy::render()
{
    lTexture.Render(posFlappy.x, posFlappy.y, angle);
}

void flappy::fall()
{
    if (lTexture.die && posFlappy.y < lTexture.SCREEN_HEIGHT - lTexture.LAND_HEIGHT - lTexture.BIRD_HEIGHT - 5)
    {
        if (time == 0)
        {
            x0 = posFlappy.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            posFlappy.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }
    }
    else return;
}

void flappy::update(short int pipeWidth, short int pipeHeight)
{
    if (!lTexture.die)
    {
        if (time == 0)
        {
            x0 = posFlappy.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            posFlappy.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }

        if ( (posFlappy.x + lTexture.getWidth() > posPipe[ahead].x + 5) && (posFlappy.x + 5 < posPipe[ahead].x + pipeWidth) &&
             (posFlappy.y + 5 < posPipe[ahead].y + pipeHeight || posFlappy.y  + lTexture.getHeight() > posPipe[ahead].y + pipeHeight + lTexture.PIPE_SPACE + 5) )
        {
            lTexture.die = true;
        }
        else if (posFlappy.x > posPipe[ahead].x + pipeWidth )
        {
            ahead = ( ahead + 1 ) % lTexture.TOTAL_PIPE;
            lTexture.score++;
        }

        if (posFlappy.y > lTexture.SCREEN_HEIGHT - lTexture.LAND_HEIGHT -  lTexture.BIRD_HEIGHT - 5 || posFlappy.y < - 10 )
        {
            lTexture.die = true;
        }
    }
}

