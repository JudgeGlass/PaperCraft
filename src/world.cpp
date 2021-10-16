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
        if(c->getX() * 512 + xOffset + 512 > 0 && c->getX() * 512 + xOffset < 800){
            c->render(renderer);
        }
    }

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

    int chunkX = (mouseX - xOffset) - ((mouseX - xOffset) % 512);

    if(mouseX - xOffset < 0) chunkX -= 512;

    chunkX /= 512;

    std::cout << "CX: " << chunkX << "\tMX:" << mouseX << "\tXOFF: " << xOffset << "\tMOD: " << (mouseX - xOffset % 512) << std::endl;
    if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(0)){
        
    }
}