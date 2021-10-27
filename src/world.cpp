#include "world.hpp"
#include "font.hpp"

World::World(){
    srand(time(0));
    for(int x = -16; x < 16; x++){
        //Chunk *c = new Chunk(x, 0, 16, 255);
        worldChunks.push_back(std::make_unique<Chunk>(x, 0, 16, 255, &worldChunks));
    }

    player = new Player(&worldChunks);
    yOffset -= 120 * 32;
}

void World::render(SDL_Renderer *renderer){
    
    for(auto &c: worldChunks){
        if(c->getX() * 512 + xOffset + 512 > 0 && c->getX() * 512 + xOffset < 800){
            c->render(renderer);
        }

        if(c->getX() == currentChunkIndex - 16){
            int chunkWidth = 16;
            int chunkHeight = 255;
            for(int x = 0; x < chunkWidth; x++){
                for(int y = 0; y < chunkHeight; y++){
                    if(c->getChunkData()[x + y * chunkWidth].getBlockID() == AIR){
                        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    }else{
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    }
                    SDL_RenderDrawPoint(renderer, x + 5, (255+y) + 50);
                }
            }
        }
    }

    player->render(renderer);

    drawRectangle(renderer, cursorX, cursorY, 32, 32, 0x000000, false);

    drawStringShadowed(5, 5, "PaperCraft - by JudgeGlass", 0xFFFFFF, 2, fontTextures, renderer);
    drawString(5, 20, std::to_string(fps), 0xFFFFFF, 2, fontTextures, renderer);
}

void World::tick(){
    for(auto &c: worldChunks){
        if(c->getX() * 512 + xOffset + 512 > 0 && c->getX() * 512 + xOffset < 800){
            c->tick();
        }
            
    }
    
    
    player->tick();
    
    currentChunkIndex = getChunkIndexFromMouse();
    int chunkX = mouseXtoChunkX();
    int chunkY = mouseYtoChunkY();
    updateCursor(&cursorX, &cursorY);
   

    if(mouseButton1Clicked){
        worldChunks[currentChunkIndex]->setBlock(chunkX, chunkY, ChunkData(AIR, true, true, 0, nullptr));
        worldChunks[currentChunkIndex]->updateCollider();
    }
}

World::~World(){
    delete player;
}