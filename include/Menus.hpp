/* ------------------------------------------*/ 
/* Filename: maze_game/include/Menus.hpp     */
/* Date:     11.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#ifndef __MENUS_HPP__
#define __MENUS_HPP__

#include "MazeGame.hpp"
#include "Screen.hpp"
#include "my_int.h"

enum main_menu_choices
{
    START, QUIT,

    NUM_CHOICES
};

enum start_menu_choices
{
    RANDOM_MAP,
    CHOOSE_MAP,
    CREATE_MAP,

    NUM_CHOICES
};

class Menus
{
public:
    Menus(context context);
    ~Menus();

    void Draw();
    void ChooseMenu(context context);
    void Scroll(char key);

    context curr_menu;
    u8 curr_option;
    u8 size;

private:
    char **curr_menu;
};

#endif /* MENUS_HPP */