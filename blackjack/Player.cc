#include "Player.h"
#include "Hand.h"
#include "Card.h"

/**
* Default Constructor.
* [docexport] Player::Player initializes hand
*/
Player::Player()
{
    hand = Hand();
}

/**
* [docexport] Player::get_hand returns a copy of hand object.
*/
Hand Player::get_hand()
{
    return hand;
}

/**
* [docexport] Player::visible_points returns points visible to the player.
*/
int Player::visible_points()
{
    return hand.visible_points();
}

/**
* [docexport] Player::add_visible adds face up cards to hand.
*
* Add a player visible (or face up) card to the hand.
*
* @param Card Visible card to add to hand.
*/
void Player::add_visible(Card card)
{
    hand.add_faceup(card);
}

/**
* [docexport] Player::add_hidden adds face down cards to hand.
*
* Add a non player visible (or face down) card to the hand.
* Note: This is useful when the Dealer is a Player.
*
* @param Card Non-visible card to add to hand.
*/
void Player::add_hidden(Card card)
{
    hand.add_facedown(card);
}