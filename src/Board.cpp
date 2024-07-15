/* ------------------------------------------*/ 
/* Filename: maze_game/src/Board.cpp         */
/* Date:     11.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#include <stdio.h>

#include "Board.hpp"

Board::Board()
{
    map = nullptr;
    player = nullptr;
    goal = nullptr;
}

void Board::InitBoard(Buffer *newMap, Sprite *newPlayer, Sprite *newGoal)
{
    map = newMap;
    player = newPlayer;
    goal = newGoal;
}

Board::~Board()
{
}

void Board::Draw()
{
    if(player->oldXPos != player->currXPos ||
       player->oldYPos != player->currYPos)
    {
        *(map->indexBuffer(player->oldYPos, player->oldXPos)) = '.';
        *(map->indexBuffer(player->currYPos, player->currXPos)) = player->presentsAs;

        player->DoMove();
    }

    for(u8 row = 0; row < map->height; ++row)
    {
        for(u8 col = 0; col < map->width; ++col)
        {
            printf("%c", *(map->indexBuffer(row, col)));
        }
    }
}
