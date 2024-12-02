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

#pragma once

#ifndef __CONIO4LINUX_H
#define __CONIO4LINUX_H

/* COLORS */
#define BLACK 	0
#define RED 	1
#define GREEN 	2
#define YELLOW 	3
#define BLUE 	4
#define PURPLE 	5
#define CYAN 	6
#define GRAY    7
#define WHITE 	9
#define RESET 	10

namespace conio
{
    class console
    {
      private:
        static int bg_color;
        static int fg_color;

      public:
        static void clearLine();
        static void insertLine();
        static void deleteLine();

        static void setCursorPosition(int x, int y);
        static void clearScreen();

        static void setBackgroundColor(short color);
        static void setTextColor(short color);

        static int setEchoMode(bool enable);

        static int ungetch(int ch);
        static int getch();
        static int getche();
		static int getarrow();

        static void wherexy(int &x, int &y);
        static int wherex();
        static int wherey();

        static int kbhit();

        static int putch(char c);
        static int cputs(const char* str);

        static char* getpass(const char* prompt);
        static int gettext(int l, int t, int r, int b, void* destination);

		static void hideCursor();
		static void enableCursor();

		static void getTerminalSize(int &x, int&y);
    };
}

#endif
