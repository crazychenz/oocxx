/**
@mainpage Blackjack Assignment

 Description
=============
A simple blackjack card game consists of a player and a dealer. A player is provided with a
sum of money with which to play. A player can place a bet between $0 and the amount of
money the player has. A player is dealt cards, called a hand. Each card in the hand has a point
value. The objective of the game is to get as close to 21 points as possible without exceeding
21 points. A player that goes over is out of the game. The dealer deals cards to itself and a
player. The dealer must play by slightly different rules than a player, and the dealer does not
place bets. A game proceeds as follows: A player is dealt two cards face up. If the point total
is exactly 21 the player wins immediately. If the total is not 21, the dealer is dealt two cards,
one face up and one face down. A player then determines whether to ask the dealer for another
card (called a "hit") or to "stay" with his/her current hand. A player may ask for several "hits."
When a player decides to "stay" the dealer begins to play. If the dealer has 21 it immediately
wins the game. Otherwise, the dealer must take "hits" until the total points in its hand is 17 or
over, at which point the dealer must "stay." If the dealer goes over 21 while taking "hits" the
game is over and the player wins. If the dealer's points total exactly 21, the dealer wins
immediately. When the dealer and player have finished playing their hands, the one with the
highest point total is the winner. Play is repeated until the player decides to quit or runs out of
money to bet.

 Synopsis
==========
Once the game has been started, the dealer deals 2 cards to the player and then
two cards to themself. One of the dealt cards is hidden from the player. The Dealer
then asks the Player if they want to 'hit' or 'stay' until they 'stay' or go bust.
The Dealer then shows what they had face down to the player. If the dealer gets
21, the player instantly loses. Otherwise, the Dealer draws cards until they are
greater than or equal to 17 points.

 Blackjack Object Overview
===========================

![blackjack-class-diagram](blackjack-class-diagram.png "blackjack-class-diagram")

 Card
------
The Card object is a simple wrapper around a scalar point value. This could
have been made into a full blown class that tracked rank and suit, but the
requirements only called for a Card with a point value.

 Hand
------
The Hand object is a class that keeps a sum total of the cards that are face 
up and a sum total of the cards that are face down. Once again, we could have
tracked a vector<Card>, but since neither the dealer or the player ever lose
points and there is no GUI, there is no reason to really track all of the
cards.

 Deck
------
The Deck object is where all the Card objects should originate from. The Deck
can be shuffled by seeding a psuedo random number generator (PRNG). When a
Card is drawn from the Deck, it is generated on the spot with a random value
between 1 and 11. This was deemed close enough because there was no description
of the size of a deck and in practice, a Casino will use many decks of cards,
making a situation like 5 of a kind a real possibility.

Note: There was nothing in the description about an Ace or an Ace being capable
of representing a 1 or an 11 like in the real game of black jack.

 Player
--------
A Player object is created for each of the players with a hand of cards. This
includes the user and the autonomous Dealer.

 Dealer
--------
The Dealer object represents the Dealer of the table. Since the Dealer drives
the flow of the game, most of the control logic has been placed into the
Dealer object. The Dealer, as an entity with a hand and rules is derived 
from the class Player. 

 Game
------
The Game object simply encapsulates the main game loop.

 'Other' Code Overview
=======================

 Argument Parser
-----------------
The application starts with an argument parser. This argument parser will allow the
user to request a --help message or set an explicit seed value. The seed value allows
for repeatable card deck shuffles so that the code can be easily tested with 
deterministic results. No arguments will implicitly set the PRNG based on the result
of time(NULL).

### Example Help Output

    $ ./blackjack --help
    Usage: ./blackjack [SEED]
    
    Play a game of blackjack.
    
    With no SEED, current time is used.
    
      -h, --help - show this help message
    
    Examples:
      ./blackjack 23443
      ./blackjack

### Example Given Seed

    $ ./blackjack 5432
    Seed: 5432
    You have $100 in your wallet.
    How much to bet? 10
    Dealer points: 7
    Your points: 11
    hit or stay? hit
    Player Dealt: 7
    Your points: 18
    hit or stay? stay
    Dealer uncovers: 1
    Dealer Dealt: 10
    Dealer points: 18
    Winner: Neither (It was a tie)
    Play again? (yes or no)? no

### Example Random Seed

    $ ./blackjack
    Seed: 1529979857
    You have $100 in your wallet.
    How much to bet? 50
    Dealer points: 5
    Your points: 6
    hit or stay? hit
    Player Dealt: 5
    Your points: 11
    hit or stay? hit
    Player Dealt: 3
    Your points: 14
    hit or stay? hit
    Player Dealt: 10
    Winner: House (because player went bust with 24 points)
    Play again? (yes or no)? no

 ConsoleUI
-----------
In an effort to learn a little more about the mechanisms provided by the standard C++11
library for sanity checking user input, the ConsoleUI class came to be. This class
effectively manages input, output, and error streams. By default, these streams are set
to the standard associated streams. This accomplishes two things:

* Provides a mechanism for automation of testing and logging by controlling the
  input and output outside of the standard streams. For example, the application
  could configure the ConsoleUI to read all input from a file and produce the
  output results to another file unattended.

* Provides a mechanism for using non-console output. By implementing the input and output
  through this ConsoleUI, this application has the beginnings of an abstracted interface
  that would allow other UI classes to more simply replace the ConsoleUI.

As a input stream manager, the ConsoleUI can prompt the user for 'fat-fingered' information
and only sanity check it after a newline character has been detected. If requesting a
numerical value, ConsoleUI will check the numerical limits of the parsed value and any
given contraints. If non-numerical values or values not within constraints are found,
an exception is thrown. ConsoleUI uses template types to support any of the numerical 
primitive data types provided by the C++ language.

In addition to the numerical input, there is also a single word input that ensures there
is no white space within the given text. This prevents premature stream injection that may
not have been desired. In otherwords, it aims to improve the user experience.

*/


#include <cstdlib>
#include <ctime>

#include "Player.h"
#include "Dealer.h"
#include "Game.h"
#include "ConsoleUI.h"
#include "ArgParser.h"

int main(int argc, char **argv)
{
    // Initialize the user interface controller.
    ConsoleUI ui = ConsoleUI();
    
    // Parse and process any CLI arguments.
    ArgParser args = ArgParser(ui, argc, argv);

    unsigned int seed = args.get_seed();
    ui.out() << "Seed: " << seed << std::endl;

    // Setup the dealer object
    Dealer dealer = Dealer(ui, seed);

    // Initialize a player object.
    Player player = Player();
    player.add_money(100);

    Game(ui).game_loop(player, dealer);

	return 0;
}