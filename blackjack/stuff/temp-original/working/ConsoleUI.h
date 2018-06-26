#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <iostream>
#include <limits>

class ConsoleUI
{
public:

    ConsoleUI();

    ConsoleUI(std::istream *in, std::ostream *out, std::ostream *err);

    std::istream& in();
    std::ostream& out();
    std::ostream& err();

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

    std::istream *in_stream = &std::cin;
    std::ostream *out_stream = &std::cout;
    std::ostream *err_stream = &std::cerr;
    
   
};

#include "ConsoleUI.cc"

#endif /* CONSOLEUI_H */
