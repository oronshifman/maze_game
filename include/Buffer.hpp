/* ------------------------------------------*/ 
/* Filename: maze_game/include/Buffer.hpp    */
/* Date:     13.07.2024                      */
/* Author:   Oron                            */ 
/* ------------------------------------------*/

#ifndef __BUFFER_HPP__
#define __BUFFER_HPP__

#include "my_int.h"

class Buffer
{
public:
    Buffer();
    Buffer(const Buffer &src);
    Buffer &operator=(const Buffer &src);
    ~Buffer();

    void InitBuffer(u16 width, u16 height, u16 xPos, u16 yPos);
    char *indexBuffer(u16 row, u16 col);

    u16 width;
    u16 height;

    u16 xPos;
    u16 yPos;

    char *mem;
};

#endif /* BUFFER_HPP */
