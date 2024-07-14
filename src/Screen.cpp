/* ------------------------------------------*/ 
/* Filename: maze_game/include/Screen.cpp    */
/* Date:     13.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#include "Screen.hpp"
#include "Menus.hpp"
#include "Board.hpp"

static void ClearTerminal();

Screen::Screen(Board *newBoard, Menus *newMenus)
{
    curr_context = MAIN_MENU;
    board = newBoard;
    menu = newMenus;
}

Screen::~Screen()
{
    board = nullptr;
    menu = nullptr;
}

void Screen::ChangeContext(context newContext)
{
    curr_context = newContext;
}

void Screen::Draw()
{
    if(curr_context == IN_GAME)
    {
        ClearTerminal();
        board->Draw();
    }
    else
    {
        ClearTerminal();
        menu->Draw();
    }
}

static void ClearTerminal()
{
    printf("\e[2J");
    printf("\e[0:0H");
}