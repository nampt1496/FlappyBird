#include "flappy.h"
#include <stdio.h>
#include <iostream>

bool flappy::init()
{
    string bird_path = "image/flappy.png";
    if (saved_path == bird_path)
    {
        posFlappy.getPos(75, SCREEN_HEIGHT / 2 - 10);
        ahead = 0;
        angle = 0;
    }
    if (isNULL() || saved_path != bird_path)
    {
        saved_path = bird_path;
        if ( Load(bird_path.c_str() , 1) )
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
    free();
}

void flappy::render()
{
    Render(posFlappy.x, posFlappy.y, angle);
}

void flappy::fall()
{
    if (die && posFlappy.y < SCREEN_HEIGHT - LAND_HEIGHT - BIRD_HEIGHT - 5)
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
    if (!die)
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

        if ( (posFlappy.x + getWidth() > posPipe[ahead].x + 5) && (posFlappy.x + 5 < posPipe[ahead].x + pipeWidth) &&
             (posFlappy.y + 5 < posPipe[ahead].y + pipeHeight || posFlappy.y  + getHeight() > posPipe[ahead].y + pipeHeight + PIPE_SPACE + 5) )
        {
            die = true;
        }
        else if (posFlappy.x > posPipe[ahead].x + pipeWidth )
        {
            ahead = ( ahead + 1 ) % TOTAL_PIPE;
            score++;
        }

        if (posFlappy.y > SCREEN_HEIGHT - LAND_HEIGHT -  BIRD_HEIGHT - 5 || posFlappy.y < - 10 )
        {
            die = true;
        }
    }
}

