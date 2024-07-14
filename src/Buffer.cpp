/* ------------------------------------------*/ 
/* Filename: maze_game/src/Buffer.cpp        */
/* Date:     13.07.2024                      */
/* Author:   Oron                            */
/* ------------------------------------------*/

#include <cassert> // assert()

#include "Buffer.hpp"

Buffer::Buffer()
{
    width = 0;
    height = 0;
    xPos = 0;
    yPos = 0;

    mem = nullptr;
}

Buffer::Buffer(u16 width, u16 height, u16 xPos, u16 yPos)
{
    // TODO(13.7.24): imple
}

Buffer::Buffer(const Buffer &src)
{
    // TODO(13.7.24): imple
}

Buffer &Buffer::operator=(const Buffer &src)
{
    // TODO(13.7.24): insert return statement here
    return *this;
}

Buffer::~Buffer()
{
    // TODO(13.7.24): imple
}

char *Buffer::indexBuffer(u16 row, u16 col)
{
    assert(row < height);
    assert(col < width);

    return mem + (row * width) + col;
}
