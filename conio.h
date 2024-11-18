/*

============ Source code ============
Link        : https://raw.githubusercontent.com/zoelabbb/conio.h/master/conio.h
GitHub      : https://github.com/zoelabbb/conio.h.git
=====================================

*/

/**
 * conio4linux (Conio.h for linux)
 * Copyright (C) 2013 by Alif Ryuu B R
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @author Alif Ryuu B R <zoelabbb@gmail.com>
 * @date 2023-12-21
 * @version 1.1
*/
/**
 * @editor Befrimon Reminodal <superaijen@gmail.com>
 * @date 2024-11-17
 * @version 1.1.1
 */


/*
List funtions
=============
    cprintf
    cscanf
    gotoxy
    clrscr
    textcolor
    textbackground
    wherex
    wherey
    getch
    getche
    ungetch
    kbhit
    putch
    putchar
    cputs
    clreol
*/
#pragma once

#ifndef __CONIO4LINUX_H
#define __CONIO4LINUX_H

#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define PURPLE 5
#define CYAN 6
#define WHITE 9

namespace conio
{
    class Console
    {
      private:
        int bg_color;
        int fg_color;

      public:
        Console();
        ~Console();


        void clearLine();
        void insertLine();
        void deleteLine();

        void setCursorPosition(int x, int y);
        void clearScreen();

        void setBackgroundColor(short color);
        void setTextColor(short color);

        int setEchoMode(bool enable);

        int ungetch(int ch);
        int getch();
        int getche();

        int wherexy(int &x, int &y);
        int wherex();
        int wherey();

        int kbhit();

        int putch(const char c);
        int cputs(const char* str);

        char* getpass(const char* prompt);
        int gettext(int l, int t, int r, int b, void* destination);
    };
}

#endif