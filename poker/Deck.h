#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

/**
* @class Deck
* @brief A finite deck of Card objects that may be dealt.
* Note: The user of this class is responsible for seeding the PRNG.
*/
class Deck
{
public:
    Deck();

    void shuffle();

    bool has_card() const;

    Card pop_card();

private:

    /** Vector that holds all remaining Card objects in the Deck. */
    std::vector<Card> deck;

};

#endif