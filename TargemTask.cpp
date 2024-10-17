/*************************************************************************
AlienKeeper Source File.
Copyright (C), AlienKeeper, 2024.
**************************************************************************/

#include <iostream>
#include "String.h"
#include <conio.h>

int main()
{
    std::cout << "Hello World!\n";

    String str1 = String("str1");
    String str2 = "str2";

    String str3;
    String str4=str2;
    str4 += str1;
    String str5(std::move(String("bla")));

    String str6 = "str6";
    String str7 = "str7";
    str6 = str6;
    bool equal = str6 == str6;
    String result = str1 + str2;


    //str1.length();
    str2.length();
    str3.length();
    str4.length();
    // str5.length();

    std::cout << "Press any key to exit...\n";
    while (!_kbhit());
}