#ifndef MATHS_HPP
#define MATHS_HPP

#include "gamevars.hpp"

static int getChunkIndexFromPoint(int x, int y){
    int chunkIndex = (x - xOffset) - ((x - xOffset) % 512);

    if(x - xOffset < 0) chunkIndex -= 512;

    chunkIndex /= 512;
    return chunkIndex + 16;
}

static int getChunkIndexFromMouse(){
    return getChunkIndexFromPoint(mouseX, mouseY);
}

static int mouseXtoChunkX(){
    int chunkX = (mouseX - xOffset) - ((getChunkIndexFromMouse() - 16) * 512);
    chunkX -= chunkX % 32;
    chunkX /= 32;

    return chunkX;
}

static int mouseYtoChunkY(){
    return ((mouseY - yOffset) - ((mouseY - yOffset) % 32)) / 32;
}

static void updateCursor(int *cx, int *cy){
    *cx = mouseX - ((mouseX - xOffset) % 32);
    if(mouseX - xOffset < 0) *cx-=32;
    *cy = cursorY = mouseY - ((mouseY - yOffset) % 32);
}


#endif