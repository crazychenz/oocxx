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
    StreamHelper io = StreamHelper();
};