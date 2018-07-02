#ifndef BANKROLL_H
#define BANKROLL_H

/**
* @class BankRoll
* @brief Class that represents the number of coins in the machine.
*/
class BankRoll
{
public:
    BankRoll();

    unsigned int get_balance() const;

    void deposit(const unsigned int coins);

    unsigned int withdraw(const unsigned int coins);

    unsigned int cash_out();

private:

    /** Number of coins currently in bank roll. */
    unsigned int coins = 0;
};

#endif