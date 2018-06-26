#include <cstdlib>
#include <vector>
#include <ctime>

#include "ConsoleUI.h"
#include "Dealer.h"
#include "Deck.h"
#include "Player.h"
#include "Card.h"

/**
* Constructor.
* Initializes PRNG with current system time.
* @param ui The user interface controller reference.
*/
Dealer::Dealer(ConsoleUI &ui)
{
    this->ui = ui;
    restart(time(NULL));
}

/**
* Explicit constructor.
* Initializes PRNG with provided seed value.
* @param ui The user interface controller reference.
* @param seed The seed to initialize PRNG with.
*/
Dealer::Dealer(ConsoleUI &ui, unsigned int seed)
{
    this->ui = ui;
    restart(seed);
}

/**
* Re-initialize the Deck member object.
* @param seed The seed to initialize PRNG with.
*/
void Dealer::restart(int seed)
{
    deck = Deck(seed);
    clear_points();
}

/**
* Deal a card to the given Player ref.
* @param player Reference of Player to deal card to.
* @return Returns *copy* of card dealt.
*/
Card Dealer::deal_card(Player &player)
{
    Card card = deck.get_card();
    player.add_visible(card);
    return card;
}

/**
* Perform the initial deal of the cards.
* @param player Reference to the other player in the game.
* @return Returns true if player wins, false if winner unknown.
*/
bool Dealer::initial_deal(Player &player)
{
    player.add_visible(deck.get_card());
    player.add_visible(deck.get_card());

    this->add_visible(deck.get_card());
    add_hidden(deck.get_card());

    if (player.visible_points() == 21)
    {
        return true;
    }

    return false;
}

/**
* Loop through allowing the player to hit or stay.
* If the player goes bust, the loop ends and the player loses.
* @param player Reference to the player being dealt cards.
* @return Returns true if player lost, false is winner unknown.
*/
bool Dealer::play_player(Player &player)
{
    using namespace std;
    string action;
    ui.out() << "Dealer points: " << visible_points() << endl;
    do {
        ui.out() << "Your points: " << player.visible_points() << endl;
        (void)ui.get_single_word_input("hit or stay", action);

        if (action == "hit") {
            ui.out() << "Player Dealt: " << deal_card(player).get_value() << endl;
        }
    } while (player.visible_points() <= 21 && action != "stay");

    if (player.visible_points() > 21)
    {
        return true;
    }

    return false;
}

/**
* Uncover the hidden dealer card and deal until >= 17.
* If the dealer started with 21, they win ... but return for
* now and show dealer wins in display_winner().
*/
void Dealer::play_dealer()
{
    using namespace std;
    ui.out() << "Dealer uncovers: " << get_hand().hidden_points() << endl;

    if (get_hand().all_points() == 21)
    {
        // Dealer won, just return.
        return;
    }

    while (get_hand().all_points() < 17) {
        ui.out() << "Dealer Dealt: " << deal_card(*this).get_value() << endl;
    }

    ui.out() << "Dealer points: " << get_hand().all_points() << endl;
}

/**
* Compares this Dealer object score to given Player to determine winner.
* @param player Reference of other Player to compare this->Player too.
* @return Returns the winner as a string.
*/
void Dealer::handle_winnings(Player &player, const unsigned int bet)
{
    if (get_hand().all_points() == 21)
    {
        // House wins
        ui.out() << "House (House started with 21 points)";
        player.sub_money(bet);
        return;
    }

    if (get_hand().all_points() > 21)
    {
        // House went bust.
        ui.out() << "Player (House went bust with " <<
            get_hand().all_points() << " points)";
        player.add_money(bet);
        return;
    }

    if (player.visible_points() == get_hand().all_points())
    {
        // Tie
        ui.out() << "Neither (It was a tie)";
        return;
    }

    if (player.visible_points() > get_hand().all_points())
    {
        // Player had more points
        ui.out() << "Player (Player: " << player.visible_points() <<
            " Dealer: " << get_hand().all_points() << ")";
        player.add_money(bet);
        return;
    }
    else {
        // House had more points
        ui.out() << "House (Player: " << player.visible_points() <<
            " Dealer: " << get_hand().all_points() << ")";
        player.sub_money(bet);
        return;
    }
}

void Dealer::add_money(unsigned int money)
{
    // House has infinite money.
}

void Dealer::sub_money(unsigned int money)
{
    // House has infinite money.
}