#ifndef ARGPARSER_H
#define ARGPARSER_H

#include "ConsoleUI.h"

/**
* @class ArgParser
* @brief Crude class for parsing out the seed or help from CLI arguments.
*/
class ArgParser
{
public:
    ArgParser(
        ConsoleUI &ui,
        const int argc,
        char **argv);

    unsigned int get_seed() const;

private:
    
    /** Seed used to initialize the Deck (via the Dealer). */
    unsigned int seed = 0;
};

#endif