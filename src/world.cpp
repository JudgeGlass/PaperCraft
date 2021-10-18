#include "world.hpp"
#include "font.hpp"

World::World(){
    srand(time(0));
    for(int x = -16; x < 16; x++){
        //Chunk *c = new Chunk(x, 0, 16, 255);
        worldChunks.push_back(std::make_unique<Chunk>(x, 0, 16, 255));
    }

    yOffset -= 120 * 32;
}

void World::render(SDL_Renderer *renderer){
    
    for(auto &c: worldChunks){
        if(c->getX() * 512 + xOffset + 512 > 0 && c->getX() * 512 + xOffset < 800){
            c->render(renderer);
        }

        if(c->getX() == currentChunkIndex){
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

    drawRectangle(renderer, cursorX, cursorY, 32, 32, 0xFFFFFF, false);

    drawStringShadowed(5, 5, "PaperCraft - by JudgeGlass", 0xFFFFFF, 2, fontTextures, renderer);
    drawString(5, 20, std::to_string(fps), 0xFFFFFF, 2, fontTextures, renderer);
}

void World::tick(){
    for(auto &c: worldChunks){
        c->tick();
    }
    
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

    if(keystate[SDL_SCANCODE_H]){
        SDL_Delay(200);
        showHitbox = !showHitbox;
    }

    int chunkIndex = (mouseX - xOffset) - ((mouseX - xOffset) % 512);

    if(mouseX - xOffset < 0) chunkIndex -= 512;

    chunkIndex /= 512;
    currentChunkIndex = chunkIndex;
    
    int chunkX = (mouseX - xOffset) - (chunkIndex * 512);
    chunkX -= chunkX % 32;
    chunkX /= 32;

    cursorX = mouseX - ((mouseX - xOffset) % 32);
    if(mouseX - xOffset < 0) cursorX-=32;
    cursorY = mouseY - ((mouseY - yOffset) % 32);

    int chunkY = ((mouseY - yOffset) - ((mouseY - yOffset) % 32)) / 32;

    

    if(mouseButton1Clicked){
        worldChunks[currentChunkIndex+16]->setBlock(chunkX, chunkY, ChunkData(AIR, true, true, 0, nullptr));
        worldChunks[currentChunkIndex+16]->updateCollider();
    }
}