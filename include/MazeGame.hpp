/* ------------------------------------------*/ 
/* Filename: maze_game/include/MazeGame.hpp  */
/* Date:     11.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#ifndef __MAZEGAME_HPP__
#define __MAZEGAME_HPP__

#include <termios.h> // struct termios
#include <fstream> // ifstream

#include "Buffer.hpp"
#include "Sprite.hpp"
#include "Board.hpp"
#include "Screen.hpp"
#include "Menus.hpp"
#include "my_int.h"

enum key_codes
{
    ESC_KEY = 27,
    ENTER_KEY = 150,
    UP_KEY = 38,
    DOWN_KEY = 40,
    LEFT_KEY = 37,
    RIGHT_KEY = 39
};

enum move_direction
{
    MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT,

    NUM_DIRECTIONS
};

class MazeGame 
{
public:
    MazeGame();
    ~MazeGame();

    b8 DrawBoard();
    void HandleInput(context context);


    b8 running = 1;
    b8 win = 0;

private:
    b8 ConfigTerminal();
    // b8 LoadNewMap(std::ifstream &loadedMap);
    b8 ReadWidthAndHeight(std::ifstream &loadedMap);

    void InGameInput(char key);

    Menus menus;
    Board board;

    Buffer map;
    Sprite player;
    Sprite goal;
};

#endif /* MAZEGAME_HPP */
