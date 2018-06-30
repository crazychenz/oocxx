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

/**
* Cashes out the BankRoll of the machine for the player.
*/
void PokerMachine::cash_out()
{
    cout << endl << "--------------------" << endl;
    cout << " Cashed Out" << endl;
    cout << "--------------------" << endl;

    cout << "You now have " << bankroll.cash_out() << 
        " coins to spend." << endl;
}

/**
* Adds coins to the bank roll for the Player.
*/
void PokerMachine::add_coins()
{
    cout << endl << "--------------------" << endl;
    cout << " Add Coins" << endl;
    cout << "--------------------" << endl;

    unsigned int coins;
    cout << "You have " << bankroll.get_balance() << " coins." << endl;
    cout << "How many coins would you like to add? ";
    cin >> coins;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // TODO: Check input?
    bankroll.deposit(coins);
}

/**
* Allows player to play the current hand of the (Five Card Stud) Poker Game.
* @return The payout of the final hand as an integer.
*/
int PokerMachine::play_game()
{
    int cnt = 0;
    Hand hand;
    //hand.test_hands();

    Deck deck = Deck();

    // Deal initial hand
    for (int i = 0; i < 5; ++i)
    {
        hand.add_card(deck.pop_card());
    }

    cout << endl << "--------------------" << endl;
    cout << " Play Game" << endl;
    cout << "--------------------" << endl;

    vector<int> replace_list;
    int to_replace = 1;
    while (to_replace > 0 && to_replace < 6)
    {
        cnt = 0;
        cout << endl << "=== Current Hand ===" << endl;
        for (Card card : hand.get_hand())
        {
            cout << ++cnt << ". " << card.to_string() << endl;
        }
        cout << "Current Hand: " << hand.type_as_string() << endl;
        cout << "Current Payout: " << hand.get_payout() << endl;
        cout << "Press Enter When Select Complete" << endl;

        cout << "Replace List: ";
        for (int r : replace_list) {
            cout << r << " ";
        }
        cout << endl;

        cout << endl << "What card to replace or 'd' when done.? ";

        // TODO: Grab whitespace
        cin >> to_replace;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (to_replace > 0 && to_replace < 6)
        {
            if (find(replace_list.begin(), replace_list.end(), to_replace) == replace_list.end()) {
                replace_list.push_back(to_replace);
            }

            //to_replace--;
            //hand.redeal(to_replace - 1, deck.pop_card());
            //hand.rank_sort();
        }
        else
        {
            break;
        }
    }

    for (int r : replace_list) {
        hand.redeal(r - 1, deck.pop_card());
    }
    hand.rank_sort();

    cnt = 0;
    cout << endl << "=== Final Hand ===" << endl;
    for (Card card : hand.get_hand())
    {
        cout << ++cnt << ". " << card.to_string() << endl;
    }
    cout << "Final Hand: " << hand.type_as_string() << endl;
    cout << "Final Payout: " << hand.get_payout() << endl;

    return hand.get_payout();
}

/**
* Asks the Player what bet they'd like to make on the next hand.
*/
void PokerMachine::place_bet()
{
    cout << endl << "--------------------" << endl;
    cout << " Place Bet" << endl;
    cout << "--------------------" << endl;

    unsigned int bet;
    unsigned int balance = bankroll.get_balance();
    cout << "You have " << balance << " coins." << endl;

    if (balance == 0)
    {
        cout << "You have no money to bet with." << endl;
        cout << "Come back when you have a bank roll!" << endl;
        cout << "(Press Enter to return to Main Menu)";
        getchar();
        return;
    }

    bet = 0;
    while (!(bet > 0 && bet < 6))
    {
        int max = bankroll.get_balance() < 5 ? bankroll.get_balance() : 5;
        cout << "How many coins will you bet (1 - " << max << " coins)? ";
        cin >> bet;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // TODO: Check input?
    bankroll.withdraw(bet);

    unsigned int payout = play_game();

    if (payout > 0)
    {
        // Payout the winnings plus the original stake
        unsigned int winnings = (payout * bet);

        bankroll.deposit(winnings + bet);

        cout << endl << "You won " << winnings << " coins! ";
        cout << "(Press Enter to return to Main Menu)";
        getchar();
    }
    else
    {
        cout << endl << "You lost " << bet << " coins. ";
        cout << "(Press Enter to return to Main Menu)";
        getchar();
    }
}

/**
* Main Menu for player action selection.
*/
void PokerMachine::main_menu()
{
    int choice = 0;

    while (choice != 3)
    {
        choice = 0;
        cout << endl << "--------------------" << endl;
        cout << " Main Menu" << endl;
        cout << "--------------------" << endl;
        cout << "1. Add Coins" << endl;
        cout << "2. Play Game" << endl;
        cout << "3. Cash Out & Quit (Current Balance: " << bankroll.get_balance() << ")" << endl;

        cout << endl << "What is your choice? ";
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            add_coins();
            break;
        case 2:
            place_bet();
            break;
        case 3:
            cash_out();
            return;
            break;
        default:
            cout << "ERROR: Invalid selection." << endl;
            break;
        }
    }
}


