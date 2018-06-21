#ifndef HAND_H
#define HAND_H

#include "Card.h"

/**
* @class Hand
* @brief The Hand object held by all players.
*/
class Hand
{
public:
    Hand();

    void add_faceup(Card card);

    void add_facedown(Card card);

    int visible_points();

    int all_points();

private:
    /** Sum of all cards visible to all players. */
	int faceup = 0;
    /** Sum of all cards not visible to all players. */
	int facedown = 0;
};

#endif