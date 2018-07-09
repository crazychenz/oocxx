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
    PokerUI(PokerMachine &machine, ArgParser &args);

    void main_menu();

protected:

    void display_current_hand(const Hand &hand) const;

private:

    void display_current_hand_text(const Hand &hand) const;
    
    void display_current_hand_ascii(const Hand &hand) const;

    void add_coins();

    unsigned int place_bet();

    std::vector<int> player_selections();

    void show_results();

    void cash_out();

    /** The PokerMachine PokerUI is communicating with. */
    PokerMachine &machine;

    ArgParser &args;

};

#endif /* POKERUI_H */