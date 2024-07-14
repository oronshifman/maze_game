/* ------------------------------------------*/ 
/* Filename: maze_game/src/Sprite.cpp        */
/* Date:     13.07.2024                      */
/* Author:   Oron                            */
/* ------------------------------------------*/

#include "Sprite.hpp"

Sprite::Sprite()
{
    xPos = 0;
    yPos = 0;

    presentsAs = '0';
}

void Sprite::InitSprite(u16 newXPos, u16 newYPos, char newPresentsAs)
{
    xPos = newXPos;
    yPos = newYPos;
    presentsAs = newPresentsAs;
}

Sprite::~Sprite()
{
    xPos = 0;
    yPos = 0;

    presentsAs = '0';
}