#include "Hand.h"
#include "Card.h"

/**
* Default constructor.
*/
Hand::Hand()
{

}

void Hand::clear_points()
{
    faceup = 0;
    facedown = 0;
}

/**
* Adds a face up card value to the face up Hand value.
* @param card Card object used to get face up card value.
*/
void Hand::add_faceup(Card card)
{
    faceup += card.get_value();
}

/**
* Adds a face down card value to the face down Hand value.
* @param card Card object used to get face down card value.
*/
void Hand::add_facedown(Card card)
{
    facedown += card.get_value();
}

/**
* Returns the total points of hand visible to all players.
* @return Visible points as integer.
*/
int Hand::visible_points()
{
    return faceup;
}

/**
* Returns the total points of hand hidden from all players.
* @return Hidden points as integer.
*/
int Hand::hidden_points()
{
    return facedown;
}

/**
* Returns the total points of hand.
* @return Total points as integer.
*/
int Hand::all_points()
{
    return faceup + facedown;
}