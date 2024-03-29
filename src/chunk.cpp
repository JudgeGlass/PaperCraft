#include "chunk.hpp"
#include "font.hpp"

Chunk::Chunk(int x, int y, byte chunkWidth, byte chunkHeight, std::vector<std::unique_ptr<Chunk>> *worldChunks){
    this->x = x;
    this->y = y;
    this->chunkWidth = chunkWidth;
    this->chunkHeight = chunkHeight;
    this->worldChunks = worldChunks;

    chunkData = (ChunkData*) malloc(sizeof(ChunkData) * (chunkWidth * chunkHeight));
    generate();
}

void Chunk::generate(){
    for(int x = 0; x < chunkWidth; x++){
        float n = abs(SimplexNoise::noise((float)(x+this->x*chunkWidth + ((float)rand() / (RAND_MAX))) / 30) * 16);
        //std::cout << "X: " << x << "\tNoise: " << n << "\tChunkHeight: " << chunkHeight - (int)n << std::endl;
        int lStart = (int)n + 120;
        for(int y = 0; y < chunkHeight; y++){
            if(y > lStart){
                if(y == lStart + 1)
                    chunkData[x + y * chunkWidth] = ChunkData(GRASS, true, true, false, 0, nullptr);
                else if(y > lStart + 1 && y < lStart + 6)
                    chunkData[x + y * chunkWidth] = ChunkData(DIRT, true, true, false, 0, nullptr);
                else
                    chunkData[x + y * chunkWidth] = ChunkData(STONE, true, true, false, 0, nullptr);
            }else{
                chunkData[x + y * chunkWidth] = ChunkData(AIR, true, true, true, 0, nullptr);
            }
        }
    }

    if(this->x == 0)
        caclcLightLevel(chunkData);
    updateCollider();
}

void Chunk::updateCollider(){
    for(int x = 0; x < chunkWidth; x++){
        for(int y = 0; y < chunkHeight; y++){
            if(chunkData[x + y * chunkWidth].getBlockID() != AIR){
                ChunkData *ba = nullptr;
                ChunkData *bb = nullptr;
                ChunkData *bl = nullptr;
                ChunkData *br = nullptr;

                if(y - 1 >= 0)
                    ba = &chunkData[x + (y-1) * chunkWidth];

                if(y + 1 <= 255)
                    bb = &chunkData[x + (y+1) * chunkWidth];

                if((x == 0 || x == 15) && (ba->getBlockID() == AIR || bb->getBlockID() == AIR)){
                    AABB *collider = new AABB(x * 32 + (this->x * chunkWidth * 32), y * 32, 32, 32, 0);

                    if(chunkData[x + y * chunkWidth].getCollider() == nullptr)
                        chunkData[x + y * chunkWidth].setCollider(collider);
                    
                    continue;
                }

                if(x - 1 >= 0)
                    bl = &chunkData[(x-1) + y * chunkWidth];
                
                if(x + 1 <= 15)
                    br = &chunkData[(x+1) + y * chunkWidth];
                
                if(ba == nullptr || bb == nullptr || bl == nullptr || br == nullptr) continue;


                if(ba->getBlockID() == AIR || bb->getBlockID() == AIR || bl->getBlockID() == AIR || br->getBlockID() == AIR){
                    AABB *collider = new AABB(x * 32 + (this->x * chunkWidth * 32), y * 32, 32, 32, 0);
                    if(chunkData[x + y * chunkWidth].getCollider() == nullptr)
                        chunkData[x + y * chunkWidth].setCollider(collider);
                }
            }

        }
    }
}

void Chunk::render(SDL_Renderer *renderer){
    for(int x = 0; x < chunkWidth; x++){

        if(x == 0 || x == 16){
            SDL_RenderDrawLine(renderer, x+xOffset+(this->x * chunkWidth * 32), 3000, x+xOffset+(this->x * chunkWidth * 32), -3000);
        }


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
            
            if(block->getCollider() != nullptr)
                block->getCollider()->render(renderer);

            if(this->x == 0){
                drawString(x * 32 + xOffset + cx + 8, y * 32 + yOffset + 8, std::to_string(block->getLightLevel()), 0xFFFFFF, 1, fontTextures, renderer);
            }
        }
    }
}

void Chunk::tick(){
    for(int i = 0; i < chunkWidth * chunkHeight; i++){
        if(chunkData[i].getCollider() != nullptr)
            chunkData[i].getCollider()->updatePos(xOffset, yOffset);
    }

    
}

void Chunk::setBlock(byte x, byte y, ChunkData block){
    chunkData[x + y * chunkWidth] = block;
}


Chunk::~Chunk(){
   delete []chunkData;
}