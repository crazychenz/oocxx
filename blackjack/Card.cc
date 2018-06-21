#include "Card.h"

/**
* Explicit Constructor. Sets the point value of the card.
*/
Card::Card(int value)
{
	this->value = value;
}

/**
* Sets the point value of the card.
* @param value Point value to set Card with.
*/
void Card::set_value(int value)
{
	this->value = value;
}

/**
* Fetch the point value of the card.
* @return Point value of card as integer
*/
int Card::get_value()
{
	return value;
}