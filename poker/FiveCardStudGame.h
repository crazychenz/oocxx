#ifndef FIVECARDSTUDGAME_H
#define FIVECARDSTUDGAME_H

#include <vector>

#include "Hand.h"
#include "Deck.h"

/**
 * @class FiveCardStudGame
 * @brief Management of the rules, hand, and deck of the game.
 */
class FiveCardStudGame
{
public:
    FiveCardStudGame();

    FiveCardStudGame(unsigned int seed);

    void redeal_cards();

    const Hand& get_hand() const;

    unsigned int replace_cards(const std::vector<int> &replace_list);

    unsigned int get_seed() const;

private:
    /** The deck of cards game is dealt from. */
    Deck deck;

    /** The player's hand being dealt from deck. */
    Hand hand;

    unsigned int seed;

};

#endif /* FIVECARDSTUDGAME_H */