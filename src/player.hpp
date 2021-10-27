#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "gamevars.hpp"
#include "maths.hpp"
#include "shapes.hpp"
#include "aabb.hpp"
#include "chunk.hpp"

class Player{
    public:
        Player(std::vector<std::unique_ptr<Chunk>> *worldChunks);
        ~Player();
        void render(SDL_Renderer *renderer);
        void tick();
        void collision();
    private:
        int x;
        int y;
        AABB *collider;
        std::vector<std::unique_ptr<Chunk>> *worldChunks;
        float acc = 0;
        float velX = 0;
        float velY = 0;
        const int max = 5;
};

#endif