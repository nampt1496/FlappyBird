#include "game.h"
#include <iostream>

bool LTexture::quit = false;
bool LTexture::die = true;
int LTexture::score = 0;
SDL_Window* LTexture::gWindow = NULL;
SDL_Renderer* LTexture::gRenderer = NULL;
SDL_Event LTexture::event;

LTexture::LTexture()
{
	Texture = NULL;
}

int LTexture::getWidth()
{
	return tWidth;
}

int LTexture::getHeight()
{
	return tHeight;
}

void LTexture::free()
{
	if( Texture != NULL )
	{
		SDL_DestroyTexture( Texture );
		Texture = NULL;
		tWidth = 0;
		tHeight = 0;
	}
}

void LTexture::Render(int x,int y,int angle, SDL_Rect* clip, SDL_RendererFlip flip)
{
	SDL_Rect Rec_Render = { x, y, tWidth, tHeight };

    if( clip != NULL )
	{
		Rec_Render.w = clip->w ;
		Rec_Render.h = clip->h ;
	}

    SDL_RenderCopyEx( gRenderer, Texture, clip, &Rec_Render, angle, NULL, flip );
}

bool LTexture::Load(string path, double rate)
{
	free();

	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		 printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{

        Texture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( Texture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			tWidth = (loadedSurface->w) * rate;
			tHeight = (loadedSurface->h) * rate;
		}

		SDL_FreeSurface( loadedSurface );
	}

	return Texture != NULL;

}

bool LTexture::isNULL()
{
    if (Texture == NULL) return true;
    return false;
}

void position::getPos(const int x,const int y)
{
    this->x = x;
    this->y = y;
}
