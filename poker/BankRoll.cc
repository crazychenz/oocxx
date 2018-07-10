#include <string>
#include <stdexcept>

using namespace std;

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
unsigned int
BankRoll::get_balance() const
{
    return coins;
}

/**
* Deposit coins into the BankRoll.
* @param coins Number of coins to deposit as an unsigned integer.
* @throws out_of_range when a potential interger overrun detected.
*/
void
BankRoll::deposit(const unsigned int coins)
{
    // Sanity check deposit amount.
    if (this->coins + coins < this->coins)
    {
        const string msg =
            "Bankroll can not hold requested coin amount.";
        throw out_of_range(msg);
    }

    // Do the deposit.
    this->coins += coins;
}

/**
* Withdraw coins from the bankroll.
* @param coins Number of coins to withdraw as unsigned integer.
* @throws bad_argument when more coins requested than exist in balance.
* @return The remaining balance as an unsigned integer.
*/
unsigned int
BankRoll::withdraw(const unsigned int coins)
{
    // Sanity check withdraw.
    if (coins > get_balance())
    {
        const string msg =
            "Invalid number of coins requested for withdraw.";
        throw invalid_argument(msg);
    }

    // Do withdraw.
    this->coins -= coins;

    // Return remaining balance.
    return get_balance();
}

/**
* Withdraw all coins from the bankroll.
* @return The amount withdrawn as an unsigned integer.
*/
unsigned int
BankRoll::cash_out()
{
    unsigned int balance = get_balance();
    withdraw(balance);
    return balance;
}