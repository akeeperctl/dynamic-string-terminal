/*************************************************************************
AlienKeeper Source File.
Copyright (C), AlienKeeper, 2024.
**************************************************************************/

#include <conio.h>
#include <utility>
#include <vector>
#include "String.h"

static void print(const char* zStr)
{
    for (const char* pBegin = zStr; *pBegin != 0; pBegin++)
    {
        _putch(*pBegin);
    }
}

int main()
{
    std::vector<String> names;

    

    while (!_kbhit());
}