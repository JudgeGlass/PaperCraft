#ifndef LIGHTING_HPP
#define LIGHTING_HPP

#include <cmath>
#include "gamevars.hpp"
#include "chunkdata.hpp"

static void caclcLightLevel(ChunkData *chunkData){
    for(byte x = 0; x < 16; x++){
        for(byte y = 0; y < 256; y++){
            byte lightLvlCurrent = chunkData[x + y * 16].getLightLevel();
            
            byte lightlvlLeft;
            byte lightlvlRight;
            byte lightlvlTop;
            byte lightlvlBottom;

            if(x - 1 > -1){
                lightlvlLeft = chunkData[(x-1) + y * 16].getLightLevel();
            }

            if(x + 1 < 16){
                lightlvlRight = chunkData[(x+1) + y * 16].getLightLevel();
            }

            if(y - 1 > -1){
                lightlvlTop = chunkData[x + (y-1) * 16].getLightLevel();
            }

            if(y + 1 < 256){
                lightlvlBottom = chunkData[x + (y+1) * 16].getLightLevel();
            }

            if(chunkData[x + y * 16].getBlockID() != AIR){
                 byte small = lightlvlBottom;
                 if(lightlvlBottom > lightlvlTop) small = lightlvlTop;
                 if(lightlvlTop > lightlvlLeft) small = lightlvlLeft;
                 if(lightlvlLeft > lightlvlRight) small = lightlvlRight;


                 chunkData[x + y * 16].setLightLevel(small - 1);
            }
        }
    }
}

#endif