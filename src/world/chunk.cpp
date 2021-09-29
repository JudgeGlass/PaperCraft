#include "chunk.hpp"

Chunk::Chunk(byte chunkWidth, byte chunkHeight){
    this->chunkWidth;
    this->chunkHeight;

    chunkData = (ChunkData*) malloc(sizeof(ChunkData) * (chunkWidth * chunkHeight));
}


Chunk::~Chunk(){
    delete chunkData;
}