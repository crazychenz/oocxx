#include <string>
#include <iostream>
#include <limits>
using namespace std;

#include "PokerArgParser.h"
#include "ArgParser.h"

/**
* Primary constructor.
* @param argc Number of arguments passed to the main() entry point.
* @param argv The argument 'vector' passed to the main() entry point.
*/
PokerArgParser::PokerArgParser(int argc, char **argv) :
    ArgParser(argc, argv)
{
    // Simply calling the super class constructor.
}

/**
* Interprets the argc/argv parameters into a argument key/value table.
*/
void PokerArgParser::parse()
{
    const int argc = get_argc();
    const char **argv = get_argv();

    // Setup defaults
    set_key("help", new ArgumentBool(false));
    //set_key("seed", new ArgumentInt(1));
    set_key("text-only", new ArgumentBool(false));
    set_key("verbose", new ArgumentBool(false));

    // Look for user defined values
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--help") {
            // Note: If we see --help, call this->usage() then terminate.
            usage();
            exit(0);
        }
        else if (std::string(argv[i]) == "--text-only") {
            set_key("text-only", new ArgumentBool(true));
        }
        else if (std::string(argv[i]) == "--verbose") {
            set_key("verbose", new ArgumentBool(true));
        }
        else if (std::string(argv[i]) == "--seed") {
            if (argc - 1 == i)
            {
                // We're out of arguments and we still need one more.
                throw invalid_argument("Missing argument for --seed.");
            }

            unsigned int seed;
            unsigned int max = numeric_limits<unsigned int>::max();
            io.parse_numeric_input<unsigned int>(argv[i + 1], seed, 0, max);

            set_key("seed", new ArgumentInt(seed));
        }
    }
}

/**
* Show the CLI usage of the application.
*/
void PokerArgParser::usage()
{
    const char **argv = get_argv();
    cout << "Usage: " << argv[0] << " [--seed SEED]\n" << endl;
    cout << "Play a game of poker (five card stud)." << endl;
    cout << endl;
    cout << "With no SEED, current time is used." << endl;
    cout << endl;
    cout << "  --help      - show this help message" << endl;
    cout << "  --seed      - seed the PRNG for deterministic shuffles" << endl;
    cout << "  --text-only - show text based hands" << endl;
    cout << "  --verbose   - increase the verbosity of output" << endl;
    cout << endl;
    cout << "Examples:" << endl;
    cout << "  " << argv[0] << " --seed 23443" << endl;
    cout << "  " << argv[0] << endl;
    cout << endl;
}
