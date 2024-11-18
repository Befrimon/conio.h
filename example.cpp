#include <iostream>
#include <conio.h>

conio::Console console = conio::Console();

int main()
{
    if (console.kbhit())
        std::cout << "Key press!" << std::endl;

    console.setTextColor(RED);
    std::cout << "This text is RED!" << std::endl;
    console.setTextColor(BLACK);
    console.setBackgroundColor(BLUE);
    std::cout << "And this BLACK text on BLUE background!" << std::endl;

    return 0;
}