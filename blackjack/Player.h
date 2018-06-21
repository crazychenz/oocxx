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
    /** [docimport] Player::Player */
    Player();

    /** [docimport] Player::get_hand */
    Hand get_hand();

    /** [docimport] Player::visible_points */
    int visible_points();

    /** [docimport] Player::add_visible */
    void add_visible(Card card);

    /** [docimport] Player::add_hidden */
    void add_hidden(Card card);

private:

	Hand hand;
};

#endif