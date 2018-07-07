#include <string>
#include <stdexcept>

using namespace std;

#include "Card.h"

/**
* Default Card Constructor.
*/
Card::Card(Rank rank, Suit suit)
{
    this->rank_enum = rank;
    this->suit_enum = suit;
}

/**
* Get the rank value of Card.
* @return the rank value of the Card as an integer.
*/
char Card::rank() const
{
    return rank_enum;
}

/**
* Get the string representation of the rank value of Card.
* @throws out_of_range thrown when an invalid rank detected.
* @return string representation of Card's rank value.
*/
const string Card::get_rank_string() const
{
    switch (rank())
    {
    case ACE:
        return "Ace";
    case KING:
        return "King";
    case QUEEN:
        return "Queen";
    case JACK:
        return "Jack";
    case CARD_10:
        return "Ten";
    case CARD_9:
        return "Nine";
    case CARD_8:
        return "Eight";
    case CARD_7:
        return "Seven";
    case CARD_6:
        return "Six";
    case CARD_5:
        return "Five";
    case CARD_4:
        return "Four";
    case CARD_3:
        return "Three";
    case CARD_2:
        return "Two";
    default:
        break;
    }

    // This should technically be impossible.
    throw out_of_range("Invalid rank value for Card.");
}

/**
* Get the suit value of Card.
* @return the suit value of the Card as an integer.
*/
int Card::suit() const
{
    return suit_enum;
}

/**
* Get the string representation of the suit value of Card.
* @throws out_of_range thrown when an invalid suit detected.
* @return string representation of Card's suit value.
*/
const string Card::get_suit_string() const
{
    switch (suit())
    {
    case SPADE:
        return "Spade";
    case HEART:
        return "Heart";
    case CLUB:
        return "Club";
    case DIAMOND:
        return "Diamond";
    default:
        break;
    }

    // This should technically be impossible.
    throw out_of_range("Invalid suit value for Card.");
}

/**
* Get the string representation of the Card object.
* @return string representation of Card object.
*/
const string Card::to_string() const
{
    return get_rank_string() + " of " + get_suit_string();
}

/**
* Boolean equality operator overloader between two Card objects.
* @param card The right side argument Card object of the comparison.
* @return true if both Card object ranks are equal and suits are equal.
*/
bool Card::operator==(const Card &card) const
{
    return (card.rank() == rank()) && (card.suit() == suit());
}