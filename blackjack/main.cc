#include <cstdlib>
#include <ctime>

#include "Player.h"
#include "Dealer.h"
#include "ConsoleUI.h"

using namespace std;

void argparser(
    ConsoleUI &ui,
    const int argc, 
    char **argv, 
    unsigned int &seed)
{
    if (argc > 1)
    {
        if (string(argv[1]) == "--help" || string(argv[1]) == "-h")
        {
            ui.out() << "Usage: " << argv[0] << " [SEED]\n" << endl <<
                "Play a game of blackjack." << endl << endl <<
                "With no SEED, current time is used." << endl << endl <<
                "  -h, --help - show this help message" << endl << endl <<
                "Examples:" << endl <<
                "  " << argv[0] << " 23443" << endl <<
                "  " << argv[0] << endl << endl;
            exit(0);
        }

        try
        {
            ui.parse_numeric_input<unsigned int>(
                string(argv[1]),
                seed,
                numeric_limits<unsigned int>::min(),
                numeric_limits<unsigned int>::max());
        }
        catch (out_of_range &oor)
        {
            ui.err() << "Given seed value out of range. Must be between " <<
                numeric_limits<unsigned int>::min() << " and " <<
                numeric_limits<unsigned int>::max() << "." << endl;
            exit(0);
        }
        catch (invalid_argument &ia)
        {
            ui.err() << "Unrecognized argument: " << argv[1] << endl;
            exit(0);
        }
    }
}

int main(int argc, char **argv)
{
    // Initialize the user interface controller.
    ConsoleUI ui = ConsoleUI();

    // Initialize PRNG with time as default.
    unsigned int seed = static_cast<unsigned int>(time(NULL));
    
    // Parse and process any CLI arguments.
    argparser(ui, argc, argv, seed);

    cout << "Seed: " << seed << endl;

    // Setup the dealer object
    Dealer dealer = Dealer(ui, seed);

    // Start main game loop.
    string action;
    do {

        // Reset dealer cards.
        dealer.clear_points();

        // Initialize a player object.
        Player player = Player();

        // Dealer performs initial deal.
        if (dealer.initial_deal(player))
        {
            ui.out() << "Winner: Player (with 21 points on initial deal)" << endl;
        }
        // Allow the player to hit or stay.
        else if (dealer.play_player(player))
        {
            ui.out() << "Winner: House (because player went bust with " << 
                player.visible_points() << " points)" << endl;
        }
        else
        {
            // Dealer finishes up the game.
            dealer.play_dealer();

            ui.out() << "Winner: ";
            dealer.display_winner(player);
            ui.out() << endl;
        }

        // Check if player wants to continue or quit.
        do {
            (void)ui.get_single_word_input("Play again? (yes or no)", action);
        } while (action != "yes" && action != "no");

    } while (action == "yes");

	return 0;
}