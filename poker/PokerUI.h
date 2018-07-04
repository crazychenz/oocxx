#ifndef POKERUI_H
#define POKERUI_H

#include <vector>

#include "BankRoll.h"
#include "PokerMachine.h"

/**
* @class PokerUI
* @brief A console user interface for interacting with PokerMachine.
*/
class PokerUI
{
public:
    PokerUI(PokerMachine *machine);

    void add_coins();

    void place_bet();

    std::vector<int> player_selections();

    void show_results();

    void cash_out();

    void main_menu();

private:
    /** The PokerMachine PokerUI is communicating with. */
    PokerMachine *machine;

};

#endif /* POKERUI_H */