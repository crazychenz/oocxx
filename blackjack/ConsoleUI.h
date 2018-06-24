#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <iostream>
#include <limits>

class ConsoleUI
{
public:

    ConsoleUI();

    ConsoleUI(std::istream *in, std::ostream *out, std::ostream *err);

    std::istream& in() const;
    std::ostream& out() const;
    std::ostream& err() const;

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

    std::istream *in_stream = &std::cin;
    std::ostream *out_stream = &std::cout;
    std::ostream *err_stream = &std::cerr;
    
   
};

#include "ConsoleUI.cc"

#endif /* CONSOLEUI_H */