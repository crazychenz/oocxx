#ifndef DECK_H
#define DECK_H

#include "Card.h"

/**
* @class Deck
* @brief The Deck that the Dealer draws cards from.
*/
class Deck
{
public:
    Deck();

    Deck(int seed);

    void shuffle(int seed);

    Card get_card();

};

#endif