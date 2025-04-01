#pragma once

#include "flappy.h"
#include "pipe.h"
#include "land.h"
#include "sound.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class game
{
public:
    struct input
    {
        enum type { QUIT, PLAY, NONE};
        type Type;
    };
    input userInput;
    flappy bird;
    pipe pipe;
    land land;
    sound sound;
public:
    game();

    ~game();

    bool initGraphic();

    bool isQuit()
    {
        return lTexture.quit;
    }

    bool isDie()
    {
        return lTexture.die;
    }

    int getPipeWidth()
    {
        return pipe.width();
    }

    int getPipeHeight()
    {
        return pipe.height();
    }

    void takeInput();

    void display();

    void releaseGraphic();

    void renderScoreSmall();

    void renderScore();

    void renderBestScore();

    void renderStart();

    void renderBackground();

    void renderLand();

    void character();

    bool changeTheme();

    void renderGameOver();

    void replay();

    bool checkReplay();

    void Restart();

private:
    LTexture lTexture;
    const double scaleNumberS = 0.75;
    short int Score;
    short int bestScore;
};
