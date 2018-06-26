#ifndef GAME_H
#define GAME_H

#include "ConsoleUI.h"
#include "Player.h"
#include "Dealer.h"

/**
* @class Game
* @brief A game object for encapsulating the main game loop.
*/
class Game
{
public:
    Game(ConsoleUI &ui);

    void game_loop(Player &player, Dealer &dealer);

    
private:
    /** User interface controller. */
    ConsoleUI ui;
};

#endif