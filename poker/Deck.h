#ifndef DECK_H
#define DECK_H

#include <vector>
#include <list>
#include <cstdlib>

#include "Card.h"

using namespace std;

class Deck
{
public:
    Deck()
    {
        shuffle(1);
    }

    Deck(int seed)
    {
        shuffle(seed);
    }

    void shuffle(int seed)
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

        srand(seed);
        while (baseline.size() > 0) {
            int idx = rand() % baseline.size();
            std::list<Card>::iterator it = baseline.begin();
            std::advance(it, idx);
            baseline.erase(it);
            deck.push_back(*it);
        }
    }

    bool has_card()
    {
        return deck.size() > 0;
    }

    Card pop_card()
    {
        vector<Card>::iterator end = deck.end() - 1;
        deck.pop_back();
        return *end;
    }

private:

    vector<Card> deck;

};

#endif