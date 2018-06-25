#include <iostream>
using namespace std;

#include <cstdlib>

#include "Deck.h"
#include "Card.h"

/** 
* Default constructor.
*/
Deck::Deck()
{
}

/**
* Explicit constructor.
* Initializes PRNG with a provided seed value.
* @param seed The seed value as integer.
*/
Deck::Deck(int seed)
{
    shuffle(seed);
}

/**
* 'Shuffle' the deck by re-initializing the PRNG.
* @param seed The seed value as integer.
*/
void Deck::shuffle(int seed)
{
    srand(seed);
}

/**
* Draw a card from the deck.
* @return Returns a randomly generated Card object.
*/
Card Deck::get_card()
{
    Card card = Card(rand() % 10 + 1);
    return card;
}