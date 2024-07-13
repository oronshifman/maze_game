/* ------------------------------------------*/ 
/* Filename: maze_game/src/MazeGame.cpp      */
/* Date:     11.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#include <iostream>
#include <string>
#include <fstream> // ifstream
#include <cstdlib> // system()
#include <termios.h> // tcgetattr(), tcsetattr() and termios macros
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h> // for STDOUT_FILENO

#include "MazeGame.hpp"
#include "my_int.h"

static struct termios old, curr;

static b8 GetTerminalSize(u32 *screenHeight, u32 *screenWidth);
static void ClearTerminal();
static void DrawMainMenu(main_menu_choice chosen);

MazeGame::MazeGame()
{
    if(!InitGameScreen())
    {
        std::cout << "failed to init game" << std::endl;
    }
    ClearTerminal();
    DrawMainMenu(START);
}

MazeGame::~MazeGame()
{
    tcsetattr(0, TCSANOW, &old);
}

// TODO(13.7.24): implement loading map
// b8 MazeGame::LoadNewMap(std::ifstream &loadedMap)
// {
//     b8 status = 1;

//     ReadWidthAndHeight(loadedMap);

//     // seeks to lines to the beginning of the map
//     loadedMap.ignore(256, '\n');
//     loadedMap.ignore(256, '\n');

//     if(map)
//     {
//         char *mapPos;

//         for(u8 row = 0; row < buf.height; ++row)
//         {
//             for(u8 col = 0; col < buf.width; ++col)
//             {
//                 mapPos = buf.indexBuffer(row, col);
//                 *mapPos = loadedMap.get();

//                 if(*mapPos == 'P')
//                 {
//                     playerPosition[X] = col;
//                     playerPosition[Y] = row;
//                 }
//             }
//         }

//         *mapPos = '\n';
//     }
//     else
//     {
//         status = 0;
//     }

//     return status;
// }

b8 MazeGame::ReadWidthAndHeight(std::ifstream &loadedMap)
{
    s32 tmpWidth, tmpHeight;
    loadedMap >> tmpWidth;
    loadedMap >> tmpHeight;

    if(tmpWidth < 256 && tmpHeight < 256)
    {
        map.width = tmpWidth;
        map.height = tmpHeight;
    }
    else
    {
        return 0;
    }

    return 1;
}

void MazeGame::InGameInput(char key)
{
    u16 posableMoves[NUM_DIRECTIONS] = 
    {
        player.yPos - 1, player.yPos + 1,
        player.xPos - 2, player.xPos + 2
    };

    switch(key)
    {
        case 'q':
        {
            running = 0; // TODO: return to main menu
        } break;

        case ascii_arrows::UP:
        {
            if(posableMoves[UP] >= 0) 
            {
                player.yPos = posableMoves[UP];
            }
        } break;

        case ascii_arrows::DOWN:
        {
            if(posableMoves[DOWN] < map.height) 
            {
                player.yPos = posableMoves[DOWN];
            }
        } break;

        case ascii_arrows::LEFT:
        {
            if(posableMoves[LEFT] >= 0) 
            {
                player.xPos = posableMoves[LEFT];
            }
        } break;

        case ascii_arrows::RIGHT:
        {
            if(posableMoves[RIGHT] < map.width - 1) 
            {
                player.xPos = posableMoves[RIGHT];
            }
        } break;

        default:
        {
            // do nothing
        } break;
    }
}

void MazeGame::MainMenuInput(char key)
{
    // TODO(13.7.24): imple!!
}

b8 MazeGame::DrawBoard()
{
    u32 screenHeight = 0, screenWidth = 0;
    GetTerminalSize(&screenHeight, &screenWidth);


    return 0;
}

void MazeGame::HandleInput(context context)
{
    char c = getchar();

    switch(context)
    {
        case MAIN_MENU:
        {
            MainMenuInput(c);
        } break;

        case IN_GAME:
        {
            InGameInput(c);
        } break;

        default:
        {
            // do nothing
        } break;
    }
}



b8 MazeGame::InitGameScreen()
{
    b8 status = 1;

    // get the attribute of the terminal into old
    if(tcgetattr(0, &old) == 0)
    {
        // copys old to curr, more accurately, assigns olb to curr
        curr = old;
        
        // sets curr to non canonical mode, meaning no special processing is done, and the terminal driver returns individual characters.
        curr.c_lflag &= ~ICANON;

        // setting the terminal to NOT echo input back to stdout. "and"ing c_lflag with ~ECHO to remove the ECHO bit from c_lflag
        curr.c_lflag &= ~ECHO;

        if(tcsetattr(STDIN_FILENO, TCSANOW, &curr) != 0)
        {
            status = 0;
        }
    }
    else
    {
        status = 0;
    }

    return status;
}

static b8 GetTerminalSize(u32 *screenHeight, u32 *screenWidth)
{
    b8 status = 1;

    struct winsize size;
    if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) == 0)
    {
        *screenHeight = size.ws_row;
        *screenWidth = size.ws_col;
    }
    else
    {
        status = 0;
    }

    return status;
}

static void ClearTerminal()
{
    printf("\033[2J");
    printf("\e[0:0H");
}

static void DrawMainMenu(main_menu_choice chosen)
{
    static char *options[NUM_CHOICES] =
    {
        "START",
        "QUIT"
    };

    for(u8 option = START; option < NUM_CHOICES; ++option)
    {
        if(option == chosen)
        {
            printf("\e[48;5;34m");
            printf("%s\n", options[option]);
            printf("\e[0m");
            continue;
        }
        printf("%s\n", options[option]);
    }
}