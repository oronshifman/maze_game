/* ------------------------------------------*/ 
/* Filename: maze_game/code/main.cpp         */
/* Date:     11.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#include <stdio.h>

#include "MazeGame.hpp"

int main(void)
{
	MazeGame game;

    while(game.running)
    {
        game.HandleInput(MAIN_MENU);
    }

	return 0;
}

