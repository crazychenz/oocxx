#include "ConsoleUI.h"

int main()
{
    ConsoleUI ui = ConsoleUI();

    unsigned int seed = 0;
    
    (void)ui.get_numeric_input<unsigned int>("Seed", seed);

	return 0;
}