#include <cstdlib>
#include <vector>
#include <ctime>
#include "Dealer.h"
#include "Deck.h"
#include "Player.h"
#include "Card.h"

using namespace std;

Dealer::Dealer()
{
    restart(time(NULL));
}

Dealer::Dealer(int seed)
{
    restart(seed);
}

void Dealer::restart(int seed)
{
    deck = Deck(seed);
}

void Dealer::initial_deal(Player &player)
{
    player.add_visible(deck.get_card());
    player.add_visible(deck.get_card());

    this->add_visible(deck.get_card());
    add_hidden(deck.get_card());
}

void Dealer::deal_card(Player &player)
{
    player.add_visible(deck.get_card());
}

string Dealer::get_winner(Player &player)
{
    if (get_hand().all_points() > 21)
    {
        // House went bust.
        return "Player";
    }

    if (player.visible_points() == get_hand().all_points())
    {
        // Tie
        return "Neither";
    }

    if (player.visible_points() > get_hand().all_points())
    {
        // Player had more points
        return "Player";
    }
    else {
        // House had more points
        return "House";
    }
}