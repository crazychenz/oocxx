#include <vector>
#include <algorithm>

using namespace std;

#include "Card.h"
#include "Hand.h"

/**
* Predicate to compare Card object ranks for sorting.
* @param x First card object to compare.
* @param y Second card object to compare.
* @return true if rank value of Card @p x is less than Card @p y
*/
static bool
comp_rank(Card &x, Card &y)
{
    return x.rank() < y.rank();
}

/**
* Predicate to compare Card object suits for sorting.
* @param x First card object to compare.
* @param y Second card object to compare.
* @return true if suit value of Card @p x is less than Card @p y
*/
static bool
comp_suit(Card &x, Card &y)
{
    return x.suit() < y.suit();
}

/**
* Default Hand Constructor
*/
Hand::Hand()
{
}

/**
* Add a Card object to Hand
*/
void
Hand::add_card(Card card)
{
    rank_vec.push_back(card);
    rank_sort();

    return;
}

/**
* Get a copy of the Hand object.
* @return Copy of the Hand object as vector<Card>
*/
const vector<Card>&
Hand::get_cards() const
{
    return rank_vec;
}

/**
* Replace the Card at index @p idx with Card object @p new_card.
*/
void
Hand::redeal(int idx, Card new_card)
{
    Card old_card = rank_vec.at(idx);
    replace(rank_vec.begin(), rank_vec.end(), old_card, new_card);
}

/**
* Sort the Cards objects in Hand based on their rank value.
*/
void
Hand::rank_sort()
{
    sort(rank_vec.begin(), rank_vec.end(), comp_rank);
}

/**
* Get a string representation of player's Hand.
* @return current calculated HandType as a string object.
*/
const string
Hand::type_as_string() const
{
    switch (get_hand_type())
    {
    case ROYAL_FLUSH:
        return "Royal Flush";
    case STRAIGHT_FLUSH:
        return "Straight Flush";
    case FOUR_OFA_KIND:
        return "Four Of A Kind";
    case FULL_HOUSE:
        return "Full House";
    case FLUSH:
        return "Flush";
    case STRAIGHT:
        return "Straight";
    case THREE_OFA_KIND:
        return "Three Of A Kind";
    case TWO_PAIR:
        return "Two Pair";
    case JACKS_OR_BETTER:
        return "Jacks Or Better";
    case NOTHING:
        return "Nothing";
    }

    return "Unknown Hand";
}

/**
* Get an enumeration type for player's Hand.
* @return current calculated HandType as a HandType enumeration.
*/
const Hand::HandType
Hand::get_hand_type() const
{
    if (is_royal_flush())
    {
        return ROYAL_FLUSH;
    }

    if (is_straight_flush())
    {
        return STRAIGHT_FLUSH;
    }

    if (is_four_ofa_kind())
    {
        return FOUR_OFA_KIND;
    }

    if (is_full_house())
    {
        return FULL_HOUSE;
    }

    if (is_flush())
    {
        return FLUSH;
    }

    if (is_straight())
    {
        return STRAIGHT;
    }

    if (has_three_ofa_kind())
    {
        return THREE_OFA_KIND;
    }

    if (has_two_pair())
    {
        return TWO_PAIR;
    }

    if (has_royal_pair())
    {
        return JACKS_OR_BETTER;
    }

    return NOTHING;
}

/**
* Check if hand is a flush.
* (This function is control flow dependent.)
* @return true if the hand is a flush.
*/
bool
Hand::is_flush() const
{
    vector<Card> suit_vec = rank_vec;
    sort(suit_vec.begin(), suit_vec.end(), comp_suit);
    return suit_vec.at(0).suit() == suit_vec.at(4).suit();
}

/**
* Check if the hand is a straight.
* (This function is control flow dependent.)
* @return true if the hand is a straight.
*/
bool
Hand::is_straight() const
{
    if (rank_vec.at(0).rank() == Card::CARD_2 &&
            rank_vec.at(1).rank() == Card::CARD_3 &&
            rank_vec.at(2).rank() == Card::CARD_4 &&
            rank_vec.at(3).rank() == Card::CARD_5 &&
            rank_vec.at(4).rank() == Card::ACE)
    {
        return true;
    }

    int start = rank_vec.begin()->rank();
    for (vector<Card>::const_iterator it = rank_vec.begin(); it < rank_vec.end(); ++it, ++start)
    {
        if (it->rank() != start)
        {
            return false;
        }
    }
    return true;
}

