//
// Created by jetts on 4/22/2024.
//

#ifndef CHECKERSWITHOOP_TEXTCOLOR_H
#define CHECKERSWITHOOP_TEXTCOLOR_H

// Macros to change the color of the console text
//Allows other OS to be used other than windows

#ifdef _WIN32
#include <windows.h>
#define RED SetConsoleTextAttribute(hConsole, 4)
#define BLACK SetConsoleTextAttribute(hConsole, 8)
#define GOLD SetConsoleTextAttribute(hConsole, 14)
#define GREEN SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN)
#define HIGHLIGHT SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE)
#define NO_COLOR SetConsoleTextAttribute(hConsole, 7)
#endif

#ifdef __linux__
#define RED cout << "\033[1;31m"
#define BLACK cout << "\033[1;90m"
#define GOLD cout << "\033[1;93m"
#define HIGHLIGHT cout << "\033[1;36"
#define NO_COLOR cout << "\033[1m"
#endif

#endif //CHECKERSWITHOOP_TEXTCOLOR_H
