#ifndef DEALER_H
#define DEALER_H

#include <string>

#include "ConsoleUI.h"
#include "Deck.h"
#include "Player.h"

/**
* @class Dealer
* @brief The Dealer object that plays and handles the dealing of cards.
*
* Note: No default constructor because Dealer must have a
* user interface controller.
*
*/
class Dealer : public Player
{
public:
    Dealer(ConsoleUI &ui);

    Dealer(ConsoleUI &ui, unsigned int seed);

    void restart(int seed);

    bool initial_deal(Player &player);

    Card deal_card(Player &player);

    bool play_player(Player &player);

    void play_dealer();

    void display_winner(Player &player);

private:

    /** The card deck for all players. */
	Deck deck;

    /** User interface controller. */
    ConsoleUI ui;
};

#endif