#include <cstdlib>
#include <vector>
#include <ctime>
#include "Dealer.h"
#include "Deck.h"
#include "Player.h"
#include "Card.h"

using namespace std;

/**
* Default constructor.
* Initializes PRNG with current system time.
*/
Dealer::Dealer()
{
    restart(time(NULL));
}

/**
* Explicit constructor.
* Initializes PRNG with provided seed value.
* @param seed The seed to initialize PRNG with.
*/
Dealer::Dealer(int seed)
{
    restart(seed);
}

/**
* Re-initialize the Deck member object.
* @param seed The seed to initialize PRNG with.
*/
void Dealer::restart(int seed)
{
    deck = Deck(seed);
}

/**
* Perform the initial deal of the cards.
* @param player Reference to the other player in the game.
*/
void Dealer::initial_deal(Player &player)
{
    player.add_visible(deck.get_card());
    player.add_visible(deck.get_card());

    this->add_visible(deck.get_card());
    add_hidden(deck.get_card());
}

/**
* Deal a card to the given Player ref.
* @param player Reference of Player to deal card to.
*/
void Dealer::deal_card(Player &player)
{
    player.add_visible(deck.get_card());
}

/**
* Compares this Dealer object score to given Player to determine winner.
* @param player Reference of other Player to compare this->Player too.
* @return Returns the winner as a string.
*/
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