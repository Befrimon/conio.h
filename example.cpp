#include <iostream>
#include <conio.h>


int main()
{
    if (conio::console->kbhit())
        std::cout << "Key press!" << std::endl;

	conio::console->setTextColor(RED);
    std::cout << "This text is RED!" << std::endl;
	conio::console->setTextColor(BLACK);
	conio::console->setBackgroundColor(BLUE);
    std::cout << "And this BLACK text on BLUE background!" << std::endl;

    return 0;
}
