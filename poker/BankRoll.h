#ifndef BANKROLL_H
#define BANKROLL_H

class BankRoll
{
public:
    BankRoll()
    {
    }

    unsigned int get_balance()
    {
        return coins;
    }

    void deposit(const unsigned int coins)
    {
        this->coins += coins;
    }

    unsigned int withdraw(const unsigned int coins)
    {
        if (coins > get_balance())
        {
            return cash_out();
        }

        this->coins -= coins;
        return coins;
    }

    unsigned int cash_out()
    {
        unsigned int coins = this->coins;
        this->coins = 0;
        return coins;
    }

private:
    unsigned int coins = 0;
};

#endif