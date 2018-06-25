#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Card.h"

/**
* @class Player
* @brief The Player object that holds a hand of cards.
* 
* Player class is responsible for managing the player's hand and
* any other potential Player specific tracking statistics.
*/
class Player
{
public:

    Player();

    void clear_points();

    Hand get_hand();

    int visible_points();

    void add_visible(Card card);

    void add_hidden(Card card);

private:

    /** The player's hand. */
	Hand hand;
};

#endif