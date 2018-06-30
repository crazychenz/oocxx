#ifndef CARD_H
#define CARD_H

#include <string>

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

    Card(Rank rank, Suit suit);

    int rank() const;

    const std::string get_rank_string() const;

    int suit() const;

    const std::string get_suit_string() const;

    std::string to_string();

    bool operator==(const Card &card) const;

private:
    Rank rank_enum;
    Suit suit_enum;
};

#endif