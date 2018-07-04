#include <vector>
#include <algorithm>

// TODO: Get rid of this?
//#include <iostream>

using namespace std;

#include "Card.h"
#include "Hand.h"

/**
* Predicate to compare Card object ranks for sorting.
* @param x First card object to compare.
* @param y Second card object to compare.
* @return true if rank value of Card @p x is less than Card @p y
*/
static bool comp_rank(Card &x, Card &y)
{
    return x.rank() < y.rank();
}

/**
* Predicate to compare Card object suits for sorting.
* @param x First card object to compare.
* @param y Second card object to compare.
* @return true if suit value of Card @p x is less than Card @p y
*/
static bool comp_suit(Card &x, Card &y)
{
    return x.suit() < y.suit();
}

/**
* Default Hand Constructor
* @public
*/
Hand::Hand()
{
    //rank_vec = std::vector<Card &>();
    //suit_vec = std::vector<Card &>();
}

/**
* Add a Card object to Hand
* @public
*/
void Hand::add_card(Card card)
{
    rank_vec.push_back(card);
    rank_sort();

    return;
}

/**
* Get a copy of the Hand object.
* @public
* @return Copy of the Hand object as vector<Card>
*/
const vector<Card>& Hand::get_cards() const
{
    return rank_vec;
}

/*bool is_locked(int idx) const
{
	Card card = locked.at(idx);
	if (find(locked.begin(), locked.end(), card) != locked.end())
	{
		return true;
	}
	return false;
}*/

/**
* Replace the Card at index @p idx with Card object @p new_card.
* @public
*/
void Hand::redeal(int idx, Card new_card)
{
    Card old_card = rank_vec.at(idx);
    replace(rank_vec.begin(), rank_vec.end(), old_card, new_card);
    //locked.push_back(new_card);
}

/**
* Sort the Cards objects in Hand based on their rank value.
*/
void Hand::rank_sort()
{
    sort(rank_vec.begin(), rank_vec.end(), comp_rank);
}

#if 0
/**
* Dump the state of Hand object to console.
* @public
*/
void Hand::dump_hand(ostream &out)
{
    /* Dump attributes. */
    out << "payout: " << get_payout() << endl;
    out << "royal flush: " << is_royal_flush() << endl;
    out << "is flush: " << is_flush() << endl;
    out << "is straight: " << is_straight() << endl;
    out << "is straight flush: " << is_straight_flush() << endl;
    out << "is four ofa kind: " << is_four_ofa_kind() << endl;
    out << "is full house: " << is_full_house() << endl;
    out << "has three ofa kind: " << has_three_ofa_kind() << endl;
    out << "has two pair: " << has_two_pair() << endl;
    out << "has_pair: " << has_royal_pair() << endl;

    /* Dump rank sorted. */
    out << "--- Rank sorted: ---" << endl;
    for (vector<Card>::iterator it = rank_vec.begin(); it < rank_vec.end(); it++)
    {
        out << it->to_string() << endl;
    }
    out << endl;
}

