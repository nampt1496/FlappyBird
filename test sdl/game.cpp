#include "game.h"
#include "lib.h"
#include <iostream>

void game::takeInput()
{
    while(SDL_PollEvent(&lTexture.event) != 0)
    {
        if (lTexture.event.type == SDL_QUIT)
        {
            userInput.Type = input::QUIT;
            lTexture.quit = true;
        }
        else if (lTexture.event.type == SDL_MOUSEBUTTONDOWN)
        {
            userInput.Type = input::PLAY;
        }
    }
}

game::game()
{
    initGraphic();
    pipe.init();
    land.init();
    sound.init();
}

game::~game()
{
    bird.Free();
    pipe.Free();
    land.Free();
    sound.Free();
    lTexture.free();
    releaseGraphic();
}

void game::releaseGraphic()
{
    SDL_DestroyWindow( lTexture.gWindow );
    lTexture.gWindow = NULL;
    SDL_DestroyRenderer( lTexture.gRenderer );
    lTexture.gRenderer = NULL;
    IMG_Quit();
    SDL_Quit();
}

bool game::initGraphic()
{
	bool success = true;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error:%s\n ", SDL_GetError());
		success = false;
	}
	else
	{
		lTexture.gWindow = SDL_CreateWindow( "Flappy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, lTexture.SCREEN_WIDTH, lTexture.SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

		if( lTexture.gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error:%s\n ", SDL_GetError());
			success = false;
		}
		else
		{
			lTexture.gRenderer = SDL_CreateRenderer( lTexture.gWindow, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC );
			if( lTexture.gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error:%s\n ", SDL_GetError());
				success = false;
			}
			else
			{
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error:%s\n ", IMG_GetError()) ;
					success = false;
				}
			}
		}
	}
	return success;
}

void game::display()
{
    SDL_RenderPresent(lTexture.gRenderer);
    SDL_RenderClear(lTexture.gRenderer);
}

void game::renderScoreSmall()
{
	string s = to_string(lTexture.score);
	signed char l = s.length();
	LTexture image;

	for (signed char i = l - 1; i >= 0; i--)
	{
		signed char number = s[i] - '0';
		if (number == 1)
		{
			image.Load("image/1.png", rate);
		}
		else if (number == 2)
		{
			image.Load("image/2.png", rate);
		}
		else if (number == 3)
		{
			image.Load("image/3.png", rate);
		}
		else if (number == 4)
		{
			image.Load("image/4.png", rate);
		}
		else if (number == 5)
		{
			image.Load("image/5.png", rate);
		}
		else if (number == 6)
		{
			image.Load("image/6.png", rate);
		}
		else if (number == 7)
		{
			image.Load("image/7.png", rate);
		}
		else if (number == 8)
		{
			image.Load("image/8.png", rate);
		}
		else if (number == 9)
		{
			image.Load("image/9.png", rate);
		}
		else
		{
			image.Load("image/0.png", rate);
		}
		image.Render(180 -(l-i-1)*20, 50);
	}
	image.free();
}
void game::renderScore()
{
	ifstream fileIn("Score.txt");
	fileIn >> Score;
	ofstream fileOut("Score.txt");
	string s = to_string(lTexture.score);
	Score=lTexture.score;
	signed char l = s.length();
	LTexture image;

	for (signed char i = l-1; i >= 0; i--)
	{
		signed char number = s[i] - '0';
		if (number == 1)
		{
			image.Load("image/1.png", rate);
		}
		else if (number == 2)
		{
			image.Load("image/2.png", rate);
		}
		else if (number == 3)
		{
			image.Load("image/3.png", rate);
		}
		else if (number == 4)
		{
			image.Load("image/4.png", rate);
		}
		else if (number == 5)
		{
			image.Load("image/5.png", rate);
		}
		else if (number == 6)
		{
			image.Load("image/6.png", rate);
		}
		else if (number == 7)
		{
			image.Load("image/7.png", rate);
		}
		else if (number == 8)
		{
			image.Load("image/8.png", rate);
		}
		else if (number == 9)
		{
			image.Load("image/9.png", rate);
		}
		else
		{
			image.Load("image/0.png", rate);
		}
		image.Render(180 -(l-i-1)*20, 470);
	}
	image.free();

	fileOut << Score;
	fileIn.close();
	fileOut.close();
}


void game::renderBestScore()
{
	ifstream fileIn("bestScore.txt");
	fileIn >> bestScore;
	ofstream fileOut("bestScore.txt");

	if (lTexture.score > bestScore)
	{
		bestScore = lTexture.score;
	}
	string s = to_string(bestScore);
	signed char l = s.length();
	LTexture image;

	for (signed char i = l-1; i >= 0; i--)
	{
		signed char number = s[i] - '0';
		if (number == 1)
		{
			image.Load("image/1.png", rate);
		}
		else if (number == 2)
		{
			image.Load("image/2.png", rate);
		}
		else if (number == 3)
		{
			image.Load("image/3.png", rate);
		}
		else if (number == 4)
		{
			image.Load("image/4.png", rate);
		}
		else if (number == 5)
		{
			image.Load("image/5.png", rate);
		}
		else if (number == 6)
		{
			image.Load("image/6.png", rate);
		}
		else if (number == 7)
		{
			image.Load("image/7.png", rate);
		}
		else if (number == 8)
		{
			image.Load("image/8.png", rate);
		}
		else if (number == 9)
		{
			image.Load("image/9.png", rate);
		}
		else
		{
			image.Load("image/0.png", rate);
		}
		image.Render(180 -(l-i-1)*20, 515);
	}
	image.free();

	fileOut << bestScore;
	fileIn.close();
	fileOut.close();
}

void game::renderStart()
{
	LTexture image;
	image.Load("image/start.png", 1);
	image.Render((lTexture.SCREEN_WIDTH - image.getWidth()) / 2, 60);
	image.Load("image/logo.png", 1);
	image.Render((lTexture.SCREEN_WIDTH - image.getWidth()) / 2, 10);
	image.free();
}

void game::renderBackground()
{
	LTexture image;
	image.Load("image/background.png", 1);
	image.Render(0, 0);
	image.free();
}

void game::renderLand()
{
	LTexture image;
	image.Load("image/land.png", 1);
	image.Render((lTexture.SCREEN_WIDTH - image.getWidth()) / 2, lTexture.SCREEN_HEIGHT- image.getHeight());
	image.free();
}
void game::character()
{
	LTexture image;
	image.Load("image/bird.png", 0.8);
	image.Render(105, 315);
	image.free();
}
void game::renderGameOver()
{
	LTexture image;
	image.Load("image/gameOver.png", 1);
	image.Render((lTexture.SCREEN_WIDTH - image.getWidth()) / 2+15, 250);
	image.free();
}
void game::replay()
{
	LTexture image;
	image.Load("image/replay.png", 1);
	image.Render((lTexture.SCREEN_WIDTH - image.getWidth()) / 2, 375);
	image.free();
}
bool game::checkReplay()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x > (lTexture.SCREEN_WIDTH - 100)/2 && x < (lTexture.SCREEN_WIDTH + 100) / 2 && y > 370 && y < 370 + 60)
	{
		SDL_Delay(300);
		return true;
	}
	return false;
}
void game::Restart()
{
    lTexture.die = false;
    lTexture.score = 0;
    bird.resetTime();
}
