#include "world.hpp"
#include "font.hpp"

World::World(){
    
    for(int x = -16; x < 16; x++){
        //Chunk *c = new Chunk(x, 0, 16, 255);
        worldChunks.push_back(std::make_unique<Chunk>(x, 0, 16, 255));
    }

    yOffset -= 120 * 32;
}

void World::render(SDL_Renderer *renderer){
    
    for(auto &c: worldChunks){
        c->render(renderer);
    }
    drawString(5, 5, "PaperCraft", 0xFFFFFF, 2, fontTextures, renderer);
}

void World::tick(){
    
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