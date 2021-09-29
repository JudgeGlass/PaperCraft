#ifndef CHUNKDATA_HPP
#define CHUNKDATA_HPP

#include "gamevars.hpp"

class ChunkData{
    public:
        ChunkData(byte blockID, bool isBreakable, bool isForeground, int durability){
            this->blockID = blockID;
            this->isBreakable = isBreakable;
            this->isForeground = isForeground;
            this->durability = durability;
        }
    private:
        int durability;
        byte blockID;
        bool isBreakable;
        bool isForeground;
};



#endif