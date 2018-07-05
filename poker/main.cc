/**
@mainpage Project #1: Poker Machine

 Project #1 Statement
======================
This project involves designing and implementing a video poker game using
object-oriented principles and the C++ language. The diagram below
illustrates the components of a GUI interface for such a game. For
purposes of this project a simple console-based user interface shall be
used.

![poker-gui](poker-gui.png "poker-gui")

 The Basic Game Mechanics
--------------------------

Our game will simulate a single hand of five-card stud poker. The basic
rules and mechanics of the game are as follows:

- A player deposits an arbitrary number of coins into the machine. Each
  coin has equal value. The number of coins deposited is the player’s
  bankroll.
- The player makes a bet of one to five coins (but not more than the
  bankroll).
- A hand of five cards is dealt from a deck of 52 cards. The deck is
  reshuffled before each game.
- After viewing his/her hand, the player decides which cards he/she
  would like to keep and which cards he/she would like to replace.
- New cards are dealt for those the player has discarded.
- The hand is evaluated and scored.
- If the hand is a winner, a payout amount is added to the bankroll.
  Otherwise, the bet amount is deducted from the bankroll.
- The player can quit and cash out at any time.
- The player can continue to play as long as the bankroll is not
  depleted.
- The player can add coins to the bankroll before each game.

 Scoring the Game
------------------

A deck of cards consists of 52 different cards. Each card has a rank or
value as well as a suit (hearts, diamonds, spades, clubs). The ordered
ranks are as follows:

    Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King

The winning hands, listed in highest to lowest precedence, are as follows:

- Royal Flush: 10, Jack, King, Queen, Ace, all of the same suit. Pays 250
  to 1. For example, if a player bets one coin and is dealt a royal flush,
  then the player wins 250 coints.
- Straight Flush: Five cards in rank sequence, all of the same suit, but
  not a royal flush. For example, Ace, 2, 3, 4, 5 all hearts. Pays 50 to 1.
- Four of a Kind: For cards of the same rank. For example, 3 of hearts, 3
  of diamonds, 3 of spades, and 10 of clubs. Pays 25 to 1.
- Full House: Three cards of one rank and two of another. For example, 4
  of hearts, 4 of spades, 4 of clubs, 7 of clubs, 7 of diamonds. Pays 9
  to 1.
- Flush: All five cards of the same suit, but not a straight flush. For
  example, 3 of hearts, 6 of hearts, 7 of harts, 10 of hearts, Jack of
  hearts. Pays 6 to 1.
- Straight: Five cards in rank sequence, but not a flush. For example,
  Ace of hearts, 2 of spades, 3 of hearts, 4 of clubs, 5 of diamonds.
  Pays 4 to 1.
- Three of a Kind: Three cards of the same rank and two cards of two other
  ranks that is not a full house or four of a kind. For example, 5 of
  hearts, 5 of clubs, 5 of spades, 7 of clubs, 9 of diamonds. Pays 3 to 1.
- Two Pair: Two cards of one rank, two of another, and one card of a
  third. For example, 6 of hearts, 6 of clubs, 9 of clubs, 9 of spades,
  Ace of hearts. Pays 2 to 1.
- Jacks or Better: Exactly one pair of Jacks, Queens, Kings, or Aces,
  and nothing else of interest. For example, Jack of hearts, Jack of
  clubs, 2 of spades, 3 of clubs, 3 of hearts. Pays 1 to 1.

 Project Deliverables
----------------------

- A class diagram
- All source code
- A screen capture illustrating the results of a single hand.

 Implementation Synopsis
=========================
This Poker machine implementation is broken up into the poker user
interface classes, a poker machine interface, and the five card stud game
classes.

 Poker User Interface
======================

 PokerUI
---------
The PokerUI user interface object is responsible for interacting with the
user via the console. With the required user input and user output, the
PokerUI drives the PokerMachine object on behalf of the user.

 Stream Helper
---------------
This class assists with managing input, output, and error streams. By
default, these streams are set to the standard associated streams. This
accomplishes two things:

- Provides a mechanism for automation of testing and logging by
  controlling the input and output outside of the standard streams.
  For example, the application could configure the ConsoleUI to
  read all input from a file and produce the output results to
  another file unattended.

- Provides a mechanism for using non-console output. By implementing
  the input and output through this ConsoleUI, this application has
  the beginnings of an abstracted interface that would allow other
  UI classes to more simply replace the ConsoleUI.

As a input stream manager, the StreamHelper can prompt the user for
'fat-fingered' information and only sanity check it after a newline
character has been detected. If requesting a numerical value, StreamHelper
will check the numerical limits of the parsed value and any given
contraints. If non-numerical values or values not within constraints
are found an exception is thrown. StreamHelper uses template types to
support any of the numerical primitive data types provided by the C++
language.

In addition to the numerical input, there is also a single word input
that ensures there is no white space within the given text. This prevents
premature stream injection that may not have been desired. In otherwords,
it aims to improve the user experience.

 Poker Machine Object Overview
===============================

 PokerMachine
--------------
The PokerMachine object is responsible for managing access to the bankroll,
the bet, and the current game being played through the use of a facade pattern.
The bankroll and bet are loosely coupled from the five card stud game itself
by the PokerMachine object.

 Five Card Stud Game
=====================

 FiveCardStudGame
------------------
The five card stud game is responsible for managing the player's hand, the
deck of cards being dealt, and the rules of the game.

 Card
------
The Card object is a wrapper around a 2 enumerations, a suit enum and a
rank enum.

 Hand
------
The Hand object stores a number of cards in a rank ordered vector.

 Deck
------
The Deck object starts out as a shuffled deck of 52 unique cards. As cards
are removed from the Deck, the Card object is copied for use by the user
and the instance in the deck is removed.

 Argument Parser
=================
The application starts with an argument parser. This argument parser will
allow the user to request a --help message or set an explicit seed value.
The seed value allows for repeatable card deck shuffles so that the code
can be easily tested with deterministic results. No arguments will
implicitly set the PRNG based on the result of time(NULL).

### Example Help Output

    $ ./poker --help

### Example Given Seed

    $ ./poker 5432


### Example Random Seed

    $ ./poker



*/

#include "PokerMachine.h"
#include "PokerUI.h"
int main(int argc, char **argv)
{
    ArgParser args(argc, argv);
    PokerMachine machine = PokerMachine(&args);
    PokerUI(&machine, &args).main_menu();
    return 0;
}

