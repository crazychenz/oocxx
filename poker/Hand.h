#ifndef HAND_H
#define HAND_H

#include <vector>

#include "Card.h"

/**
* @class Hand
* @brief Class that represents and calculates the value of the players cards.
*/
class Hand
{
public:

    ///The types of hands recognized and their payouts.
    enum HandType : int
    {
        ROYAL_FLUSH = 250, ///< Royal Flush pays 250:1
        STRAIGHT_FLUSH= 50, ///< Straight Flush pays 50:1
        FOUR_OFA_KIND = 25, ///< Four Of A Kind 25:1
        FULL_HOUSE = 9, ///< Full House 9:1
        FLUSH = 6, ///< Flush pays 6:1
        STRAIGHT = 4, ///< Straight pays 4:1
        THREE_OFA_KIND = 3, ///< Three Of A Kind pays 3:1
        TWO_PAIR = 2, ///< Two Pair pays 2:1
        JACKS_OR_BETTER = 1, ///< Jacks Or Better gets your bet back 1:1
        NOTHING = 0, ///< Hand has no value, lose your bet.
    };


    Hand();

    void add_card(Card card);

    const std::vector<Card>& get_cards() const;

    void redeal(int idx, Card new_card);

    //void dump_hand();

    const HandType get_hand_type() const;

    const unsigned int get_payout() const;

    const std::string type_as_string() const;

    // TODO: Make class function
    //void test_hands();

    // TODO: Make this private?
    void rank_sort();

private:



    // TODO: Make class function
    //void test(std::string name, Card *cards);

    bool is_flush() const;

    bool is_straight() const;

    bool is_straight_flush() const;

    bool is_royal_flush() const;

    bool is_four_ofa_kind() const;

    // Assumed not four of a kind.
    bool is_full_house() const;

    // Assumed not four of a kind OR full house
    bool has_three_ofa_kind() const;

    // Assumed not three ofa kind, not four ofa kind, AND not full house
    bool has_two_pair() const;

    bool has_royal_pair() const;

    /** Rank order vector of cards in hand. */
    std::vector<Card> rank_vec;
};

#endif