#ifndef DEALER_H
#define DEALER_H

#include <string>

#include "Deck.h"
#include "Player.h"

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

	Deck deck;

};

#endif