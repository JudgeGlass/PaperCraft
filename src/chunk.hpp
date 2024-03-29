#ifndef CHUNCK_HPP
#define CHUNCK_HPP

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <memory>

#include "gamevars.hpp"
#include "chunkdata.hpp"
#include "SimplexNoise.h"
#include "lighting.hpp"


class Chunk {
    public:
        Chunk(int x, int y, byte chunkWidth, byte chunkHeight, std::vector<std::unique_ptr<Chunk>> *worldChunk);
        ~Chunk();

        void render(SDL_Renderer *renderer);
        void tick();
        void generate();
        void updateCollider();

        ChunkData* getChunkData(){
            return chunkData;
        }

        ChunkData* getBlock(byte x, byte y){
            return &chunkData[x + y * chunkWidth];
        }

        void setBlock(byte x, byte y, ChunkData block);

        int getX(){
            return x;
        }
    private:
        int x;
        int y;
        byte chunkWidth;
        byte chunkHeight;
        ChunkData *chunkData;
        std::vector<std::unique_ptr<Chunk>> *worldChunks;
};


#endif