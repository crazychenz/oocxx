#include <string>

#include "Game.h"
#include "Player.h"
#include "Dealer.h"
#include "ConsoleUI.h"

using namespace std;

/**
* Constructor. Sets the ConsoleUI.
*/
Game::Game(ConsoleUI &ui)
{
    this->ui = ui;
}

/**
* The main game loop.
* @param player The reference to the active player object.
* @param dealer The reference to the autonomous dealer object.
*/
void Game::game_loop(Player &player, Dealer &dealer)
{
    // Start main game loop.
    string action;
    do {
        unsigned int bet = 0;

        // Reset all participant's cards.
        dealer.clear_points();
        player.clear_points();

        ui.out() << "You have $" << player.get_wallet() << " in your wallet." << endl;
        ui.get_numeric_input<unsigned int>("How much to bet", bet, 0, player.get_wallet());

        // Dealer performs initial deal.
        if (dealer.initial_deal(player))
        {
            ui.out() << "Winner: Player (with 21 points on initial deal)" << endl;
            player.add_money(bet);
        }
        // Allow the player to hit or stay.
        else if (dealer.play_player(player))
        {
            ui.out() << "Winner: House (because player went bust with " <<
                player.visible_points() << " points)" << endl;
            player.sub_money(bet);
        }
        else
        {
            // Dealer finishes up the game.
            dealer.play_dealer();

            ui.out() << "Winner: ";
            dealer.handle_winnings(player, bet);
            ui.out() << endl;
        }

        // Check if player wants to continue or quit.
        do {
            (void)ui.get_single_word_input("Play again? (yes or no)", action);
        } while (action != "yes" && action != "no");

    } while (action == "yes");
}