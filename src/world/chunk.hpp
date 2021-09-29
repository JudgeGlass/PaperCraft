#ifndef CHUNCK_HPP
#define CHUNCK_HPP

#include "gamevars.hpp"
#include "chunkdata.hpp"
#include <stdlib.h>


class Chunk {
    public:
        Chunk(byte chunkWidth, byte chunkHeight);
    private:
        byte chunkWidth;
        byte chunkHeight;
        ChunkData *chunkData;

        ~Chunk();

};


#endif