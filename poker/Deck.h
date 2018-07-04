#ifndef DECK_H
#define DECK_H

#include "Card.h"

/**
* @class Deck
* @brief A finite deck of Card objects that may be dealt.
*/
class Deck
{
public:
    Deck();

    Deck(int seed);

    void shuffle(int seed);

    bool has_card() const;

    Card pop_card();

private:

    /** Vector that holds all remaining Card objects in the Deck. */
    std::vector<Card> deck;

};

#endif