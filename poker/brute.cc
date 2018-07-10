/* Utility code for locating adventageous seeds. */

#include <iostream>
#include "Hand.h"
#include "FiveCardStudGame.h"


int main(int argc, char **argv)
{
    for (unsigned int i = 1; i != 0 ; ++i)
    {
        FiveCardStudGame game = FiveCardStudGame(i);
        if (i % 10000000 == 0)
        {
            std::cout << "Update: " << i << std::endl;
        }
        if (game.get_hand().get_hand_type() == Hand::ROYAL_FLUSH)
        {
            std::cout << "Seed: " << i << " Hand: " << game.get_hand().type_as_string() << std::endl;
            std::getchar();
        }
    }
    std::getchar();

    return 0;
}

