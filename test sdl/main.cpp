#include "game.h"
#include "lib.h"
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char** argv)
{
    game g;
    bool isMenu = 0;
    while(!g.isQuit())
    {
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
                        g.sound.resumeMusic();
                        isMenu = 0;
                        g.lTexture.score=0;
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
            g.sound.renderSound();
            g.renderScoreSmall();
            g.bird.update(g.getPipeWidth(), g.getPipeHeight());
            g.pipe.update();
            g.land.update();
            g.display();
        }
    }
    return 0;
}
