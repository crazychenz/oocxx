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

    const Hand& get_hand() const;

    unsigned int replace_cards(const std::vector<int> &replace_list);

private:
    Deck deck;
    Hand hand;

};

#endif /* FIVECARDSTUDGAME_H */