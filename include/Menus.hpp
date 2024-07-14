/* ------------------------------------------*/ 
/* Filename: maze_game/include/Menus.hpp     */
/* Date:     11.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#ifndef __MENUS_HPP__
#define __MENUS_HPP__

#include <string>

#include "MazeGame.hpp"
#include <vector> // vector
#include <string> // std::string
#include "my_int.h"

namespace main_menu_choices
{
    enum main_menu_choices
    {
        START, QUIT,

        NUM_CHOICES
    };
}

namespace start_menu_choices
{
    enum start_menu_choices
    {
        RANDOM_MAP,
        CHOOSE_MAP,
        CREATE_MAP,
        BACK,

        NUM_CHOICES
    };
}

class Menus
{
public:
    Menus(context context);
    ~Menus();

    void Draw();
    void ChangeMenu(context context);

    /**
     * if QUIT is chosen, return 0 to turn running to 0
     * else return 1
     */
    b8 Scroll(u8 key);

    context curr_context;
    u8 curr_option;
    u8 size;

private:
    std::vector<std::string> *curr_menu;
};

#endif /* MENUS_HPP */