/**
* Check if the hand is a straight flush.
* (This function is control flow dependent.)
* @return true if the hand is a straight flush.
*/
bool
Hand::is_straight_flush() const
{
    return is_flush() && is_straight();
}

/**
* Check if hand is a royal flush.
* (This function is control flow dependent.)
* @return true if the hand is a royal flush.
*/
bool
Hand::is_royal_flush() const
{
    return is_straight_flush() &&
           rank_vec.at(0).rank() == Card::CARD_10 &&
           rank_vec.at(4).rank() == Card::ACE;
}

/**
* Check if hand is a four of a kind.
* (This function is control flow dependent.)
* @return true if the hand is a four of a kind.
*/
bool
Hand::is_four_ofa_kind() const
{
    if ((rank_vec.at(0).rank() == rank_vec.at(1).rank() &&
            rank_vec.at(1).rank() == rank_vec.at(2).rank() &&
            rank_vec.at(2).rank() == rank_vec.at(3).rank()) ||
            (rank_vec.at(1).rank() == rank_vec.at(2).rank() &&
             rank_vec.at(2).rank() == rank_vec.at(3).rank() &&
             rank_vec.at(3).rank() == rank_vec.at(4).rank()))
    {
        return true;
    }
    return false;
}

/**
* Check if hand is a full house.
* (This function is control flow dependent.)
* @return true if the hand is a full house.
*/
// Assumed not four of a kind.
bool
Hand::is_full_house() const
{
    if ((rank_vec.at(0).rank() == rank_vec.at(1).rank() &&
            rank_vec.at(1).rank() == rank_vec.at(2).rank() &&
            rank_vec.at(3).rank() == rank_vec.at(4).rank()) ||
            (rank_vec.at(4).rank() == rank_vec.at(3).rank() &&
             rank_vec.at(3).rank() == rank_vec.at(2).rank() &&
             rank_vec.at(1).rank() == rank_vec.at(0).rank()))
    {
        return true;
    }
    return false;
}

/**
* Check if hand is a three of a kind.
* (This function is control flow dependent.)
* @return true if the hand is a three of a kind.
*/
// Assumed not four of a kind OR full house
bool
Hand::has_three_ofa_kind() const
{
    if ((rank_vec.at(0).rank() == rank_vec.at(1).rank() &&
            rank_vec.at(1).rank() == rank_vec.at(2).rank()) ||
            (rank_vec.at(1).rank() == rank_vec.at(2).rank() &&
             rank_vec.at(2).rank() == rank_vec.at(3).rank()) ||
            (rank_vec.at(2).rank() == rank_vec.at(3).rank() &&
             rank_vec.at(3).rank() == rank_vec.at(4).rank()))
    {
        return true;
    }
    return false;
}

/**
* Check if hand has two pair.
* (This function is control flow dependent.)
* @return true if the hand is a two pair.
*/
// Assumed not three ofa kind, not four ofa kind, AND not full house
bool
Hand::has_two_pair() const
{
    int t[3][4] = {
        { 0, 1, 2, 3 },
        { 1, 2, 3, 4 },
        { 0, 1, 3, 4 },
    };

    for (int i = 0; i < 3; ++i)
    {
        if (rank_vec.at(t[i][0]).rank() == rank_vec.at(t[i][1]).rank() &&
                rank_vec.at(t[i][2]).rank() == rank_vec.at(t[i][3]).rank())
        {
            return true;
        }
    }
    return false;
}

/**
* Check if hand has a pair of jacks or better.
* (This function is control flow dependent.)
* @return true if the hand is pair of jacks or better.
*/
bool
Hand::has_royal_pair() const
{
    for (int i = 0; i < 4; ++i)
    {
        if (rank_vec.at(i).rank() == rank_vec.at(i + 1).rank() &&
                rank_vec.at(i).rank() >= Card::JACK) {
            return true;
        }
    }
    return false;
}
