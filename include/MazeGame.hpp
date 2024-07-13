/* ------------------------------------------*/ 
/* Filename: maze_game/code/MazeGame.hpp     */
/* Date:     11.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#ifndef __MAZEGAME_HPP__
#define __MAZEGAME_HPP__

#include <termios.h> // struct termios
#include <fstream> // ifstream

#include "Buffer.hpp"
#include "Sprite.hpp"
#include "my_int.h"

enum context
{
    MAIN_MENU,
    IN_GAME,

    NUM_CONTEXTS
};

enum ascii_arrows
{
    UP = 38,
    DOWN = 40,
    LEFT = 37,
    RIGHT = 39
};

enum main_menu_choice
{
    START, QUIT,

    NUM_CHOICES
};

enum move_direction
{
    UP, DOWN, LEFT, RIGHT,

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
    b8 InitGameScreen();
    // b8 LoadNewMap(std::ifstream &loadedMap);
    b8 ReadWidthAndHeight(std::ifstream &loadedMap);

    void InGameInput(char key);
    void MainMenuInput(char key);

    Buffer map;
    Sprite player;
    Sprite goal;
};

#endif /* MAZEGAME_HPP */
