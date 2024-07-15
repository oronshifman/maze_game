/* ------------------------------------------*/ 
/* Filename: maze_game/include/Sprite.hpp    */
/* Date:     13.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include "MazeGame.hpp"
#include "my_int.h"

class Sprite
{
public:
    Sprite();
    ~Sprite();

    void InitSprite(u16 newXPos, u16 newYPos, char presentsAs);
    
    /**
     * changes currXPos/currYPos
     */
    void RequestMove(move_direction direction);
    /**
     * updates oldXPos/oldYPos after sprite was moved by Board if move in map and not though wall
     */
    void DoMove();

    u16 oldXPos;
    u16 oldYPos;

    u16 currXPos;
    u16 currYPos;

    char presentsAs;
};

#endif /* SPRITE_HPP */
