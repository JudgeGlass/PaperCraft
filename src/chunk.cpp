#include "chunk.hpp"

Chunk::Chunk(int x, int y, byte chunkWidth, byte chunkHeight){
    this->x = x;
    this->y = y;
    this->chunkWidth = chunkWidth;
    this->chunkHeight = chunkHeight;

    chunkData = (ChunkData*) malloc(sizeof(ChunkData) * (chunkWidth * chunkHeight));
}

void Chunk::generate(){
    for(int x = 0; x < chunkWidth; x++){
        for(int y = 0; y < chunkHeight; y++){
            chunkData[x + y * chunkWidth] = ChunkData(DIRT, true, true, 10);
        }
    }
}

void Chunk::render(SDL_Renderer *renderer){
    for(int x = 0; x < chunkWidth; x++){
        for(int y = 0; y < chunkHeight; y++){
            byte id = chunkData[x + y * chunkWidth].getBlockID();
            worldTextures->render(renderer, 2, x * 32, y * 32, 2, 16);
        }
    }
}

void Chunk::tick(){

}


Chunk::~Chunk(){
    delete chunkData;
}