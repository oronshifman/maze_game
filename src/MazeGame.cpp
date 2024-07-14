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
#include "Menus.hpp"
#include "Screen.hpp"
#include "my_int.h"

static struct termios old, curr;

static b8 ConfigTerminal();

static b8 DrawBoard();

static b8 GetTerminalSize(u32 *screenHeight, u32 *screenWidth);
static b8 LoadNewMap();
static b8 ReadWidthAndHeight(std::ifstream &loadedMap);
static void LoadBoard();

static void HandleInput();
static void InGameInput(u8 key);

static void Logic();

static void HideCursor();
static void ShowCursor();

Menus menus(MAIN_MENU);
Board board;

Screen screen(&board, &menus);

Buffer map;
Sprite player;
Sprite goal;

b8 running = 1;
b8 win = 0;

void StartGame()
{
    if(!ConfigTerminal())
    {
        std::cout << "failed to init game" << std::endl;
    }

    screen.Draw();

    Logic();
}

void EndGame()
{
    tcsetattr(0, TCSANOW, &old);
    ShowCursor();
}

static void Logic()
{
    while(running)
    {
        HandleInput();
        screen.Draw();
    }
}

// TODO(13.7.24): implement loading map
static b8 LoadNewMap()
{
    b8 status = 1;

    std::string mapPath = maps_dir + "/" + menus.GetChosenMapName();

    std::ifstream loadedMap;
    loadedMap.open(mapPath);

    ReadWidthAndHeight(loadedMap);

    // seeks to lines to the beginning of the map
    loadedMap.ignore(256, '\n');
    loadedMap.ignore(256, '\n');

    if(map.mem)
    {
        char *mapPos;

        for(u8 row = 0; row < map.height; ++row)
        {
            for(u8 col = 0; col < map.width; ++col)
            {
                mapPos = map.indexBuffer(row, col);
                *mapPos = loadedMap.get();

                if(*mapPos == 'P')
                {
                    player.xPos = col;
                    player.yPos = row;
                }
                else if(*mapPos == 'G')
                {
                    goal.xPos = col;
                    goal.yPos = row;
                }
            }
        }

        *mapPos = '\n';
    }
    else
    {
        status = 0;
    }

    return status;
}

static b8 ReadWidthAndHeight(std::ifstream &loadedMap)
{
    s32 tmpWidth, tmpHeight;
    loadedMap >> tmpWidth;
    loadedMap >> tmpHeight;

    if(tmpWidth < 256 && tmpHeight < 256)
    {
        map.InitBuffer(tmpWidth, tmpHeight, 0, 0);
    }
    else
    {
        return 0;
    }

    return 1;
}

static void LoadBoard()
{

}

static void InGameInput(u8 key)
{
    s32 posableMoves[NUM_DIRECTIONS] = 
    {
        player.yPos - 1, player.yPos + 1,
        player.xPos - 2, player.xPos + 2
    };

    switch(key)
    {
        case 'q':
        case ESC_KEY:
        {
            screen.ChangeContext(MAIN_MENU);
        } break;

        case UP_KEY:
        {
            if(posableMoves[MOVE_UP] >= 0) 
            {
                player.yPos = posableMoves[MOVE_UP];
            }
        } break;

        case DOWN_KEY:
        {
            if(posableMoves[MOVE_DOWN] < map.height) 
            {
                player.yPos = posableMoves[MOVE_DOWN];
            }
        } break;

        case LEFT_KEY:
        {
            if(posableMoves[MOVE_LEFT] >= 0) 
            {
                player.xPos = posableMoves[MOVE_LEFT];
            }
        } break;

        case RIGHT_KEY:
        {
            if(posableMoves[MOVE_RIGHT] < map.width - 1) 
            {
                player.xPos = posableMoves[MOVE_RIGHT];
            }
        } break;

        default:
        {
            // do nothing
        } break;
    }
}

static b8 DrawBoard()
{
    u32 screenHeight = 0, screenWidth = 0; // NOTE(14.7.24): currently not used
    GetTerminalSize(&screenHeight, &screenWidth);

    return 0;
}

static void HandleInput()
{
    u8 c = getchar();    

    switch(screen.curr_context)
    {
        case MAIN_MENU:
        case START_MENU:
        {
            switch(menus.Scroll(c))
            {
                case STOP_RUNNING:
                {
                    running = 0;
                } break;

                case KEEP_RUNNING:
                {
                    // do nothing
                } break;

                case LOAD_MAP:
                {
                    LoadNewMap();
                    LoadBoard();
                    screen.ChangeContext(IN_GAME);
                } break;

                default:
                {
                    // do nothing
                } break;
            }
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

static b8 ConfigTerminal()
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

        HideCursor();
    }
    else
    {
        status = 0;
    }

    return status;
}

static void ShowCursor()
{
    printf("\e[?25h");
}

static void HideCursor()
{
    printf("\e[?25l");
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

