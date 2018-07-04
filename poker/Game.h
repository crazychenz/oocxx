#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Hand.h"
#include "Deck.h"

class Game
{
public:
    Game() : deck(), hand() 
    {
        for (int i = 0; i < 5; ++i)
        {
            hand.add_card(deck.pop_card());
        }
    }
    
    const Hand& get_hand() const
    {
        return hand;
    }
    
    unsigned int replace_cards(const std::vector<int> &replace_list)
    {
        for (int r : replace_list) {
            hand.redeal(r - 1, deck.pop_card());
        }
        hand.rank_sort();

        return hand.get_payout();
    }
private:
    Deck deck;
    Hand hand;
    
};

#endif /* GAME_H */