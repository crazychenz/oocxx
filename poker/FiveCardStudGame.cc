#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "FiveCardStudGame.h"
#include "Hand.h"
#include "Deck.h"

/**
 * Default Constructor.
 * Initialize a game by dealing a hand to the player.
 */
FiveCardStudGame::FiveCardStudGame() :
    deck(), hand()
{
    srand(static_cast<unsigned int>(time(NULL)));
    redeal_cards();
}

/**
 * Seeded Constructor.
 * Initialize a game by shuffling and dealing a hand to the player.
 */
FiveCardStudGame::FiveCardStudGame(unsigned int seed) :
    deck(), hand()
{
    srand(seed);
    redeal_cards();
}

/**
* Reshuffle and redeal cards for a new game.
*/
void FiveCardStudGame::redeal_cards()
{
    deck = Deck();
    hand = Hand();
    for (int i = 0; i < 5; ++i)
    {
        hand.add_card(deck.pop_card());
    }
}

/**
 * Fetch an immutable Hand object for inspection by the user interface.
 * @return Immutable Hand reference.
 */
const Hand&
FiveCardStudGame::get_hand() const
{
    return hand;
}

/**
 * Replace all the requested cards (by index) at once.
 * @param replace_list A reference to a vector of card indicies to replace.
 * @return Hand payout as an unsigned integer.
 */
unsigned int
FiveCardStudGame::replace_cards(
    const std::vector<int> &replace_list)
{
    for (int r : replace_list) {
        hand.redeal(r - 1, deck.pop_card());
    }
    hand.rank_sort();

    return hand.get_hand_type();
}