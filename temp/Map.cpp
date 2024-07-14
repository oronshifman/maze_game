/* ------------------------------------------*/ 
/* Filename: maze_game/code/Map.cpp          */
/* Date:     11.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#include <stdio.h>
#include <string>
#include <fstream> // ifstream

#include "Map.hpp"
#include "Buffer.hpp"
#include "my_int.h"

std::string mapsDir = "/home/oron/git/maze_game/maps";

Map::Map(std::string fileName)
{
    std::string mapPath = mapsDir + '/' + fileName;
    std::ifstream loadedMap;
    loadedMap.open(mapPath);

    if(loadedMap.good())
    {
        if(!LoadNewMap(loadedMap))
        {
            fprintf(stderr, "Map file is corrupted");
        }
    }
    else
    {
        fprintf(stderr, "Can't load %s\n", mapPath.c_str());
        perror("Map ctor: ");
    }
}

Map::~Map()
{
    delete buf;
}

 b8 Map::LoadNewMap()
{
    b8 status = 1;

    ReadWidthAndHeight(loadedMap);

    // seeks to lines to the beginning of the map
    loadedMap.ignore(256, '\n');
    loadedMap.ignore(256, '\n');

    if(map)
    {
        char *mapPos;

        for(u8 row = 0; row < buf.height; ++row)
        {
            for(u8 col = 0; col < buf.width; ++col)
            {
                mapPos = buf.indexBuffer(row, col);
                *mapPos = loadedMap.get();

                if(*mapPos == 'P')
                {
                    playerPosition[X] = col;
                    playerPosition[Y] = row;
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


b8 Map::DrawMap()
{
    b8 status = 1;
    
    system("clear");
    
    for(u8 row = 0; row < buf.height; ++row)
    {
        for(u8 col = 0; col < buf.width; ++col)
        {
            printf("%c", *buf.indexBuffer(row, col));
        }
    }
    return status;
}

b8 Map::ReadWidthAndHeight(std::ifstream &loadedMap)
{
    s32 tmpWidth, tmpHeight;
    loadedMap >> tmpWidth;
    loadedMap >> tmpHeight;

    if(tmpWidth < 256 && tmpHeight < 256)
    {
        buf.width = tmpWidth;
        buf.height = tmpHeight;
    }
    else
    {
        return 0;
    }

    return 1;
}