#ifndef DECK_H
#define DECK_H

#include <cstdlib>

#include "Card.h"

class Deck
{
public:
	Deck()
	{
	}

	Deck(int seed)
	{
		shuffle(seed);
	}

	void shuffle(int seed)
	{
		srand(seed);
	}

	Card get_card()
	{
		return Card(rand() % 10 + 1);
	}

};

#endif