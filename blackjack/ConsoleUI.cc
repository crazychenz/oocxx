#ifndef CONSOLEUI_CC
#define CONSOLEUI_CC

#include <iostream>
#include <limits>
#include <cctype>
#include <algorithm>

#include "ConsoleUI.h"

using namespace std;

/**
* Default Constructor
*/
ConsoleUI::ConsoleUI()
{
}

/**
* Explicit constructor for providing specific streams.
* @param in The input stream.
* @param out The output stream.
* @param err The error stream.
*/
ConsoleUI::ConsoleUI(istream *in, ostream *out, ostream *err)
{
    if (in != nullptr)
        this->in_stream = in;
    if (out != nullptr)
        this->out_stream = out;
    if (err != nullptr)
        this->err_stream = err;
}


unsigned long long 
ConsoleUI::get_ull_value(
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

long long 
ConsoleUI::get_ll_value(
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

string&
ConsoleUI::prompted_getline(
    const std::string &prompt,
    string &input)
{
    out() << prompt << "? ";
    getline(in(), input);
    in().clear();

    return input;
}

/** get_numeric_input fetches numeric input from a stream.
*
* This function is intended as a way to ensure clear and clean
* retrieval of numeric values from a user. The function operates
* by delimiting all values with a newline and then treating each
* line atomically. The function is provided a min and max 
* constraint to further check if the value is parsable and 
* assignable within the given template type.
*
* @param prompt The text from to place on console for the user.
* @param output The reference that returns the retrieved value.
* @param min The minimum allowable value. (Inclusive)
* @param max The maximum allowable value. (Inclusive)
*
* Got a strange issue here where if I build this member template in another
* compilation unit, the build system has no idea what to do. The only solution
* that seems to work cleanly is to include this .cc file in the associated .h
* file as suggested by the stackoverflow link below. 
*
* https://stackoverflow.com/questions/9352216/undefined-references-to-member-functions-of-a-class-template
* 
*/
template <typename NumType>
void ConsoleUI::get_numeric_input(
    const std::string &prompt,
    NumType &output,
    const NumType min,
    const NumType max)
{
    using namespace std;
    string input;

    do
    {
        prompted_getline(prompt, input);

        if (input.find_first_not_of("-0123456789") == string::npos)
        {
            try
            {
                if (is_unsigned<NumType>::value)
                {
                    output = static_cast<NumType>(
                        ConsoleUI::get_ull_value(input, min, max));
                }
                else
                {
                    output = static_cast<NumType>(
                        ConsoleUI::get_ll_value(input, min, max));
                }
                break;
            }
            catch (out_of_range &oor)
            {
                err() << "Given value out of range. Must be between " <<
                    min << " and " << max << "." << endl;
            }
            catch (invalid_argument &ia)
            {
                err() << "Input must be a decimal number." << endl;
            }
        }

    } while (true);

}

/** get_numeric_input fetches numeric input from a stream.
*
* This function is intended as a way to ensure clear and clean
* retrieval of numeric values from a user. The function operates
* by delimiting all values with a newline and then treating each
* line atomically. 
*
* @param prompt The text from to place on console for the user.
* @param output The reference that returns the retrieved value.
*/
template <typename NumType>
void ConsoleUI::get_numeric_input(
    const std::string &prompt,
    NumType &output)
{
    using namespace std;
    NumType min = numeric_limits<NumType>::min();
    NumType max = numeric_limits<NumType>::max();

    get_numeric_input<NumType>(prompt, output, min, max);
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
bool ConsoleUI::isnotspace(const int c)
{
    return !(::isspace(c));
}

/**
* Prompts the user to input a single word response.
* @param prompt The string prompt to present to the user.
* @param output The single word reference string returned to user.
*/
void ConsoleUI::get_single_word_input(
    const std::string &prompt,
    string &output)
{
    using namespace std;
    string input;

    do
    {
        out() << prompt << "? ";
        getline(in(), input);
        in().clear();

    } while (!all_of(input.begin(), input.end(), &ConsoleUI::isnotspace));

    output = input;
}
/**
* Fetches the internally stored input stream.
*/
istream& ConsoleUI::in() const
{
    return *in_stream;
}

/**
* Fetches the internally stored output stream.
*/
ostream& ConsoleUI::out() const
{
    return *out_stream;
}

/**
* Fetches the internally stored error output stream.
*/
ostream& ConsoleUI::err() const
{
    return *err_stream;
}

#endif /* CONSOLEUI_CC */