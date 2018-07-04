#include <iostream>
#include <limits>
#include <algorithm>

#include "Deck.h"
#include "Hand.h"
#include "Card.h"
#include "BankRoll.h"

#include "PokerMachine.h"

using namespace std;

/**
* Default PokerMachine Constructor
*/
PokerMachine::PokerMachine()
{
    bankroll = BankRoll();
}

const Hand& PokerMachine::get_hand() const
{
    return game.get_hand();
}

/**
* Adds coins to the bank roll for the Player.
*/
void PokerMachine::add_coins(const unsigned int coins)
{
    // TODO: Check input?
    bankroll.deposit(coins);
}

unsigned int PokerMachine::cash_out()
{
    return bankroll.cash_out();
}

/**
* Allows player to play the current hand of the (Five Card Stud) Poker Game.
* @return The payout of the final hand as an integer.
*/
void PokerMachine::start_game()
{
    game = Game();
}

void PokerMachine::finish_game(const vector<int> &replace_list)
{
    game.replace_cards(replace_list);
        
    // Payout the winnings plus the original stake
    bankroll.deposit(get_winnings() + bet);
}

/**
* Asks the Player what bet they'd like to make on the next hand.
*/
void PokerMachine::place_bet(const unsigned int bet)
{
    // TODO: Trigger Event?
    this->bet = bet;

    // TODO: Check input?
    bankroll.withdraw(bet);
}

const unsigned int PokerMachine::get_balance() const
{
    return bankroll.get_balance();
}




