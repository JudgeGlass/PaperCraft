#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL.h>
#include "gamevars.hpp"
#include "maths.hpp"
#include "shapes.hpp"
#include "aabb.hpp"

class Player{
    public:
        Player();
        ~Player();
        void render(SDL_Renderer *renderer);
        void tick();
        void collision();
    private:
        int x;
        int y;
        AABB *collider;
        int acc = 0;
        int vel = 0;
        const int max = 5;
};

#endif