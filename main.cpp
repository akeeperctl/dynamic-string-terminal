/*************************************************************************
AlienKeeper Source File.
Copyright (C), AlienKeeper, 2024.
**************************************************************************/

#include <conio.h>
#include <algorithm>
#include <vector>
#include "String.h"

static void print(const char* zStr)
{
    for (const char* pBegin = zStr; *pBegin != 0; pBegin++)
    {
        _putch(*pBegin);
    }
}

static void read(char* buffer, int maxBufferSize)
{
    char* pBegin = buffer;
    for (int i = 0; i < maxBufferSize - 1; i++, pBegin++)
    {
        *pBegin = _getch();

        if (*pBegin == '\r')
            break;

        _putch(*pBegin);
    }

    *pBegin = 0;
}

int main()
{
    std::vector<String> names;  
    
    while (true)
    {
        print("Enter string to add or Q to stop: ");
        char buffer[64];
        read(buffer, sizeof(buffer) + 1);
        print("\n");

        if (buffer[0] == 'Q' || buffer[0] == 'q')
            break;

        names.push_back(buffer);
    }

    print("\nForward lexico: \n");
    auto pBegin = names.begin();
    auto pEnd = names.end();

    std::sort(pBegin, pEnd);
    for (; pBegin != pEnd; pBegin++)
    {
        print("-- " + *pBegin + "\n");
    }

    print("\nReversed lexico: \n");
    pBegin = names.begin();
    pEnd = names.end();
    std::sort(pBegin, pEnd, std::greater<String>());

    for (; pBegin != pEnd; pBegin++)
    {
        print("-- " + *pBegin + "\n");
    }

    print("\nPress any key to exit...\n");
    while (!_kbhit());
}