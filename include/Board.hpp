/* ------------------------------------------*/ 
/* Filename: maze_game/src/Board.hpp         */
/* Date:     11.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "Buffer.hpp"
#include "Sprite.hpp"

class Board
{
public:
    Board();
    ~Board();

    void InitBoard(Buffer *newMap, Sprite *newPlayer, Sprite *newGoal);
    void Draw();

private:
    Buffer *map;
    Sprite *player;
    Sprite *goal;
};

#endif /* BOARD_HPP */
