#ifndef CARD_H
#define CARD_H

class Card
{
public:
	Card(int value);

	void set_value(int value);

	int get_value();

private:
	int value = 0;
};

#endif