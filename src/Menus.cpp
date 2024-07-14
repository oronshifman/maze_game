/* ------------------------------------------*/ 
/* Filename: maze_game/src/Menus.cpp         */
/* Date:     11.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#include <stdio.h> // printf()
#include <string> // std::string
#include <filesystem> // directory_iterator()
#include <vector>

#include "Menus.hpp"

#define NUM_MENUS 3

struct menu_t
{
    std::vector<std::string> *options;
    u64 size;
};

static void UpdateMapsList();
static void StartMenuHandleInput(Menus menus, u8 curr_option);
static b8 MainMenuHandleInput(Menus menus, u8 curr_option);

static std::vector<std::string> maps_list;

std::vector<std::string> main_menu_options
{
    "START",
    "QUIT"
};

std::vector<std::string> start_menu_options
{
    "RANDOM MAP",
    "CHOOSE MAP",
    "CREATE MAP",
    "BACK"
};

menu_t main_menu = {&main_menu_options, main_menu_choices::NUM_CHOICES};
menu_t start_menu = {&start_menu_options, start_menu_choices::NUM_CHOICES};
menu_t maps_menu = {&maps_list};

menu_t *game_menus[NUM_MENUS] =
{
    &main_menu,
    &start_menu,
    &maps_menu
};

Menus::Menus(context context)
{
    ChangeMenu(context);
}

Menus::~Menus()
{
    // NOTE(14.7.24): do nothing
}

void Menus::ChangeMenu(context context)
{
    menu_t *chosen_menu = game_menus[context];

    curr_context = context;
    curr_menu = chosen_menu->options;
    size = chosen_menu->size;
    curr_option = 0;
}

std::string Menus::GetChosenMapName()
{
    return maps_list[curr_option];
}

void Menus::Draw()
{
    for(u8 option = 0; option < size; ++option)
    {
        if(option == curr_option)
        {
            printf("\e[48;5;34m");
            printf("%s\n", curr_menu->at(option).c_str());
            printf("\e[0m");
            continue;
        }
        printf("%s\n", curr_menu->at(option).c_str());
    }
}

b8 Menus::Scroll(u8 key)
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

        case ENTER_KEY:
        {
            switch(curr_context)
            {
                case MAIN_MENU:
                {
                    return MainMenuHandleInput(*this, curr_option);
                } break;

                case START_MENU:
                {
                    StartMenuHandleInput(*this, curr_option);
                } break;

                case MAPS_MENU:
                {
                    return LOAD_MAP;
                } break;
            }
        }

        default:
        {
            // do nothing
        } break;
    }

    return 1;
}

static void StartMenuHandleInput(Menus menus, u8 curr_option)
{
    switch (curr_option)
    {
        case start_menu_choices::RANDOM_MAP:
        {
        } break;

        case start_menu_choices::CHOOSE_MAP:
        {
            UpdateMapsList();
            menus.ChangeMenu(MAPS_MENU);
        } break;

        case start_menu_choices::CREATE_MAP:
        {
        } break;

        case start_menu_choices::BACK:
        {
            menus.ChangeMenu(MAIN_MENU);
        } break;
    
        default:
        {
            // do nothing
        } break;
    }
}

static b8 MainMenuHandleInput(Menus menus, u8 curr_option)
{
    switch (curr_option)
    {
        case main_menu_choices::START:
        {
            menus.ChangeMenu(START_MENU);
        } break;

        case main_menu_choices::QUIT:
        {
            return STOP_RUNNING;
        } break;
    
        default:
        {
            // do nothing
        } break;
    }

    return KEEP_RUNNING;
}

static void UpdateMapsList()
{
    maps_list.clear();
    for(const auto &entry : std::filesystem::directory_iterator(maps_dir))
    {
        maps_list.push_back(entry.path().filename());
    }
    maps_menu.size = maps_list.size();
}
