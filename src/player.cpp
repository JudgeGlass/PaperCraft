#include "player.hpp"


Player::Player(){
    x = 800 / 2;
    y = 480 / 2;
}

void Player::render(SDL_Renderer *renderer){
    drawRectangle(renderer, x - 16, y - 16, 32, 32, 0x000000, true);
}

void Player::tick(){

    std::cout << "Index: " << getChunkIndexFromPoint(x, y) << std::endl;



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
}

void Player::collision(){
    AABB *temp;

    


    delete temp;
}

Player::~Player(){
    delete collider;
}