#ifndef POKERMACHINE_H
#define POKERMACHINE_H

#include <vector>

#include "BankRoll.h"
#include "Game.h"
#include "Hand.h"

/**
* @class PokerMachine
* @brief A poker machine user interface.
*/
class PokerMachine
{
public:
    PokerMachine();
    
    void add_coins(const unsigned int coins);
    
    void start_game();

    void finish_game(const std::vector<int> &replace_list);
    
    void place_bet(const unsigned int bet);

    const unsigned int get_balance() const;
    
    const Hand& get_hand() const;
    
    const unsigned int get_winnings() const
    {
        return game.get_hand().get_payout() * get_bet();
    }
    
    const unsigned int get_bet() const
    {
        return bet;
    }
    
    unsigned int cash_out();

private:

    /** The current Player's bank roll in the machine. */
    BankRoll bankroll;
    
    /** Current bet on current Game. */
    unsigned int bet;
    
    /** The current Game being played. */
    Game game;
};

#endif /* POKERMACHINE_H */
