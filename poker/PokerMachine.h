#include "BankRoll.h"

/**
* @class PokerMachine
* @brief A poker machine user interface.
*/
class PokerMachine
{
public:
    PokerMachine();

    void cash_out();

    void add_coins();

    int play_game();

    void place_bet();

    void main_menu();

private:

    /** The current Player's bank roll in the machine. */
    BankRoll bankroll;
};
