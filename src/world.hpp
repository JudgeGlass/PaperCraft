#ifndef WORLD_HPP
#define WORLD_HPP

#include <SDL2/SDL.h>
#include <vector>


#include "chunk.hpp"

class World{
    public:
        World();
        void render(SDL_Renderer *renderer);
        void tick();

    private:
        std::vector<Chunk> worldChunks;
        Chunk *tempChunk;
};


#endif