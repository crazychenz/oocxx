#ifndef HAND_H
#define HAND_H

#include <vector>
#include <algorithm>

#include "Card.h"

bool comp_rank(Card &x, Card &y)
{
    return x.get_rank_value() < y.get_rank_value();
}

bool comp_suit(Card &x, Card &y)
{
    return x.get_suit_value() < y.get_suit_value();
}

class Hand
{
public:

    enum HandType : int
    {
        ROYAL_FLUSH = 250,
        STRAIGHT_FLUSH= 50,
        FOUR_OFA_KIND = 25,
        FULL_HOUSE = 9,
        FLUSH = 6,
        STRAIGHT = 4,
        THREE_OFA_KIND = 3,
        TWO_PAIR = 2,
        JACKS_OR_BETTER = 1,
        NOTHING = 0,
    };


    Hand()
    {
        //rank_vec = std::vector<Card &>();
        //suit_vec = std::vector<Card &>();
    }

    void add_card(Card card)
    {
        rank_vec.push_back(card);
        rank_sort();

        return;
    }

    const vector<Card> get_hand() const
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

    void redeal(int idx, Card new_card)
    {
        Card old_card = rank_vec.at(idx);
        replace(rank_vec.begin(), rank_vec.end(), old_card, new_card);
        //locked.push_back(new_card);
    }

    void rank_sort()
    {
        sort(rank_vec.begin(), rank_vec.end(), comp_rank);
    }

    void dump_hand()
    {

        /* Dump attributes. */
        cout << "payout: " << get_payout() << endl;
        cout << "royal flush: " << is_royal_flush() << endl;
        cout << "is flush: " << is_flush() << endl;
        cout << "is straight: " << is_straight() << endl;
        cout << "is straight flush: " << is_straight_flush() << endl;
        cout << "is four ofa kind: " << is_four_ofa_kind() << endl;
        cout << "is full house: " << is_full_house() << endl;
        cout << "has three ofa kind: " << has_three_ofa_kind() << endl;
        cout << "has two pair: " << has_two_pair() << endl;
        cout << "has_pair: " << has_royal_pair() << endl;

        /* Dump rank sorted. */
        cout << "--- Rank sorted: ---" << endl;
        for (vector<Card>::iterator it = rank_vec.begin(); it < rank_vec.end(); it++)
        {
            cout << it->to_string() << endl;
        }
        cout << endl;

        /* Dump suit sorted. */
        /*cout << "--- Suit sorted: ---" << endl;
        for (vector<Card>::iterator it = suit_vec.begin(); it < suit_vec.end(); it++)
        {
        	cout << it->to_string() << endl;
        }
        cout << endl;*/


    }

    // TODO: Make class function
    void test_hands()
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

    string type_as_string()
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

    HandType get_hand_type()
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

    int get_payout()
    {
        return get_hand_type();
    }

private:

    // TODO: Make class function
    void test(string name, Card *cards)
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

    bool is_flush()
    {
        vector<Card> suit_vec = rank_vec;
        sort(suit_vec.begin(), suit_vec.end(), comp_suit);
        return suit_vec.at(0).get_suit_value() == suit_vec.at(4).get_suit_value();
    }

    bool is_straight()
    {
        if (rank_vec.at(0).get_rank_value() == Card::CARD_2 &&
                rank_vec.at(1).get_rank_value() == Card::CARD_3 &&
                rank_vec.at(2).get_rank_value() == Card::CARD_4 &&
                rank_vec.at(3).get_rank_value() == Card::CARD_5 &&
                rank_vec.at(4).get_rank_value() == Card::ACE)
        {
            return true;
        }

        int start = rank_vec.begin()->get_rank_value();
        for (vector<Card>::iterator it = rank_vec.begin(); it < rank_vec.end(); ++it, ++start)
        {
            if (it->get_rank_value() != start)
            {
                return false;
            }
        }
        return true;
    }

    bool is_straight_flush()
    {
        return is_flush() && is_straight();
    }

