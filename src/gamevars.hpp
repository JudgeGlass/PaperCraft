#ifndef GAMEVARS_HPP
#define GAMEVARS_HPP

#include "texture.hpp"

inline const std::string GAME_VERSION = "0.0.1_3a";

typedef unsigned char byte;

inline int xOffset;
inline int yOffset;

inline int mouseX = 0;
inline int mouseY = 0;
inline int cursorX = 0;
inline int cursorY = 0;

inline int fps;
inline int currentChunkIndex;

inline bool showHitbox = true;
inline bool mouseButton1Clicked = false;


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