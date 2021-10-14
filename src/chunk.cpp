#include "chunk.hpp"

Chunk::Chunk(int x, int y, byte chunkWidth, byte chunkHeight){
    this->x = x;
    this->y = y;
    this->chunkWidth = chunkWidth;
    this->chunkHeight = chunkHeight;

    chunkData = (ChunkData*) malloc(sizeof(ChunkData) * (chunkWidth * chunkHeight));
    yOffset -= 120 * 32; // Center chunk on screen
}

void Chunk::generate(){
    for(int x = 0; x < chunkWidth; x++){
        float n = abs(SimplexNoise::noise((float)x / 10) * 16);
        //std::cout << "X: " << x << "\tNoise: " << n << "\tChunkHeight: " << chunkHeight - (int)n << std::endl;
        for(int y = 0; y < chunkHeight; y++){
            if(y > (int)n + 120){
                chunkData[x + y * chunkWidth] = ChunkData(DIRT, true, true, 0, nullptr);
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
            if(id != AIR){
                if(id == DIRT)
                    worldTextures->render(renderer, 2, x * 32 + xOffset, y * 32 + yOffset, 2, 16);
                else if(id == STONE)
                    worldTextures->render(renderer, 0, x * 32 + xOffset, y * 32 + yOffset, 2, 16);
            }
            
            
        }
    }
}

void Chunk::tick(){
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    if(keystate[SDL_SCANCODE_A]){
        xOffset += 4;
    }

    if(keystate[SDL_SCANCODE_D]){
        xOffset -= 4;
    }

    if(keystate[SDL_SCANCODE_S]){
        yOffset -= 4;
    }

    if(keystate[SDL_SCANCODE_W]){
        yOffset += 4;
    }

    
}


Chunk::~Chunk(){
    delete chunkData;
}