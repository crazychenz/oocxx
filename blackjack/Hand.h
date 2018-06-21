#ifndef HAND_H
#define HAND_H

#include "Card.h"

class Hand
{
public:
    Hand();

    void add_faceup(Card card);

    void add_facedown(Card card);

    int visible_points();

    int all_points();

private:

	int faceup = 0;
	int facedown = 0;
};

#endif