#include <iostream>
#include <limits>
#include <algorithm>

#include "Deck.h"
#include "Hand.h"
#include "Card.h"
#include "BankRoll.h"
#include "FiveCardStudGame.h"
#include "PokerMachine.h"
#include "ArgParser.h"

using namespace std;

/**
* Default PokerMachine Constructor
* @param args The ArgParser object for fetching exec arguments.
*/
PokerMachine::PokerMachine(
    ArgParser &args) : bankroll(), args(args)
{
    if (args.has_key("seed"))
    {
        game = FiveCardStudGame(static_cast<unsigned int>(args.get_int("seed")));
    }
    else
    {
        game = FiveCardStudGame();
    }
}

/**
* Fetch the seed used to shuffle the deck.
* @return unsigned int of PRNG seed.
*/
unsigned int
PokerMachine::get_seed() const
{
    return game.get_seed();
}

/**
 * Fetch the Hand in the current Game.
 * @return reference to Hand object.
 */
const Hand&
PokerMachine::get_hand() const
{
    return game.get_hand();
}

/**
* Adds coins to the bank roll for the Player.
* @param coins Number of coins to add to bankroll.
*/
void
PokerMachine::add_coins(const unsigned int coins)
{
    // TODO: Check input?
    bankroll.deposit(coins);
}

/**
* Withdraw all coins from the bankroll.
* @return Returns the amount withdrawn.
*/
unsigned int
PokerMachine::cash_out()
{
    return bankroll.cash_out();
}

/**
* Initializes a new Five Card Stud poker game.
*/
void
PokerMachine::start_game()
{
    game.redeal_cards();
}

/**
* Replaces the requested cards and deposits the winnings into bankroll.
* @param replace_list Reference to vector<int> indicies for replacing cards.
*/
void
PokerMachine::finish_game(
    const vector<int> &replace_list)
{
    game.replace_cards(replace_list);

    if (get_payout() > 0)
    {
        // Payout the winnings plus the original stake
        bankroll.deposit(get_winnings() + bet);
    }
}

/**
* Move the player's bet from bankroll.
* @param bet Number of coins being bet.
*/
void
PokerMachine::place_bet(
    const unsigned int bet)
{
    // TODO: Trigger Event?
    this->bet = bet;

    // TODO: Check input?
    bankroll.withdraw(bet);
}

/**
* Get the bankroll balance.
* @return The balance of the bankroll.
*/
const unsigned int
PokerMachine::get_balance() const
{
    return bankroll.get_balance();
}

/**
* Get the payout for the current Hand.
* @return current calculated HandType as a integer representation of payout.
*/
const unsigned int
PokerMachine::get_payout() const
{
    return game.get_hand().get_hand_type();
}

/**
* Get the current bet value made by the player.
* @return The bet value.
*/
const unsigned int
PokerMachine::get_bet() const
{
    return bet;
}

/**
* Calculate the player winnings.
* @return The player winnings based on current Game hand.
*/
const unsigned int
PokerMachine::get_winnings() const
{
    return get_payout() * get_bet();
}



