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

void Buffer::InitBuffer(u16 newWidth, u16 newHeight, u16 newXPos, u16 newYPos)
{
    width = newWidth;
    height = newHeight;
    xPos = newXPos;
    yPos = newYPos;

    mem = new char[width * height];
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
