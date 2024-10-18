/*************************************************************************
AlienKeeper Source File.
Copyright (C), AlienKeeper, 2024.
**************************************************************************/

#pragma once

namespace cstrings
{
    /// @brief Возвращает длину строки c учетом нуль-терминатора
    /// @param zStr - нуль-терминированная строка
    inline int len(const char* zStr)
    {
        int len = 0;
        const char* pBegin = zStr;

        // Если нуль-терминатор в начале строки, то длина строки равна 1
        if (*pBegin == 0)
            return 1;

        for (; *pBegin != 0; pBegin++)
            len++;

        if (*pBegin == 0)
            len++;

        return len;
    }    
    
    /// @brief Делает букву строчной
    inline char lower(char ch)
    {
        // Если буква заглавная 
        if (ch >= 65 && ch <= 90)
        {
            // Меняем букву на строчную
            ch += 32;
        }

        return ch;
    }    
}