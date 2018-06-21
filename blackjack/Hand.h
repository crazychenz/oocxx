#ifndef HAND_H
#define HAND_H

#include "Card.h"

class Hand
{
public:
	Hand()
	{

	}

	void add_faceup(Card card)
	{
		faceup += card.get_value();
	}

	void add_facedown(Card card)
	{
		facedown += card.get_value();
	}

	int visible_points()
	{
		return faceup;
	}

	int all_points()
	{
		return faceup + facedown;
	}

private:

	int faceup = 0;
	int facedown = 0;
};

#endif