/**
* Unit test various Hand states.
* @public
*/
// TODO: Make class function
void Hand::test_hands()
{
    Card royal_flush[5] = {
        Card(Card::ACE, Card::SPADE),
        Card(Card::QUEEN, Card::SPADE),
        Card(Card::CARD_10, Card::SPADE),
        Card(Card::KING, Card::SPADE),
        Card(Card::JACK, Card::SPADE),
    };

    Card royal_straight[5] = {
        Card(Card::ACE, Card::SPADE),
        Card(Card::QUEEN, Card::CLUB),
        Card(Card::CARD_10, Card::SPADE),
        Card(Card::KING, Card::CLUB),
        Card(Card::JACK, Card::SPADE),
    };

    Card low_straight[5] = {
        Card(Card::ACE, Card::SPADE),
        Card(Card::CARD_2, Card::CLUB),
        Card(Card::CARD_3, Card::SPADE),
        Card(Card::CARD_4, Card::CLUB),
        Card(Card::CARD_5, Card::SPADE),
    };

    Card not_straight[5] = {
        Card(Card::ACE, Card::SPADE),
        Card(Card::CARD_2, Card::CLUB),
        Card(Card::CARD_3, Card::SPADE),
        Card(Card::CARD_4, Card::CLUB),
        Card(Card::CARD_6, Card::SPADE),
    };

    Card club_flush[5] = {
        Card(Card::ACE, Card::CLUB),
        Card(Card::CARD_2, Card::CLUB),
        Card(Card::CARD_3, Card::CLUB),
        Card(Card::CARD_4, Card::CLUB),
        Card(Card::CARD_6, Card::CLUB),
    };

    Card diamond_straight_flush[5] = {
        Card(Card::ACE, Card::DIAMOND),
        Card(Card::CARD_2, Card::DIAMOND),
        Card(Card::CARD_3, Card::DIAMOND),
        Card(Card::CARD_4, Card::DIAMOND),
        Card(Card::CARD_5, Card::DIAMOND),
    };

    Card four_ofa_kind_low[5] = {
        Card(Card::CARD_2, Card::SPADE),
        Card(Card::CARD_2, Card::CLUB),
        Card(Card::CARD_2, Card::DIAMOND),
        Card(Card::CARD_2, Card::HEART),
        Card(Card::CARD_5, Card::DIAMOND),
    };

    Card four_ofa_kind_high[5] = {
        Card(Card::CARD_2, Card::DIAMOND),
        Card(Card::CARD_3, Card::SPADE),
        Card(Card::CARD_3, Card::CLUB),
        Card(Card::CARD_3, Card::DIAMOND),
        Card(Card::CARD_3, Card::HEART),
    };

    Card fullhouse[5] = {
        Card(Card::CARD_2, Card::DIAMOND),
        Card(Card::CARD_2, Card::SPADE),
        Card(Card::CARD_2, Card::CLUB),
        Card(Card::CARD_3, Card::DIAMOND),
        Card(Card::CARD_3, Card::HEART),
    };

    Card three_ofa_kind[5] = {
        Card(Card::CARD_2, Card::DIAMOND),
        Card(Card::CARD_5, Card::SPADE),
        Card(Card::CARD_3, Card::CLUB),
        Card(Card::CARD_3, Card::DIAMOND),
        Card(Card::CARD_3, Card::HEART),
    };

    Card two_pair[5] = {
        Card(Card::CARD_2, Card::DIAMOND),
        Card(Card::CARD_2, Card::SPADE),
        Card(Card::CARD_3, Card::CLUB),
        Card(Card::CARD_3, Card::DIAMOND),
        Card(Card::CARD_5, Card::HEART),
    };

    Card low_pair[5] = {
        Card(Card::CARD_2, Card::DIAMOND),
        Card(Card::CARD_2, Card::SPADE),
        Card(Card::CARD_6, Card::CLUB),
        Card(Card::CARD_7, Card::DIAMOND),
        Card(Card::CARD_5, Card::HEART),
    };

    Card high_pair[5] = {
        Card(Card::CARD_2, Card::DIAMOND),
        Card(Card::CARD_3, Card::SPADE),
        Card(Card::CARD_6, Card::CLUB),
        Card(Card::QUEEN, Card::DIAMOND),
        Card(Card::QUEEN, Card::HEART),
    };

    test("Royal Flush", royal_flush);

    test("Royal Straight", royal_straight);

    test("Low Straight", low_straight);

    test("Not Straight", not_straight);

    test("Club Flush", club_flush);

    test("Diamond Straight Flush", diamond_straight_flush);

    test("Four Of A Kind (Low)", four_ofa_kind_low);

    test("Four Of A Kind (High)", four_ofa_kind_high);

    test("Full House", fullhouse);

    test("Three Of A Kind", three_ofa_kind);

    test("Two Pair", two_pair);

    test("Pair (Low)", low_pair);

    test("Pair (High)", high_pair);
}

/**
* Test a single hand state. (For use with test_hands().)
*/
// TODO: Make class function
void Hand::test(string name, Card *cards)
{
    Hand hand = Hand();
    Card *card;
    card = cards;
    hand.add_card(card[0]);
    hand.add_card(card[1]);
    hand.add_card(card[2]);
    hand.add_card(card[3]);
    hand.add_card(card[4]);
    cout << endl << "=== Name: " << name << " ===" << endl;
    hand.dump_hand();
}

#endif /* #if 0 */

/**
* Get a string representation of player's Hand.
* @return current calculated HandType as a string object.
* @public
*/
const string Hand::type_as_string() const
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
* @public
*/
const Hand::HandType Hand::get_hand_type() const
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
* Get the payout for the current Hand.
* @return current calculated HandType as a integer representation of payout.
* @public
*/
const unsigned int Hand::get_payout() const
{
    return get_hand_type();
}

/**
* Check if hand is a flush.
* (This function is control flow dependent.)
* @return true if the hand is a flush.
*/
bool Hand::is_flush() const
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
bool Hand::is_straight() const
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
bool Hand::is_straight_flush() const
{
    return is_flush() && is_straight();
}

/**
* Check if hand is a royal flush.
* (This function is control flow dependent.)
* @return true if the hand is a royal flush.
*/
bool Hand::is_royal_flush() const
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
bool Hand::is_four_ofa_kind() const
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
bool Hand::is_full_house() const
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
bool Hand::has_three_ofa_kind() const
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
bool Hand::has_two_pair() const
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

    /*if ((rank_vec.at(0).rank() == rank_vec.at(1).rank() &&
    rank_vec.at(2).rank() == rank_vec.at(3).rank()) ||
    (rank_vec.at(1).rank() == rank_vec.at(2).rank() &&
    rank_vec.at(3).rank() == rank_vec.at(4).rank()) ||
    (rank_vec.at(0).rank() == rank_vec.at(1).rank() &&
    rank_vec.at(3).rank() == rank_vec.at(4).rank()))
    {
    return true;
    }
    return false;*/
}

/**
* Check if hand has a pair of jacks or better.
* (This function is control flow dependent.)
* @return true if the hand is pair of jacks or better.
*/
bool Hand::has_royal_pair() const
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
