#include <iostream>
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <sstream>

#include "PokerUI.h"
#include "PokerMachine.h"
#include "Hand.h"
#include "Card.h"
#include "ArgParser.h"
#include "StreamHelper.h"

using namespace std;

/**
* Primary Constructor
* @param machine The machine this PokerUI interacts with.
* @param args Parsed execution environment arguments.
*/
PokerUI::PokerUI(PokerMachine &machine, ArgParser &args) :
    machine(machine), args(args)
{
    if (args.get_bool("verbose"))
    {
        cout << "Seed: " << machine.get_seed() << endl;
    }
}

/**
* Requests from user the number of coins they have and sets amount in machine.
*/
void PokerUI::add_coins()
{
    // Give the user some context.
    cout << endl;
    cout << "--------------------" << endl;
    cout << " Add Coins" << endl;
    cout << "--------------------" << endl;
    cout << "You have " << machine.get_balance() << " coins." << endl; 
    
    // Only allow adding coins if they fit within primitive type.
    unsigned int max;
    max = numeric_limits<unsigned int>::max();
    max -= machine.get_balance();

    // Get safe user input.
    unsigned int coins;
    string prompt = "How many coins would you like to add?";
    io.get_numeric_input<unsigned int>(prompt, coins, 0, max);

    // Make it so.
    machine.add_coins(coins);
}

/**
* Asks the Player what bet they'd like to make on the next hand.
*/
unsigned int PokerUI::place_bet()
{
    unsigned int bet = 0;

    // Give the user some context.
    cout << endl;
    cout << "--------------------" << endl;
    cout << " Place Bet" << endl;
    cout << "--------------------" << endl;
    
    unsigned int balance = machine.get_balance();
    cout << "You have " << balance << " coins." << endl;

    // Only ask for bet if there is something to bet.
    if (balance == 0)
    {
        cout << "You have no money to bet with." << endl;
        cout << "Come back when you have a bank roll!" << endl;
        cout << "(Press Enter to return to Main Menu)";
        getchar();
        return bet;
    }

    // Allow a bet between 1 and 5 coins or between 1 and the BankRoll coins.
    bet = 0;
    while (!(bet > 0 && bet < 6))
    {
        int max = balance < 5 ? balance : 5;
        stringstream prompt;
        prompt << "How many coins will you bet (1 - " << max << " coins)? ";
        io.get_numeric_input<unsigned int>(prompt.str(), bet, 0, max);
    }

    // Make it so.
    machine.place_bet(bet);
    return bet;
}

/**
* Present the a Hand to the user with plain text.
* @param hand A reference to the hand to display.
*/
void PokerUI::display_current_hand_text(const Hand &hand) const
{
    int cnt = 0;
    for (Card card : hand.get_cards())
    {
        cout << ++cnt << ". " << card.to_string() << endl;
    }
}

/**
* Present the a Hand to the user with ASCII art.
* @param hand A reference to the hand to display.
*/
void PokerUI::display_current_hand_ascii(const Hand &hand) const
{
    /* Suit ascii art found at: 
       http://www.asciiartfarts.com/poker.html

         .    _ _    _    / \ 
        / \  ( V )  ( )  /   \
       (_,_)  \ /  (_x_) \   /
         I     V     Y    \ / 
    
    */

    // An easy index for remapping the sides of the cards.
    string ul = " ";
    string ur = " ";
    string hz = "-";
    string vt = "|";
    string lr = " ";
    string ll = " ";

    // Broke each suit into their lines for horizontal presentation.
    const string suit[4][4] = {
        { "  .  ",  " _ _ ", "  _  ", " / \\ "},
        { " / \\ ",  "( V )", " ( ) ", "/   \\" },
        { "(_,_)",  " \\ / ", "(_x_)", "\\   /" },
        { "  I  ",  "  V  ", "  Y  ", " \\ / " },
    };

    // First line
    for (int i = 0; i < 5; ++i)
    {
        cout << ul << hz << hz << hz << hz << hz << hz << hz << ur << " ";
    }
    cout << endl;

    // First Rank line
    for (Card card : hand.get_cards())
    {
        cout << vt << card.rank() << "      " << vt << " ";
    }
    cout << endl;

    // Draw the suits.
    for (int j = 0; j < 4; ++j)
    {
        for (Card card : hand.get_cards())
        {
            cout << vt << " " << suit[j][card.suit()] << " " << vt << " ";
        }
        cout << endl;
    }

    // Second rank line
    for (Card card : hand.get_cards())
    {
        cout << vt << "      " << card.rank() << vt << " ";
    }
    cout << endl;

    // Bottom line.
    for (int i = 0; i < 5; ++i)
    {
        cout << ll << hz << hz << hz << hz << hz << hz << hz << lr << " ";
    }
    cout << endl;

    // Selection index line.
    for (int i = 1; i < 6; ++i)
    {
        cout << "     " << i << ".   ";
    }
    cout << endl << endl;
}

