#ifndef WORLD_HPP
#define WORLD_HPP

#include <SDL2/SDL.h>
#include <vector>
#include <memory>


#include "chunk.hpp"
#include "shapes.hpp"
#include "player.hpp"
#include "maths.hpp"

class World{
    public:
        World();
        ~World();
        void render(SDL_Renderer *renderer);
        void tick();

        std::vector<std::unique_ptr<Chunk>>* getChunks(){
            return &worldChunks;
        }

    private:
        std::vector<std::unique_ptr<Chunk>> worldChunks;
        Player *player;
};


#endif