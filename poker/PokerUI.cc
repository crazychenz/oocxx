#include <iostream>
#include <limits>
#include <algorithm>

#include "PokerUI.h"
#include "PokerMachine.h"
#include "Hand.h"
#include "Card.h"

using namespace std;

/**
* Primary Constructor
* @param machine The machine this PokerUI interacts with.
*/
PokerUI::PokerUI(PokerMachine *machine) {
    this->machine = machine;
}

/**
* Requests from user the number of coins they have and sets amount in machine.
*/
void PokerUI::add_coins()
{
    cout << endl << "--------------------" << endl;
    cout << " Add Coins" << endl;
    cout << "--------------------" << endl;

    unsigned int coins;
    cout << "You have " << machine->get_balance() << " coins." << endl;
    cout << "How many coins would you like to add? ";
    cin >> coins;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    machine->add_coins(coins);
}

/**
* Asks the Player what bet they'd like to make on the next hand.
*/
void PokerUI::place_bet()
{
    cout << endl << "--------------------" << endl;
    cout << " Place Bet" << endl;
    cout << "--------------------" << endl;

    unsigned int bet;
    unsigned int balance = machine->get_balance();
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
        int max = balance < 5 ? balance : 5;
        cout << "How many coins will you bet (1 - " << max << " coins)? ";
        cin >> bet;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    machine->place_bet(bet);
}

/**
* Allows player to play the current hand of the (Five Card Stud) Poker Game.
* @return The payout of the final hand as an integer.
*/
vector<int> PokerUI::player_selections()
{
    cout << endl;
    cout << "--------------------" << endl;
    cout << " Play Game" << endl;
    cout << "--------------------" << endl;

    vector<int> replace_list;
    int to_replace = 1;
    int cnt = 0;
    while (to_replace > 0 && to_replace < 6)
    {
        const Hand &hand = machine->get_hand();
        cnt = 0;
        cout << endl << "=== Current Hand ===" << endl;
        for (Card card : hand.get_cards())
        {
            cout << ++cnt << ". " << card.to_string() << endl;
        }
        cout << "Current Hand: " << hand.type_as_string() << endl;
        cout << "Current Payout: " << hand.get_payout() << endl;
        cout << "Current Balance: " << machine->get_balance() << endl;
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
            if (find(replace_list.begin(), replace_list.end(), to_replace) == replace_list.end())
            {
                replace_list.push_back(to_replace);
            }
        }
        else
        {
            break;
        }
    }

    return replace_list;
}

/**
* Shows player the results of their hand after the card replacements.
*/
void PokerUI::show_results()
{
    int cnt = 0;
    const Hand &hand = machine->get_hand();
    unsigned int payout = hand.get_payout();

    cout << endl << "=== Final Hand ===" << endl;
    for (Card card : hand.get_cards())
    {
        cout << ++cnt << ". " << card.to_string() << endl;
    }
    cout << "Final Hand: " << hand.type_as_string() << endl;
    cout << "Final Payout: " << payout << endl;

    if (payout > 0)
    {


        cout << endl << "You won " << machine->get_winnings() << " coins! ";
        cout << "(Press Enter to return to Main Menu)";
        getchar();
    }
    else
    {
        cout << endl << "You lost " << machine->get_bet() << " coins. ";
        cout << "(Press Enter to return to Main Menu)";
        getchar();
    }
}



/**
* Cashes out the BankRoll of the machine for the player.
* Presents the user with the number of coins they've cashed out.
*/
void PokerUI::cash_out()
{
    cout << endl << "--------------------" << endl;
    cout << " Cashed Out" << endl;
    cout << "--------------------" << endl;

    unsigned int balance = machine->get_balance();
    machine->cash_out();
    cout << "You now have " << balance << " coins to spend." << endl;
}



/**
* Main Menu for player action selection.
*/
void PokerUI::main_menu()
{
    int choice = 0;

    while (choice != 3)
    {
        choice = 0;
        cout << endl;
        cout << "--------------------" << endl;
        cout << " Main Menu" << endl;
        cout << "--------------------" << endl;
        cout << "Current Balance: " << machine->get_balance() << endl;
        cout << "1. Add Coins" << endl;
        cout << "2. Play Game" << endl;
        cout << "3. Cash Out & Quit" << endl;

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
            machine->start_game();
            machine->finish_game(player_selections());
            show_results();
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