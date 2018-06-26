#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

#include "ArgParser.h"

/**
* Constructor for argument parsing.
* @param ui Reference to the ConsoleUI object.
* @param argc Number of CLI arguments.
* @param argv Vector of null terminated CLI arguments.
*/
ArgParser::ArgParser(
    ConsoleUI &ui,
    const int argc,
    char **argv)
{
    if (argc > 1)
    {
        if (string(argv[1]) == "--help" || string(argv[1]) == "-h")
        {
            ui.out() << "Usage: " << argv[0] << " [SEED]\n" << endl <<
                "Play a game of blackjack." << endl << endl <<
                "With no SEED, current time is used." << endl << endl <<
                "  -h, --help - show this help message" << endl << endl <<
                "Examples:" << endl <<
                "  " << argv[0] << " 23443" << endl <<
                "  " << argv[0] << endl << endl;
            exit(0);
        }

        try
        {
            ui.parse_numeric_input<unsigned int>(
                string(argv[1]),
                seed,
                numeric_limits<unsigned int>::min(),
                numeric_limits<unsigned int>::max());
        }
        catch (out_of_range &oor)
        {
            ui.err() << "Given seed value out of range. Must be between " <<
                numeric_limits<unsigned int>::min() << " and " <<
                numeric_limits<unsigned int>::max() << "." << endl;
            exit(0);
        }
        catch (invalid_argument &ia)
        {
            ui.err() << "Unrecognized argument: " << argv[1] << endl;
            exit(0);
        }
    }
    else
    {
        seed = static_cast<unsigned int>(time(NULL));
    }
}

/**
* Fetch the seed as processed by ArgParser.
*/
unsigned int ArgParser::get_seed() const
{
    return seed;
}