#ifndef POKERUI_H
#define POKERUI_H

#include <vector>

#include "BankRoll.h"
#include "PokerMachine.h"
#include "ArgParser.h"

/**
* @class PokerUI
* @brief A console user interface for interacting with PokerMachine.
*/
class PokerUI
{
public:
    PokerUI(PokerMachine *machine, ArgParser *args);

    void main_menu();

private:

    void add_coins();

    void place_bet();

    std::vector<int> player_selections();

    void show_results();

    void cash_out();

    void usage(const char *argv0);

    /** The PokerMachine PokerUI is communicating with. */
    PokerMachine *machine;

    ArgParser *args;

};

#endif /* POKERUI_H */