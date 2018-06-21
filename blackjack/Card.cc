#include "Card.h"

Card::Card(int value)
{
	this->value = value;
}

void Card::set_value(int value)
{
	this->value = value;
}

int Card::get_value()
{
	return value;
}