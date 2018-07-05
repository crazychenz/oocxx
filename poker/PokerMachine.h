#ifndef POKERMACHINE_H
#define POKERMACHINE_H

#include <vector>

#include "BankRoll.h"
#include "FiveCardStudGame.h"
#include "Hand.h"
#include "ArgParser.h"

/**
* @class PokerMachine
* @brief A poker machine interface.
*/
class PokerMachine
{
public:
    PokerMachine(ArgParser *args);

    void add_coins(const unsigned int coins);

    void start_game();

    void finish_game(const std::vector<int> &replace_list);

    void place_bet(const unsigned int bet);

    const unsigned int get_balance() const;

    const Hand& get_hand() const;

    const unsigned int get_bet() const;

    const unsigned int get_winnings() const;

    unsigned int cash_out();

    const unsigned int get_payout() const;

private:

    /** The current Player's bank roll in the machine. */
    BankRoll bankroll;

    /** Current bet on current Game. */
    unsigned int bet;

    /** The current Game being played. */
    FiveCardStudGame game;

    /** Execution environment arguments. */
    ArgParser *args;
};

#endif /* POKERMACHINE_H */
