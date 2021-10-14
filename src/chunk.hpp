#ifndef CHUNCK_HPP
#define CHUNCK_HPP

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <cstdlib>
#include <vector>

#include "gamevars.hpp"
#include "chunkdata.hpp"
#include "SimplexNoise.h"


class Chunk {
    public:
        Chunk(int x, int y, byte chunkWidth, byte chunkHeight);
        ~Chunk();

        void render(SDL_Renderer *renderer);
        void tick();
        void generate();
    private:
        int x;
        int y;
        byte chunkWidth;
        byte chunkHeight;
        ChunkData *chunkData;

};


#endif