    bool is_royal_flush()
    {
        return is_straight_flush() &&
               rank_vec.at(0).get_rank_value() == Card::CARD_10 &&
               rank_vec.at(4).get_rank_value() == Card::ACE;
    }

    bool is_four_ofa_kind()
    {
        if ((rank_vec.at(0).get_rank_value() == rank_vec.at(1).get_rank_value() &&
                rank_vec.at(1).get_rank_value() == rank_vec.at(2).get_rank_value() &&
                rank_vec.at(2).get_rank_value() == rank_vec.at(3).get_rank_value()) ||
                (rank_vec.at(1).get_rank_value() == rank_vec.at(2).get_rank_value() &&
                 rank_vec.at(2).get_rank_value() == rank_vec.at(3).get_rank_value() &&
                 rank_vec.at(3).get_rank_value() == rank_vec.at(4).get_rank_value()))
        {
            return true;
        }
        return false;
    }

    // Assumed not four of a kind.
    bool is_full_house()
    {
        if ((rank_vec.at(0).get_rank_value() == rank_vec.at(1).get_rank_value() &&
                rank_vec.at(1).get_rank_value() == rank_vec.at(2).get_rank_value() &&
                rank_vec.at(3).get_rank_value() == rank_vec.at(4).get_rank_value()) ||
                (rank_vec.at(4).get_rank_value() == rank_vec.at(3).get_rank_value() &&
                 rank_vec.at(3).get_rank_value() == rank_vec.at(2).get_rank_value() &&
                 rank_vec.at(1).get_rank_value() == rank_vec.at(0).get_rank_value()))
        {
            return true;
        }
        return false;
    }

    // Assumed not four of a kind OR full house
    bool has_three_ofa_kind()
    {
        if ((rank_vec.at(0).get_rank_value() == rank_vec.at(1).get_rank_value() &&
                rank_vec.at(1).get_rank_value() == rank_vec.at(2).get_rank_value()) ||
                (rank_vec.at(1).get_rank_value() == rank_vec.at(2).get_rank_value() &&
                 rank_vec.at(2).get_rank_value() == rank_vec.at(3).get_rank_value()) ||
                (rank_vec.at(2).get_rank_value() == rank_vec.at(3).get_rank_value() &&
                 rank_vec.at(3).get_rank_value() == rank_vec.at(4).get_rank_value()))
        {
            return true;
        }
        return false;
    }

    // Assumed not three ofa kind, not four ofa kind, AND not full house
    bool has_two_pair()
    {
        int table[3][4] = {
            { 0, 1, 2, 3 },
            { 1, 2, 3, 4 },
            { 0, 1, 3, 4 },
        };

        for (int i = 0; i < 3; ++i)
        {
            if (rank_vec.at(table[i][0]).get_rank_value() == rank_vec.at(table[i][1]).get_rank_value() &&
                    rank_vec.at(table[i][2]).get_rank_value() == rank_vec.at(table[i][3]).get_rank_value())
            {
                return true;
            }
        }
        return false;

        /*if ((rank_vec.at(0).get_rank_value() == rank_vec.at(1).get_rank_value() &&
        rank_vec.at(2).get_rank_value() == rank_vec.at(3).get_rank_value()) ||
        (rank_vec.at(1).get_rank_value() == rank_vec.at(2).get_rank_value() &&
        rank_vec.at(3).get_rank_value() == rank_vec.at(4).get_rank_value()) ||
        (rank_vec.at(0).get_rank_value() == rank_vec.at(1).get_rank_value() &&
        rank_vec.at(3).get_rank_value() == rank_vec.at(4).get_rank_value()))
        {
        return true;
        }
        return false;*/
    }

    bool has_royal_pair()
    {
        for (int i = 0; i < 4; ++i)
        {
            if (rank_vec.at(i).get_rank_value() == rank_vec.at(i + 1).get_rank_value() &&
                    rank_vec.at(i).get_rank_value() >= Card::JACK) {
                return true;
            }
        }
        return false;
    }

    //std::vector<Card> locked;
    std::vector<Card> rank_vec;
};

#endif