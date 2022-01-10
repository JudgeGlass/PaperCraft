#include <iostream>
#include "game.hpp"
#include "gamevars.hpp"

/*
    PaperCraft
    Copyright (c) 2020-2021 Hunter Wilcox
                            Zicron Technologies

    Requirements:
        - SDL 2
        - SDL_Image
        - std=c++17
*/

// Where is all began...
int main(int argv, char** args){
    std::cout << "Starting program....." << std::endl;
    std::string title = "PaperCraft - v" + GAME_VERSION;
    Game game(800, 480, title);
    game.init();
    game.loop();

    return 0;
}