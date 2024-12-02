#include "conio.h"

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>


int conio::console::bg_color = BLACK;
int conio::console::fg_color = WHITE;

void conio::console::clearLine()
{
    std::cout << "\033[K";
}
void conio::console::insertLine()
{
    std::cout << "\x1b[1L";
}
void conio::console::deleteLine()
{
    std::cout << "\033[1M";
}

void conio::console::setCursorPosition(int x, int y)
{
    std::cout << "\033[" << y << ";" << x << "f";
}
void conio::console::clearScreen()
{
    std::cout << "\033[0m\033[2J\033[1;1f";
}

void conio::console::setBackgroundColor(short color)
{
    if (color < 0 || color > 10) return;
	if (color == 10) bg_color = -40;
	else bg_color = color;
    std::cout << "\033[0;" << 30 + fg_color << ";" << 40 + bg_color << "m";
}

void conio::console::setTextColor(short color)
{
    if (color < 0 || color > 10) return;
	if (color == 10) fg_color = -30;
	else fg_color = color;
    std::cout << "\033[0;" << 30 + fg_color << ";" << 40 + bg_color << "m";
}

int conio::console::setEchoMode(bool enable)
{
    termios newt;
	tcgetattr(STDIN_FILENO, &newt);
    if (enable) newt.c_lflag |= (ICANON | ECHO);
    else newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    return getchar();
}

int conio::console::ungetch(int ch)
{
    return ungetc(ch, stdin);
}
int conio::console::getch()
{
    return setEchoMode(false);
}
int conio::console::getche()
{
    return setEchoMode(true);
}
int conio::console::getarrow()
{
	return getch() + getch();
}

void conio::console::wherexy(int &x, int &y)
{
    std::cout << "\033[6n";
    if (getch() != '\x1B') return;
    if (getch() != '\x5B') return;

    int in;
    int ly = 0, lx = 0;
    while ((in = getch()) != ';')
        ly = ly * 10 + in - '0';
    while ((in = getch()) != 'R')
        lx = lx * 10 + in - '0';

    x = lx; y = ly;
}
int conio::console::wherex()
{
    int x = 0, y = 0;
    wherexy(x, y);
    return x;
}
int conio::console::wherey()
{
    int x = 0, y = 0;
    wherexy(x, y);
    return y;
}

int conio::console::kbhit()
{
    struct termios oldt, newt;
    int ch, oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

int conio::console::putch(const char c)
{
    std::cout << c;
    return (int)c;
}
int conio::console::cputs(const char* str)
{
    std::cout << str;
    return 0;
}

char* conio::console::getpass(const char* prompt)
{
    // implementada en unistd.h
    return nullptr;
}
int conio::console::gettext(int l, int t, int r, int b, void* destination)
{
    // Provide a meaningful implementation or remove the parameters if not needed.
    return 0;
}

void conio::console::hideCursor()
{
	std::cout << "\e[?25l";
}
void conio::console::enableCursor()
{
	std::cout << "\e[?25h";
}

void conio::console::getTerminalSize(int& x, int& y)
{
	winsize w{};
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    x = w.ws_col;
	y = w.ws_row;
}

// conio::Console* conio::console = new conio::Console();

