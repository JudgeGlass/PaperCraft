#ifndef WORLD_HPP
#define WORLD_HPP

#include <SDL2/SDL.h>
#include <vector>


#include "chunk.hpp"

class World{
    public:

    private:
        std::vector<Chunk> worldChunks;
};


#endif