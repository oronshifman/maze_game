/* ------------------------------------------*/ 
/* Filename: maze_game/include/Sprite.hpp    */
/* Date:     13.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include "my_int.h"

class Sprite
{
public:
    Sprite();
    ~Sprite();

    void InitSprite(u16 xPos, u16 yPos, char presentsAs);
    
    u16 xPos;
    u16 yPos;

    char presentsAs;
};

#endif /* SPRITE_HPP */
