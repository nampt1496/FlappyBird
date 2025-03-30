#include "game.h"
#include "lib.h"
#include <iostream>

void game::takeInput()
{
    while(SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            userInput.Type = input::QUIT;
            quit = true;
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN || (event.type == SDL_KEYDOWN &&
		(event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_UP) && event.key.repeat == 0) )
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
    free();
    releaseGraphic();
}

void game::releaseGraphic()
{
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    SDL_DestroyRenderer( gRenderer );
    gRenderer = NULL;
    IMG_Quit();

    SDL_Quit();
}

bool game::initGraphic()
{
	bool success = true;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		gWindow = SDL_CreateWindow( "Flappy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}


			}
		}
	}

	return success;
}

void game::display()
{
    SDL_RenderPresent(gRenderer);
    SDL_RenderClear(gRenderer);
}

void game::renderScoreSmall()
{
	string s = to_string(score);
	signed char l = s.length();
	LTexture image;

	for (signed char i = l - 1; i >= 0; i--)
	{
		signed char number = s[i] - '0';
		if (number == 1)
		{
			image.Load("image/1.png", scaleNumberS);
		}
		else if (number == 2)
		{
			image.Load("image/2.png", scaleNumberS);
		}
		else if (number == 3)
		{
			image.Load("image/3.png", scaleNumberS);
		}
		else if (number == 4)
		{
			image.Load("image/4.png", scaleNumberS);
		}
		else if (number == 5)
		{
			image.Load("image/5.png", scaleNumberS);
		}
		else if (number == 6)
		{
			image.Load("image/6.png", scaleNumberS);
		}
		else if (number == 7)
		{
			image.Load("image/7.png", scaleNumberS);
		}
		else if (number == 8)
		{
			image.Load("image/8.png", scaleNumberS);
		}
		else if (number == 9)
		{
			image.Load("image/9.png", scaleNumberS);
		}
		else
		{
			image.Load("image/0.png", scaleNumberS);
		}
		image.Render(260 - image.getWidth() * (l-i-1) * 0.75 - 5 * (l-i-1)-80, 50);
	}
	image.free();
}
void game::renderScore()
{
	ifstream fileIn("Score.txt");
	fileIn >> Score;
	ofstream fileOut("Score.txt", ios::trunc);
	string s = to_string(score);
	Score=score;
	signed char l = s.length();
	LTexture image;

	for (signed char i = l-1; i >= 0; i--)
	{
		signed char number = s[i] - '0';
		if (number == 1)
		{
			image.Load("image/1.png", scaleNumberS);
		}
		else if (number == 2)
		{
			image.Load("image/2.png", scaleNumberS);
		}
		else if (number == 3)
		{
			image.Load("image/3.png", scaleNumberS);
		}
		else if (number == 4)
		{
			image.Load("image/4.png", scaleNumberS);
		}
		else if (number == 5)
		{
			image.Load("image/5.png", scaleNumberS);
		}
		else if (number == 6)
		{
			image.Load("image/6.png", scaleNumberS);
		}
		else if (number == 7)
		{
			image.Load("image/7.png", scaleNumberS);
		}
		else if (number == 8)
		{
			image.Load("image/8.png", scaleNumberS);
		}
		else if (number == 9)
		{
			image.Load("image/9.png", scaleNumberS);
		}
		else
		{
			image.Load("image/0.png", scaleNumberS);
		}
		image.Render(260 - image.getWidth()*(l-i-1)*0.75 - 5*(l-i-1)-80, 470);
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
	ofstream fileOut("bestScore.txt", ios::trunc);

	if (score > bestScore)
	{
		bestScore = score;
	}
	string s = to_string(bestScore);
	signed char l = s.length();
	LTexture image;

	for (signed char i = l-1; i >= 0; i--)
	{
		signed char number = s[i] - '0';
		if (number == 1)
		{
			image.Load("image/1.png", scaleNumberS);
		}
		else if (number == 2)
		{
			image.Load("image/2.png", scaleNumberS);
		}
		else if (number == 3)
		{
			image.Load("image/3.png", scaleNumberS);
		}
		else if (number == 4)
		{
			image.Load("image/4.png", scaleNumberS);
		}
		else if (number == 5)
		{
			image.Load("image/5.png", scaleNumberS);
		}
		else if (number == 6)
		{
			image.Load("image/6.png", scaleNumberS);
		}
		else if (number == 7)
		{
			image.Load("image/7.png", scaleNumberS);
		}
		else if (number == 8)
		{
			image.Load("image/8.png", scaleNumberS);
		}
		else if (number == 9)
		{
			image.Load("image/9.png", scaleNumberS);
		}
		else
		{
			image.Load("image/0.png", scaleNumberS);
		}
		image.Render(260 - image.getWidth()*(l-i-1)*0.75 - 5*(l-i-1)-80, 515);
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
	image.Render((SCREEN_WIDTH - image.getWidth()) / 2, 60);
	image.Load("image/logo.png", 1);
	image.Render((SCREEN_WIDTH - image.getWidth()) / 2, 10);
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
	image.Render((SCREEN_WIDTH - image.getWidth()) / 2, SCREEN_HEIGHT- image.getHeight());
	image.free();
}
void game::character()
{
	LTexture image;
	image.Load("image/bird.png", 0.8);
	image.Render(105, 315);
	image.free();
}
bool game::changeTheme()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (((x > 149 && x < 149+13)  || (x > 88 && x < 88 + 13)) && (y > 322 && y < 322 + 16))
	{
		return true;
	}
	return false;
}
void game::renderGameOver()
{
	LTexture image;
	image.Load("image/gameOver.png", 1);
	image.Render((SCREEN_WIDTH - image.getWidth()) / 2+15, 250);
	image.free();
}
void game::replay()
{
	LTexture image;
	image.Load("image/replay.png", 1);
	image.Render((SCREEN_WIDTH - image.getWidth()) / 2, 375);
	image.free();
}
bool game::checkReplay()
{
    SDL_Delay(100);
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x > (SCREEN_WIDTH - 100)/2 && x < (SCREEN_WIDTH + 100) / 2 && y > 380 && y < 380 + 60)
	{
		return true;
	}
	return false;
}
void game::Restart()
{
    die = false;
    score = 0;
    bird.resetTime();
}
