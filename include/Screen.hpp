/* ------------------------------------------*/ 
/* Filename: maze_game/include/Screen.hpp    */
/* Date:     13.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#ifndef __SCREEN_HPP__
#define __SCREEN_HPP__

#include "Menus.hpp"
#include "Board.hpp"
#include "my_int.h"

enum context
{
    MAIN_MENU,
    START_MENU,
    IN_GAME,

    NUM_CONTEXTS
};

class Screen
{
public:
    Screen(Board *newBoard, Menus *newMenus);
    ~Screen();

    void ChangeContext(context newContext);
    void Draw();

    context curr_context;

private:
    Menus *menu;
    Board *board;
};

#endif /* SCREEN_HPP */
