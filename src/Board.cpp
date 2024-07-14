/* ------------------------------------------*/ 
/* Filename: maze_game/src/Board.cpp         */
/* Date:     11.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

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
    map = nullptr;
    player = nullptr;
    goal = nullptr;
}

void Board::Draw()
{
}
