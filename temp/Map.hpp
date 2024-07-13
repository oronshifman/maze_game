/* ------------------------------------------*/ 
/* Filename: maze_game/code/Map.hpp          */
/* Date:     11.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <fstream> // ifstream

#include "my_int.h"

enum map_dimensions
{
    WIDTH, HEIGHT,

    NUM_DIMENSIONS
};

enum position
{
    X, Y,

    NUM_PLANES
};

enum move_direction
{
    UP, DOWN, LEFT, RIGHT,

    NUM_DIRECTIONS
};

class Map 
{
public:
    Map(std::string fileName);
    ~Map();

    b8 DrawMap();

private:

    Buffer buf;
};

#endif /* MAP_HPP */