#include <iostream>

#include "Player.h"
#include "Dealer.h"

using namespace std;

int main()
{
	int seed;

	cout << "Seed? ";
	cin >> seed;

	Dealer dealer = Dealer(seed);
	Player player = Player();

	dealer.initial_deal(player);

	if (player.visible_points() == 21)
	{
		cout << "Player wins." << endl;
		return 0;
	}

	// player.play()
	string action;
	cout << "Dealer points: " << dealer.visible_points() << endl;
	do {
		cout << "Your points: " << player.visible_points() << endl;
		cout << "hit or stay? ";
		cin >> action;
		if (action == "hit") {
			dealer.deal_card(player);
		}
	} while (player.visible_points() <= 21 && action != "stay");

	if (player.visible_points() > 21)
	{
		cout << "House wins." << endl;
		return 0;
	}
	
	//dealer.play();
	while (dealer.get_hand().all_points() < 17) {
		dealer.deal_card(dealer);
	}

	cout << "Dealer points: " << dealer.get_hand().all_points() << endl;

	cout << "Winner: " << dealer.get_winner(player) << endl;

	return 0;
}