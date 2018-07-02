#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <iostream>
#include <limits>

/**
* @class ConsoleUI
* @brief Console support class for managing input and output streams.
*/
class ConsoleUI
{
public:

    ConsoleUI();

    ConsoleUI(std::istream *in, std::ostream *out, std::ostream *err);

    std::istream& in() const;
    std::ostream& out() const;
    std::ostream& err() const;

    template <typename NumType>
    void parse_numeric_input(
        const std::string &input,
        NumType &output,
        const NumType min,
        const NumType max);

    template <typename NumType>
    void get_numeric_input(
        const std::string &prompt,
        NumType &output,
        const NumType min,
        const NumType max);

    template <typename NumType>
    void get_numeric_input(
        const std::string &prompt,
        NumType &output);

    void get_single_word_input(
        const std::string &prompt,
        std::string &output);

private:


    static unsigned long long
    get_ull_value(
        const std::string &input,
        const unsigned long long min,
        const unsigned long long max);

    static long long
    get_ll_value(
        const std::string &input,
        const long long min,
        const long long max);

    std::string&
    prompted_getline(
        const std::string &prompt,
        std::string &input);

    static bool
    isnotspace(const int c);

    /** Input stream, defaulted to standard input stream. */
    std::istream *in_stream = &std::cin;
    /** Output stream, defaulted to standard output stream. */
    std::ostream *out_stream = &std::cout;
    /** Error stream, defaulted to standard error stream. */
    std::ostream *err_stream = &std::cerr;
    
   
};

/**
* parse_numeric_input parses numeric input from a stream.
*
* @param input The input string to parse.
* @param output The reference that returns the retrieved value.
* @param min The minimum allowable value. (Inclusive)
* @param max The maximum allowable value. (Inclusive)
* @throws invalid_argument if input is not decimal.
* @throws out_of_range if input not within constraints.
*/
template <typename NumType>
void ConsoleUI::parse_numeric_input(
    const std::string &input,
    NumType &output,
    const NumType min,
    const NumType max)
{
    using namespace std;

    if (input.find_first_not_of("-0123456789") == string::npos)
    {
        if (is_unsigned<NumType>::value)
        {
            output = static_cast<NumType>(
                ConsoleUI::get_ull_value(input, min, max));
            return;
        }

        output = static_cast<NumType>(
            ConsoleUI::get_ll_value(input, min, max));
        return;
    }
    throw std::invalid_argument("Input must be numeric in decimal notation.");
}

/**
* get_numeric_input fetches numeric input from a stream.
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

        try
        {
            parse_numeric_input<NumType>(input, output, min, max);
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

#endif /* CONSOLEUI_H */