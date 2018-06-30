#include "BankRoll.h"

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
    BankRoll bankroll;
};
