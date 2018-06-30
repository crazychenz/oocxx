#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card
{
public:
    enum Rank: int
    {
        ACE = 14,
        KING = 13,
        QUEEN = 12,
        JACK = 11,
        CARD_10 = 10,
        CARD_9 = 9,
        CARD_8 = 8,
        CARD_7 = 7,
        CARD_6 = 6,
        CARD_5 = 5,
        CARD_4 = 4,
        CARD_3 = 3,
        CARD_2 = 2
    };

    enum Suit: int
    {
        SPADE=5,
        HEART=6,
        CLUB=7,
        DIAMOND=8
    };

    Card(Rank rank, Suit suit)
    {
        this->rank = rank;
        this->suit = suit;
    }

    int get_rank_value() const
    {
        return rank;
    }

    string get_rank_string()
    {
        switch (rank)
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
        cout << "BAD: " << rank;
        return "Unknown Rank";
    }

    int get_suit_value() const
    {
        return suit;
    }

    string get_suit_string()
    {
        switch (suit)
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

    string to_string()
    {
        return get_rank_string() + " of " + get_suit_string();
    }

    bool operator==(const Card &card) const
    {
        return (card.get_rank_value() == get_rank_value()) && (card.get_suit_value() == get_suit_value());
    }

private:
    Rank rank;
    Suit suit;
};

#endif