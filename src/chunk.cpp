#include "chunk.hpp"

Chunk::Chunk(int x, int y, byte chunkWidth, byte chunkHeight){
    this->x = x;
    this->y = y;
    this->chunkWidth = chunkWidth;
    this->chunkHeight = chunkHeight;

    chunkData = (ChunkData*) malloc(sizeof(ChunkData) * (chunkWidth * chunkHeight));
    generate();
}

void Chunk::generate(){
    for(int x = 0; x < chunkWidth; x++){
        float n = abs(SimplexNoise::noise((float)(x+this->x*chunkWidth) / 30) * 16);
        std::cout << "X: " << x << "\tNoise: " << n << "\tChunkHeight: " << chunkHeight - (int)n << std::endl;
        int lStart = (int)n + 120;
        for(int y = 0; y < chunkHeight; y++){
            if(y > lStart){
                if(y == lStart + 1)
                    chunkData[x + y * chunkWidth] = ChunkData(GRASS, true, true, 0, nullptr);
                else if(y > lStart + 1 && y < lStart + 6)
                    chunkData[x + y * chunkWidth] = ChunkData(DIRT, true, true, 0, nullptr);
                else
                    chunkData[x + y * chunkWidth] = ChunkData(STONE, true, true, 0, nullptr);
            }else{
                chunkData[x + y * chunkWidth] = ChunkData(AIR, true, true, 0, nullptr);
            }
        }
    }
}

void Chunk::render(SDL_Renderer *renderer){
    for(int x = 0; x < chunkWidth; x++){
        for(int y = 0; y < chunkHeight; y++){
            ChunkData *block = &chunkData[x + y * chunkWidth];
            byte id = block->getBlockID();
            int cx = this->x * chunkWidth * 32;
            //std::cout << cx << std::endl;
            if(id != AIR){
                if(id == DIRT)
                    worldTextures->render(renderer, 3, x * 32 + xOffset + cx, y * 32 + yOffset, 2, 16);
                else if(id == GRASS)
                    worldTextures->render(renderer, 2, x * 32 + xOffset + cx, y * 32 + yOffset, 2, 16);
                else if(id == STONE)
                    worldTextures->render(renderer, 0, x * 32 + xOffset + cx, y * 32 + yOffset, 2, 16);
            }
            
            
        }
    }
}

void Chunk::tick(){
    

    
}


Chunk::~Chunk(){
   //delete []chunkData;
}