/**
* Present the a Hand to the user.
* @param hand A reference to the hand to display.
*/
void PokerUI::display_current_hand(const Hand &hand) const
{
    // If --text-only was provided from CLI, do not use ascii art.
    if (args.get_bool("text-only"))
    {
        display_current_hand_text(hand);
    }
    else
    {
        display_current_hand_ascii(hand);
    }
}

/**
* Allows player to play the current hand of the (Five Card Stud) Poker Game.
* @return The payout of the final hand as an integer.
*/
vector<int> PokerUI::player_selections()
{
    // Give the user some context.
    cout << endl;
    cout << "--------------------" << endl;
    cout << " Play Game" << endl;
    cout << "--------------------" << endl;

    vector<int> replace_list;
    int to_replace = 1;
    while (to_replace >= -5 && to_replace <= 5)
    {
        // Give the user some context.
        const Hand &hand = machine.get_hand();
        cout << endl << "=== Current Hand ===" << endl;
        display_current_hand(hand);
        cout << "Current Hand: " << hand.type_as_string() << endl;
        cout << "Current Payout: " << machine.get_payout() << endl;
        cout << "Current Balance: " << machine.get_balance() << endl;
        cout << "Press Enter When Select Complete" << endl;

        // Provide the current state of requested card replacements.
        cout << "Replace List: ";
        for (int r : replace_list) {
            cout << r << " ";
        }
        cout << endl;

        // Ask the user (one card at a time) what to replace.
        stringstream prompt;
        cout << "Instructions:" << endl;
        cout << "- Choose between 1 and 5 to add card to list." << endl;
        cout << "- Choose between -1 and -5 to take card from list." << endl;
        cout << "- Choose '0' when card selection is complete." << endl;
        cout << endl;
        io.get_numeric_input<int>("What card to replace?", to_replace, -5, 5);

        if (to_replace >= 1 && to_replace <= 5)
        {
            // replace_list will only hold distinct indicies.
            if (find(replace_list.begin(), replace_list.end(), to_replace) == replace_list.end())
            {
                replace_list.push_back(to_replace);
            }
        }
        else if (to_replace <= -1 && to_replace >= -5)
        {
            vector<int>::iterator it = find(replace_list.begin(), replace_list.end(), -to_replace);
            if (it != replace_list.end())
            {
                replace_list.erase(it);
            }
        }
        else
        {
            break;
        }
    }

    // Return list of cards to replace.
    return replace_list;
}

/**
* Shows player the results of their hand after the card replacements.
*/
void PokerUI::show_results()
{
    const Hand &hand = machine.get_hand();
    unsigned int payout = machine.get_payout();

    // Give the user some context
    cout << endl;
    cout << "=== Final Hand ===" << endl;
    display_current_hand(hand);
    cout << "Final Hand: " << hand.type_as_string() << endl;
    cout << "Final Payout: " << payout << endl;

    if (payout > 1)
    {
        // TODO: If payout is 1, you win zero coins?
        cout << endl << "You won " << machine.get_winnings() << " coins! ";
        cout << "(Press Enter to return to Main Menu)";
        getchar();
    }
    // Note: You can never bet and only have the bet value returned.
    //       (Unless you play craps. ;) )
    else
    {
        cout << endl << "You lost " << machine.get_bet() << " coins. ";
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
    cout << endl;
    cout << "--------------------" << endl;
    cout << " Cashed Out" << endl;
    cout << "--------------------" << endl;

    unsigned int balance = machine.cash_out();
    cout << "You now have " << balance << " coins to spend." << endl;
    cout << "(Press Enter to Exit)";
    getchar();
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
        cout << "Current Balance: " << machine.get_balance() << endl;
        cout << "1. Add Coins" << endl;
        cout << "2. Play Game" << endl;
        cout << "3. Cash Out & Quit" << endl;

        io.get_numeric_input<int>("What is your choice?", choice, 1, 3);

        switch (choice)
        {
        case 1:
            add_coins();
            break;
        case 2:
            if (place_bet() == 0)
            {
                break;
            }
            machine.start_game();
            machine.finish_game(player_selections());
            show_results();
            break;
        case 3:
            cash_out();
            return;
            break;
        default:
            // This should never happen.
            cout << "ERROR: Invalid selection." << endl;
            break;
        }
    }
}