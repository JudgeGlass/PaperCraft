#include "world.hpp"
#include "font.hpp"

World::World(){
    tempChunk = new Chunk(0, 0, 16, 16);
    tempChunk->generate();
}

void World::render(SDL_Renderer *renderer){
    tempChunk->render(renderer);
    drawString(5, 5, "PaperCraft", 0xFFFFFF, 2, fontTextures, renderer);
}

void World::tick(){

}