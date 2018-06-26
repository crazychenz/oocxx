#ifndef CONSOLEUI_CC
#define CONSOLEUI_CC

#include <iostream>
#include <limits>
#include <cctype>
#include <algorithm>

#include "ConsoleUI.h"

using namespace std;

ConsoleUI::ConsoleUI()
{
}

ConsoleUI::ConsoleUI(istream *in, ostream *out, ostream *err)
{
    if (in != nullptr)
        this->in_stream = in;
    if (out != nullptr)
        this->out_stream = out;
    if (err != nullptr)
        this->err_stream = err;
}

/* Got a strange issue here where if I build this member template in another
* compilation unit, the build system has no idea what to do. The only solution that
* seems to work cleanly is to include this .cc file in the associated .h file as
* suggested by the stackoverflow link below. */
//https://stackoverflow.com/questions/9352216/undefined-references-to-member-functions-of-a-class-template
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
        out() << prompt << "? ";
        getline(in(), input);
        in().clear();

        if (input.find_first_not_of("-0123456789") == string::npos)
        {
            try
            {
                string::size_type off;
                if (is_unsigned<NumType>::value)
                {
                    unsigned long long parsed;
                    parsed = stoull(input, &off);
                    if (parsed > static_cast<unsigned long long>(max))
                    {
                        const string msg =
                            "Parseable, but doesn't fall within constraints.";
                        throw out_of_range(msg);
                    }
                    output = static_cast<NumType>(parsed);
                }
                else
                {
                    long long parsed;
                    parsed = stoll(input, &off);
                    if (parsed > static_cast<long long>(max) ||
                        parsed < static_cast<long long>(min))
                    {
                        const string msg =
                            "Parseable, but doesn't fall within constraints.";
                        throw out_of_range(msg);
                    }
                    output = static_cast<NumType>(parsed);
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

static bool isnotspace(int c)
{
    return !(::isspace(c));
}

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

    } while (!all_of(input.begin(), input.end(), &isnotspace));

    output = input;
}

istream& ConsoleUI::in()
{
    return *in_stream;
}

ostream& ConsoleUI::out()
{
    return *out_stream;
}

ostream& ConsoleUI::err()
{
    return *err_stream;
}

#endif /* CONSOLEUI_CC */