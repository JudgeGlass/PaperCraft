#include "player.hpp"


Player::Player(std::vector<std::unique_ptr<Chunk>> *worldChunks){
    this->worldChunks = worldChunks;
    x = 800 / 2;
    y = 480 / 2;

    collider = new AABB(x, y, 32, 32, 255);
}

void Player::render(SDL_Renderer *renderer){
    drawRectangle(renderer, x - 16, y - 16, 32, 32, 0x000000, true);
}

void Player::tick(){

    //std::cout << "Index: " << getChunkIndexFromPoint(x, y) << std::endl;



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

    collision();
}

void Player::collision(){
    AABB *temp = new AABB(x-16, y+4, 32, 32, 255);

    //Chunk *chunk = 


    delete temp;
}

Player::~Player(){
    delete collider;
}