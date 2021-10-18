#ifndef SHAPES_HPP
#define SHAPES_HPP

#include<SDL2/SDL.h>

static void drawRectangle(SDL_Renderer *renderer, int x, int y, int w, int h, int color, bool fillRect){
    int r = (color & 0xFF0000) >> 16;
	int g = (color & 0xFF00) >> 8;
	int b = (color & 0xFF);

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    if(fillRect) SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderDrawRect(renderer, &rect);
}

#endif