#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Card.h"

class Player
{
public:
	Player()
	{
		hand = Hand();
	}

	Hand get_hand()
	{
		return hand;
	}

	int visible_points()
	{
		return hand.visible_points();
	}

	void add_visible(Card card)
	{
		hand.add_faceup(card);
	}

	void add_hidden(Card card)
	{
		hand.add_facedown(card);
	}

private:

	Hand hand;
};

#endif