#ifndef CARD_H
#define CARD_H

/**
* @class Card
* @brief The card object that knows its value.
*/
class Card
{
public:
	Card(int value);

	void set_value(int value);

	int get_value();

private:
    /** The point value of this Card object. */
	int value = 0;
};

#endif