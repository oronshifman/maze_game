#include <iostream>
#include <termios.h>
#include <stdio.h> // printf()
#include <cstdlib> // system()
#include <fstream> // ifstream
#include <sys/ioctl.h>

void WithOldAndCurr();
void FileIO();

int main(void)
{
    // WithOldAndCurr();
    // FileIO();
    printf("\033[2J");

    return 0;
}

void WithOldAndCurr()
{
    struct termios old, curr;

    // get the attribute of the terminal into old
    tcgetattr(0, &old);
    
    // copys old to curr, more accurately, assigns olb to curr
    curr = old;
    
    // sets curr to non canonical mode, meaning no special processing is done, and the terminal driver returns individual characters.
    curr.c_lflag &= ~ICANON;

    // setting the terminal to echo input back to stdout. "or"ing c_lflag with ECHO to add ECHO to c_lflag
    curr.c_lflag &= ~ECHO;

    tcsetattr(0, TCSANOW, &curr);

    system("clear");

    char c;
    while(c != 'q')
    {
        c = getchar();
        printf("Entered: %c\n", c);
    }

    tcsetattr(0, TCSANOW, &old);
}

void FileIO()
{
    std::ifstream map;
    map.open("maps/test_map.txt");

    char *inMemMap;

    int width;
    int height;
    if(map.good())
    {
        map >> width;
        map >> height;
        inMemMap = new char[width * height];

        map.ignore(255, '\n');
        map.ignore(255, '\n');

        for(int i = 0; i <= height; ++i)
        {
            map.getline(inMemMap + (i * width), 255);
        }
    }
    for(int i = 0; i < height; ++i)
    {
        std::cout << inMemMap + (i * width) << std::endl;
    }
    std::cout << inMemMap + (height * width);
}

void UsingAnsiEscCodes()
{

}