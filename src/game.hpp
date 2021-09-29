#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

#include "texture.hpp"
#include "sound.hpp"
#include "world.hpp"
#include "gamevars.hpp"


class Game{
    public:
        Game(int width, int height, std::string &title);
        ~Game();
        void init();
        void loop();
        void handleEvents();
        void render();
        bool quit;

    private:
        int width;
        int height;
        std::string title;
        SDL_Window *window;
        SDL_Renderer *renderer;

        World *world;
};

#endif