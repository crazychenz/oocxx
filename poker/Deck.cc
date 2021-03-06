#include <vector>
#include <list>
#include <cstdlib>

#include "Deck.h"
#include "Card.h"

using namespace std;

/**
* Default Deck Constructor.
*/
Deck::Deck()
{
    shuffle();
}

/**
* Shuffles the Cards in the deck vector.
*/
void
Deck::shuffle()
{
    list<Card> baseline = {
        Card(Card::ACE, Card::SPADE),
        Card(Card::KING, Card::SPADE),
        Card(Card::QUEEN, Card::SPADE),
        Card(Card::JACK, Card::SPADE),
        Card(Card::CARD_10, Card::SPADE),
        Card(Card::CARD_9, Card::SPADE),
        Card(Card::CARD_8, Card::SPADE),
        Card(Card::CARD_7, Card::SPADE),
        Card(Card::CARD_6, Card::SPADE),
        Card(Card::CARD_5, Card::SPADE),
        Card(Card::CARD_4, Card::SPADE),
        Card(Card::CARD_3, Card::SPADE),
        Card(Card::CARD_2, Card::SPADE),

        Card(Card::ACE, Card::CLUB),
        Card(Card::KING, Card::CLUB),
        Card(Card::QUEEN, Card::CLUB),
        Card(Card::JACK, Card::CLUB),
        Card(Card::CARD_10, Card::CLUB),
        Card(Card::CARD_9, Card::CLUB),
        Card(Card::CARD_8, Card::CLUB),
        Card(Card::CARD_7, Card::CLUB),
        Card(Card::CARD_6, Card::CLUB),
        Card(Card::CARD_5, Card::CLUB),
        Card(Card::CARD_4, Card::CLUB),
        Card(Card::CARD_3, Card::CLUB),
        Card(Card::CARD_2, Card::CLUB),

        Card(Card::ACE, Card::HEART),
        Card(Card::KING, Card::HEART),
        Card(Card::QUEEN, Card::HEART),
        Card(Card::JACK, Card::HEART),
        Card(Card::CARD_10, Card::HEART),
        Card(Card::CARD_9, Card::HEART),
        Card(Card::CARD_8, Card::HEART),
        Card(Card::CARD_7, Card::HEART),
        Card(Card::CARD_6, Card::HEART),
        Card(Card::CARD_5, Card::HEART),
        Card(Card::CARD_4, Card::HEART),
        Card(Card::CARD_3, Card::HEART),
        Card(Card::CARD_2, Card::HEART),

        Card(Card::ACE, Card::DIAMOND),
        Card(Card::KING, Card::DIAMOND),
        Card(Card::QUEEN, Card::DIAMOND),
        Card(Card::JACK, Card::DIAMOND),
        Card(Card::CARD_10, Card::DIAMOND),
        Card(Card::CARD_9, Card::DIAMOND),
        Card(Card::CARD_8, Card::DIAMOND),
        Card(Card::CARD_7, Card::DIAMOND),
        Card(Card::CARD_6, Card::DIAMOND),
        Card(Card::CARD_5, Card::DIAMOND),
        Card(Card::CARD_4, Card::DIAMOND),
        Card(Card::CARD_3, Card::DIAMOND),
        Card(Card::CARD_2, Card::DIAMOND),

    };

    // Shuffle cards by randomly removing a card from the baseline
    // until the baseline is empty. Each card removed from the baseline
    // is appended to the Deck.
    while (baseline.size() > 0) {
        // Note: Caller responsible for seeding rand() with srand()
        int idx = rand() % baseline.size();
        std::list<Card>::iterator it = baseline.begin();
        if (it != baseline.end())
        {
            std::advance(it, idx);
            deck.push_back(*it);
            // Note: Windows actually erases iterator reference here. Booooo!
            baseline.erase(it);
        }
    }
}

/**
* Check if there are Card objects left in the deck.
* @return true if there are Card objects in the deck.
*/
bool
Deck::has_card() const
{
    return deck.size() > 0;
}

/**
* Remove and return the top card of the deck.
* @return Card object that was removed from the deck.
*/
Card
Deck::pop_card()
{
    vector<Card>::iterator end = deck.end() - 1;
    Card card((Card::Rank)(*end).rank(), (Card::Suit)(*end).suit());
    // Note: Windows blows away iterator reference here. Booooo!
    deck.pop_back();
    return card;
}

