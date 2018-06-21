#ifndef DEALER_H
#define DEALER_H

#include <string>

#include "Deck.h"
#include "Player.h"

/**
* @class Dealer
* @brief The Dealer object that plays and handles the dealing of cards.
*/
class Dealer : public Player
{
public:
    Dealer();

    Dealer(int seed);

    void restart(int seed);

    void initial_deal(Player &player);

    void deal_card(Player &player);

    std::string get_winner(Player &player);

private:

    /** The card deck for all players. */
	Deck deck;
};

#endif