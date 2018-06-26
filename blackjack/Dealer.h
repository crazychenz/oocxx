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

    Card deal_card(Player &player);

    bool initial_deal(Player &player);

    bool play_player(Player &player);

    void play_dealer();

    void add_money(unsigned int money);

    void sub_money(unsigned int money);

    void handle_winnings(Player &player, const unsigned int bet);

private:
    /** The card deck for all players. */
	Deck deck;

    /** User interface controller. */
    ConsoleUI ui;
};

#endif