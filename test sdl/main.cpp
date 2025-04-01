#include "game.h"
#include "lib.h"
#include <time.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

const short int FPS = 60;
const short int frameDelay = 1000 / FPS;

int main(int argc, char** argv)
{
    Uint32 frameStart;
    short int frameTime;
    game g;
    bool isMenu = 0;
    while(!g.isQuit())
    {
        frameStart = SDL_GetTicks();

        if (g.isDie())
        {
            if (isMenu) {
                g.bird.render();
                g.sound.playHit();
                g.sound.pauseMusic();
            }
            g.userInput.Type = game::input::NONE;
            while(g.isDie() && !g.isQuit())
            {
                g.takeInput();
                if (isMenu == 1 && g.userInput.Type == game::input::PLAY)
                {
                    if (g.checkReplay())
                    {
                        isMenu = 0;
                    }
                    g.userInput.Type = game::input::NONE;
                }
                g.renderBackground();
                g.pipe.render();
                g.land.render();
                if (isMenu)
                {
                    g.bird.render();
                    g.bird.fall();
                    g.renderGameOver();
                    g.renderScoreSmall();
                    g.renderScore();
                    g.renderBestScore();
                    g.replay();
                }
                else
                {
                    g.pipe.init();
                    g.bird.init();
                    g.bird.render();
                    g.renderStart();
                    if (g.userInput.Type == game::input::PLAY)
                    {
                        g.Restart();
                        isMenu = 1;
                        g.userInput.Type = game::input::NONE;
                    }
                    g.land.update();
                }
                g.display();
            }
            g.pipe.init();
        }
        else
        {
            g.takeInput();
            if ( g.userInput.Type == game::input::PLAY)
            {
                g.bird.resetTime();
                g.sound.playBreath();
                g.userInput.Type = game::input::NONE;
            }
            g.renderBackground();
            g.pipe.render();
            g.land.render();
            g.bird.render();
            g.sound.resumeMusic();
            g.sound.renderSound();
            g.renderScoreSmall();
            g.bird.update(g.getPipeWidth(), g.getPipeHeight());
            g.pipe.update();
            g.land.update();
            g.display();
        }

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    return 0;
}
