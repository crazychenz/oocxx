#include <string>

// TODO: Get rid of this?
#include <iostream>

using namespace std;

#include "Card.h"

Card::Card(Rank rank, Suit suit)
{
    this->rank_enum = rank;
    this->suit_enum = suit;
}

int Card::rank() const
{
    return rank_enum;
}

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
    cout << "BAD: " << rank_enum;
    return "Unknown Rank";
}

int Card::suit() const
{
    return suit_enum;
}

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

    return "Unknown Suit";
}

string Card::to_string()
{
    return get_rank_string() + " of " + get_suit_string();
}

bool Card::operator==(const Card &card) const
{
    return (card.rank() == rank()) && (card.suit() == suit());
}