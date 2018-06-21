#include <cstdlib>

#include "Deck.h"
#include "Card.h"

Deck::Deck()
{
}

Deck::Deck(int seed)
{
    shuffle(seed);
}

void Deck::shuffle(int seed)
{
    srand(seed);
}

Card Deck::get_card()
{
    return Card(rand() % 10 + 1);
}