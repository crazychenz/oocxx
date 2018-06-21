#ifndef DEALER_H
#define DEALER_H

#include <cstdlib>
#include <vector>
#include <ctime>
#include "Deck.h"
#include "Player.h"
#include "Card.h"

using namespace std;

class Dealer : public Player
{
public:
	Dealer()
	{
		restart(time(NULL));
	}

	Dealer(int seed)
	{
		restart(seed);
	}

	void restart(int seed)
	{
		deck = Deck(seed);
	}

	void initial_deal(Player &player)
	{
		player.add_visible(deck.get_card());
		player.add_visible(deck.get_card());

		this->add_visible(deck.get_card());
		add_hidden(deck.get_card());
	}

	void deal_card(Player &player)
	{
		player.add_visible(deck.get_card());
	}

	string get_winner(Player &player)
	{
		if (get_hand().all_points() > 21)
		{
			// House went bust.
			return "Player";
		}

		if (player.visible_points() == get_hand().all_points())
		{
			// Tie
			return "Neither";
		}

		if (player.visible_points() > get_hand().all_points())
		{
			// Player had more points
			return "Player";
		}
		else {
			// House had more points
			return "House";
		}
	}

private:

	Deck deck;

};

#endif