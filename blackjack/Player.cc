#include "Player.h"
#include "Hand.h"
#include "Card.h"

/**
* Default Constructor. Initializes empty Hand object.
*/
Player::Player()
{
    hand = Hand();
}

/**
* Returns a *copy* of hand object.
* @return Copy of Hand object.
*/
Hand Player::get_hand()
{
    return hand;
}

/**
* Clears out the hand's card/points.
*/
void Player::clear_points()
{
    hand.clear_points();
}

/**
* Fetches points visible to the Player.
* @return Visible points as integer.
*/
int Player::visible_points()
{
    return hand.visible_points();
}

/**
* Add a player visible (or face up) card to the hand.
*
* @param card Visible card to add to hand.
*/
void Player::add_visible(Card card)
{
    hand.add_faceup(card);
}

/**
* Add a non player visible (or face down) card to the hand.
* Note: This is useful when the Dealer is a Player.
*
* @param card Non-visible card to add to hand.
*/
void Player::add_hidden(Card card)
{
    hand.add_facedown(card);
}

/**
* Add money to wallet.
* @param money Amount of money to add.
*/
void Player::add_money(unsigned int money)
{
    // Note: Risk of overrun here.
    wallet += money;
}

/**
* Remove money to wallet.
* @param money Amount of money to remove.
*/
void Player::sub_money(unsigned int money)
{
    // Protect from (unlikely) underrun
    if (wallet - money > wallet)
    {
        wallet = 0;
        return;
    }
    wallet -= money;
}

/**
* Get money in wallet.
* @return Returns money in wallet.
*/
unsigned int Player::get_wallet() const
{
    return wallet;
}