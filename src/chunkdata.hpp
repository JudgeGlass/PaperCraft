#ifndef CHUNKDATA_HPP
#define CHUNKDATA_HPP

#include "gamevars.hpp"
#include "aabb.hpp"

class ChunkData{
    public:
        ChunkData(byte blockID, bool isBreakable, bool isForeground, int durability, AABB *collider){
            this->blockID = blockID;
            this->isBreakable = isBreakable;
            this->isForeground = isForeground;
            this->durability = durability;
            this->collider = collider;
        }

        byte getBlockID(){
            return blockID;
        }

        void setCollider(AABB *collider){
            this->collider = collider;
        }

        AABB* getCollider(){
            return collider;
        }
    private:
        int durability;
        byte blockID;
        bool isBreakable;
        bool isForeground;

        AABB *collider;
};



#endif