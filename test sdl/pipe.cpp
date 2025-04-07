
#include "pipe.h"

vector<position> posPipe;

bool pipe::init()
{
    posPipe.clear();
    for (int i = 0; i < lTexture.TOTAL_PIPE; i++)
    {
        position temp;
        temp.getPos(lTexture.SCREEN_WIDTH + i * lTexture.PIPE_DISTANCE + 350, (rand() % (randMax - randMin + 1)) + randMin);
        posPipe.push_back(temp);
    }
    if (lTexture.isNULL())
    {
        if (lTexture.Load( "image/pipe.png", 1 ))
        {
            return true;
        }
    }
    return false;
}

void pipe::Free()
{
    lTexture.free();
}

void pipe::render()
{
    for (int i = 0; i < lTexture.TOTAL_PIPE; i++)
    {
        lTexture.Render(posPipe[i].x, posPipe[i].y);
        lTexture.Render(posPipe[i].x, posPipe[i].y + lTexture.getHeight() + lTexture.PIPE_SPACE, 180);
    }
}

void pipe::update()
{
    if (!lTexture.die)
    {
        for (int i = 0; i < lTexture.TOTAL_PIPE; i++)
        {
            if (posPipe[i].x < - lTexture.getWidth())
            {
                posPipe[i].y = (rand() % (randMax - randMin + 1)) + randMin;
                posPipe[i].x = posPipe[(i + lTexture.TOTAL_PIPE - 1) % lTexture.TOTAL_PIPE].x + lTexture.PIPE_DISTANCE;
            }
            else
            {
                posPipe[i].x -= 3;
            }
        }
    }
}
