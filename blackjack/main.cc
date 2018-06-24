#include <iostream>
#include <limits>

#include "Player.h"
#include "Dealer.h"
#include "ConsoleUI.h"

using namespace std;

int main()
{
    ConsoleUI ui = ConsoleUI();

    unsigned int seed = 0;
    
    (void)ui.get_numeric_input<unsigned int>("Seed", seed);

	Dealer dealer = Dealer(seed);
	Player player = Player();

	dealer.initial_deal(player);

	if (player.visible_points() == 21)
	{
		ui.out() << "Player wins." << endl;
		return 0;
	}

	// player.play()
	string action;
    ui.out() << "Dealer points: " << dealer.visible_points() << endl;
	do {
        ui.out() << "Your points: " << player.visible_points() << endl;
        (void)ui.get_single_word_input("hit or stay", action);

		if (action == "hit") {
			dealer.deal_card(player);
		}
	} while (player.visible_points() <= 21 && action != "stay");

	if (player.visible_points() > 21)
	{
		ui.out() << "House wins." << endl;
		return 0;
	}
	
	//dealer.play();
	while (dealer.get_hand().all_points() < 17) {
		dealer.deal_card(dealer);
	}

    ui.out() << "Dealer points: " << dealer.get_hand().all_points() << endl;

    ui.out() << "Winner: " << dealer.get_winner(player) << endl;

	return 0;
}