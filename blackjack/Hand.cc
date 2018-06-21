#include "Hand.h"
#include "Card.h"

Hand::Hand()
{

}

void Hand::add_faceup(Card card)
{
    faceup += card.get_value();
}

void Hand::add_facedown(Card card)
{
    facedown += card.get_value();
}

int Hand::visible_points()
{
    return faceup;
}

int Hand::all_points()
{
    return faceup + facedown;
}