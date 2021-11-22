#ifndef CHUNKDATA_HPP
#define CHUNKDATA_HPP

#include "gamevars.hpp"
#include "aabb.hpp"

class ChunkData{
    public:
        ChunkData(byte blockID, bool isBreakable, bool isForeground, bool isSky, int durability, AABB *collider){
            this->blockID = blockID;
            this->isBreakable = isBreakable;
            this->isForeground = isForeground;
            this->isSky = isSky;
            this->durability = durability;
            this->collider = collider;
            lightLvl = 15;
        }

        byte getBlockID(){
            return blockID;
        }

        void setLightLevel(byte value){
            lightLvl = value;
        }

        byte getLightLevel(){
            return lightLvl;
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
        bool isSky;

        byte lightLvl;

        AABB *collider;
};



#endif