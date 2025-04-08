#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class position
{
public:
    int x, y, angle, state;
    void getPos(const int x, const int y);
};

class LTexture
{
public:
    LTexture();

    ~LTexture() {}

    bool isNULL();

    bool Load(string path, double rate = 1);

    int getWidth();
    int getHeight();

    void free();
    void Render(int x,int y,int angle = 0, SDL_Rect* clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    SDL_Texture* Texture;

    int tWidth;
    int tHeight;

    static SDL_Window* gWindow;
    static SDL_Renderer* gRenderer;
    static SDL_Event event;
    static bool quit;
    static bool die;
    static int score;

    static const int SCREEN_WIDTH = 525;
    static const int SCREEN_HEIGHT = 625;
    static const int BIRD_WIDTH = 50;
    static const int BIRD_HEIGHT = 35;
    static const int PIPE_SPACE = 140;
    static const int TOTAL_PIPE = 4;
    static const int PIPE_DISTANCE = 220;
    static const int LAND_HEIGHT = 140;
};
