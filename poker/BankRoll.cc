#include "BankRoll.h"

/**
* Default BankRoll Constructor
*/
BankRoll::BankRoll()
{
}

/**
* Get the BankRoll balance.
* @return The BankRoll balance as an unsigned integer.
*/
unsigned int BankRoll::get_balance() const
{
    return coins;
}

/**
* Deposit coins into the BankRoll.
* @param coins Number of coins to deposit as an unsigned integer.
*/
void BankRoll::deposit(const unsigned int coins)
{
    this->coins += coins;
}

/**
* Withdraw coins from the bankroll.
* @param coins Number of coins to withdraw as unsigned integer.
* @return The remaining balance as an unsigned integer.
*/
unsigned int BankRoll::withdraw(const unsigned int coins)
{
    unsigned int to_withdraw = coins > get_balance() ? get_balance() : coins;
    this->coins -= to_withdraw;
    
    return get_balance();
}

/**
* Withdraw all coins from the bankroll.
* @return The balance as an unsigned integer.
*/
unsigned int BankRoll::cash_out()
{
    return withdraw(get_balance());
}