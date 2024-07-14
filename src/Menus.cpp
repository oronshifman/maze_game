/* ------------------------------------------*/ 
/* Filename: maze_game/src/Menus.cpp         */
/* Date:     11.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#include <stdio.h>

#include "Menus.hpp"

#define NUM_MENUS 2
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

char *main_menu_options[NUM_CHOICES] =
{
    "START",
    "QUIT"
};

char *start_menu_options[NUM_CHOICES] =
{
    "RANDOM MAP",
    "CHOOSE MAP",
    "CREATE MAP"
};

char **menus[NUM_MENUS] =
{
    main_menu_options,
    start_menu_options
};

Menus::Menus(context context)
{
    curr_menu = menus[context];
    size = ARRAY_SIZE(curr_menu);
    curr_option = 0;
}

Menus::~Menus()
{
    // NOTE(14.7.24): do nothing
}

void Menus::Draw()
{
    for(u8 option = 0; option < size; ++option)
    {
        if(option == curr_option)
        {
            printf("\e[48;5;34m");
            printf("%s\n", curr_menu[option]);
            printf("\e[0m");
            continue;
        }
        printf("%s\n", curr_menu[option]);
    }
}

void Menus::ChooseMenu(context context)
{
    curr_menu = menus[context];
    size = ARRAY_SIZE(curr_menu);
    curr_option = 0;
}

void Menus::Scroll(char key)
{
    switch(key)
    {
        case UP_KEY:
        {
            curr_option = --curr_option % size;
        } break;

        case DOWN_KEY:
        {
            curr_option = ++curr_option % size;
        } break;

        default:
        {
            // do nothing
        } break;
    }
}
