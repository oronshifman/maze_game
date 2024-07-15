/* ------------------------------------------*/ 
/* Filename: maze_game/src/Sprite.cpp        */
/* Date:     13.07.2024                      */
/* Author:   Oron                            */
/* ------------------------------------------*/

#include "Sprite.hpp"

Sprite::Sprite()
{
    oldXPos = 0;
    oldYPos = 0;

    currXPos = 0;
    currYPos = 0;

    presentsAs = '0';
}

void Sprite::InitSprite(u16 newXPos, u16 newYPos, char newPresentsAs)
{
    oldXPos = newXPos;
    oldYPos = newYPos;

    currXPos = newXPos;
    currYPos = newYPos;
    presentsAs = newPresentsAs;
}

void Sprite::RequestMove(move_direction direction)
{
    switch(direction)
    {
        case MOVE_UP:
        {
            oldYPos = currYPos--;
        } break;

        case MOVE_DOWN:
        {
            oldYPos = currYPos++;
        } break;

        case MOVE_LEFT:
        {
            oldXPos = currXPos;
            currXPos -= 2;
        } break;

        case MOVE_RIGHT:
        {
            oldXPos = currXPos;
            currXPos += 2;
        } break;

        default:
        {
            // do nothing
        } break;
    }
}

void Sprite::DoMove()
{
    oldXPos = currXPos;
    oldYPos = currYPos;
}

Sprite::~Sprite()
{
    oldXPos = 0;
    oldYPos = 0;

    currXPos = 0;
    currYPos = 0;

    presentsAs = '0';
}