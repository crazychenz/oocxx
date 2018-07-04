#include <iostream>
#include <limits>
#include <cctype>
#include <algorithm>

#include "StreamHelper.h"

using namespace std;

/**
* Default Constructor
*/
StreamHelper::StreamHelper()
{
}

/**
* Explicit constructor for providing specific streams.
* @param in The input stream.
* @param out The output stream.
* @param err The error stream.
*/
StreamHelper::StreamHelper(std::istream *in, std::ostream *out, std::ostream *err)
{
    if (in != nullptr)
        this->in_stream = in;
    if (out != nullptr)
        this->out_stream = out;
    if (err != nullptr)
        this->err_stream = err;
}

/**
* Parse numeric string into primitive unsigned datatype and check constraints.
* When the parsed input doesn't meet constriants, std::out_of_range()
* exception is thrown.
*
* @param input A string reference of the data to be parsed.
* @param min The minumum allowable value of the parsed input string.
* @param min The maximum allowable value of the parsed input string.
* @return Returns the parsed input string as a unsigned long long.
* @throws out_of_range when @p min or @p max constraints are not met.
*/
unsigned long long
StreamHelper::get_ull_value(
    const string &input,
    const unsigned long long min,
    const unsigned long long max)
{
    unsigned long long parsed;
    string::size_type off;
    parsed = stoull(input, &off);
    if (parsed > static_cast<unsigned long long>(max) ||
            parsed < static_cast<unsigned long long>(min))
    {
        const string msg =
            "Parseable, but doesn't fall within constraints.";
        throw out_of_range(msg);
    }
    return parsed;
}

/**
* Parse numeric string into primitive signed datatype and check constraints.
* When the parsed input doesn't meet constriants, std::out_of_range()
* exception is thrown.
*
* @param input A string reference of the data to be parsed.
* @param min The minumum allowable value of the parsed input string.
* @param min The maximum allowable value of the parsed input string.
* @return Returns the parsed input string as a long long.
* @throws out_of_range when @p min or @p max constraints are not met.
*/
long long
StreamHelper::get_ll_value(
    const string &input,
    const long long min,
    const long long max)
{
    long long parsed;
    string::size_type off;
    parsed = stoll(input, &off);
    if (parsed > static_cast<long long>(max) ||
            parsed < static_cast<long long>(min))
    {
        const string msg =
            "Parseable, but doesn't fall within constraints.";
        throw out_of_range(msg);
    }
    return parsed;
}

/**
* Prompt the user for a single 'newline' of data.
*
* Note: When the function returns, the input stream is cleared.
*
* @param prompt The prompt that indicates the field to be filled in.
* @param input A reference to a string to return the user input with.
*/
string&
StreamHelper::prompted_getline(
    const std::string &prompt,
    string &input)
{
    out() << prompt << "? ";
    getline(in(), input);
    in().clear();

    return input;
}

/**
* Checks if a given character is non-whitespace.
*
* This function is intended to be used as a callable predicate in all_of()
* Note that isnotspace() is not part of the ConsoleUI class.
*
* @param c The character value to check.
* @return Returns true if character is not a whitespace. False otherwise.
*/
bool StreamHelper::isnotspace(const int c)
{
    return !(::isspace(c));
}

/**
* Prompts the user to input a single word response.
* @param prompt The string prompt to present to the user.
* @param output The single word reference string returned to user.
*/
void StreamHelper::get_single_word_input(
    const std::string &prompt,
    string &output)
{
    using namespace std;
    string input;

    do
    {
        prompted_getline(prompt, input);

    } while (!all_of(input.begin(), input.end(), &StreamHelper::isnotspace));

    output = input;
}
/**
* Fetches the internally stored input stream.
*/
istream& StreamHelper::in() const
{
    return *in_stream;
}

/**
* Fetches the internally stored output stream.
*/
ostream& StreamHelper::out() const
{
    return *out_stream;
}

/**
* Fetches the internally stored error output stream.
*/
ostream& StreamHelper::err() const
{
    return *err_stream;
}

