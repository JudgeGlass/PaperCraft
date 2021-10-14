#ifndef GAMEVARS_HPP
#define GAMEVARS_HPP

#include "texture.hpp"

typedef unsigned char byte;

inline int xOffset;
inline int yOffset;

inline int fps;


inline Texture *entityTextures;
inline Texture *fontTextures;
inline Texture *worldTextures;

/*
*  List of block IDs 
*/

inline const byte AIR = 0;
inline const byte GRASS = 1;
inline const byte DIRT = 2;
inline const byte STONE = 3;

#endif