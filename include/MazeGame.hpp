/* ------------------------------------------*/ 
/* Filename: maze_game/include/MazeGame.hpp  */
/* Date:     11.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#ifndef __MAZEGAME_HPP__
#define __MAZEGAME_HPP__

#include <string>

enum context
{
    MAIN_MENU,
    START_MENU,
    MAPS_MENU,
    IN_GAME,

    NUM_CONTEXTS
};

enum game_state
{
    STOP_RUNNING,
    KEEP_RUNNING,
    LOAD_MAP,

    NUM_STATES
};

enum key_codes
{
    ENTER_KEY = '\n',
    UP_KEY = 'A',
    DOWN_KEY = 'B',
    LEFT_KEY = 'D',
    RIGHT_KEY = 'C'
};

enum move_direction
{
    MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT,

    NUM_DIRECTIONS
};

const std::string maps_dir = "/home/oron/git/maze_game/maps";

void StartGame();
void EndGame();

#endif /* MAZEGAME_HPP */
