#ifndef CARD_H
#define CARD_H

#include <string>

/**
* @class Card
* @brief Card object that holds the suit and rank of the card.
*/
class Card
{
public:

    /// Card rank enumeration.
    enum Rank: int
    {
        ACE = 14, ///< Ace Card
        KING = 13, ///< King Card
        QUEEN = 12, ///< Queen Card
        JACK = 11, ///< Jack Card
        CARD_10 = 10, ///< 10 Card
        CARD_9 = 9, ///< 9 Card
        CARD_8 = 8, ///< 8 Card
        CARD_7 = 7, ///< 7 Card
        CARD_6 = 6, ///< 6 Card
        CARD_5 = 5, ///< 5 Card
        CARD_4 = 4, ///< 4 Card
        CARD_3 = 3, ///< 3 Card
        CARD_2 = 2 ///< 2 Card
    };

    /// Card suit enumeration.
    enum Suit: int
    {
        SPADE=5, ///< Spade Card
        HEART=6, ///< Heart Card
        CLUB=7, ///< Club Card
        DIAMOND=8 ///< Diamond Card
    };

    Card(Rank rank, Suit suit);

    int rank() const;

    const std::string get_rank_string() const;

    int suit() const;

    const std::string get_suit_string() const;

    const std::string to_string() const;

    bool operator==(const Card &card) const;

private:

    /** Rank enumeration. */
    Rank rank_enum;

    /** Suit enumeration. */
    Suit suit_enum;
};

#endif