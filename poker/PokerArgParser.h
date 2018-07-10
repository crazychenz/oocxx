#include "ArgParser.h"
#include "StreamHelper.h"

/**
* @class PokerArgParser
* @brief Implementation of ArgParser super class.
*/
class PokerArgParser : public ArgParser
{
public:
    PokerArgParser(int argc, char **argv);

    void parse();

    void usage();

private:

    /** Stream helper for parsing seed input. */
    StreamHelper io = StreamHelper();
};