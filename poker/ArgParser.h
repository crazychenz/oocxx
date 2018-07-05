#ifndef ARGPARSER_H
#define ARGPARSER_H

#include <string>
#include <map>

/**
* @class ArgParser
* @brief Crude class for parsing out the seed or help from CLI arguments.
*/
class ArgParser
{
public:

    /**
    * @class ArgumentBaseType
    * @brief The base class for Argument values.
    */
    class ArgumentBaseType
    {
    };

    /**
    * @class ArgumentBool
    * @brief For storing boolean arguments
    */
    class ArgumentBool : public ArgumentBaseType
    {
    public:
        /** Boolean Constructor */
        ArgumentBool(bool v) : value(v) {}
        /** Boolean value represented by this class. */
        bool value;
    };

    /**
    * @class ArgumentInt
    * @brief For storing numeric arguments.
    */
    class ArgumentInt : public ArgumentBaseType
    {
    public:
        /** Integer Constructor */
        ArgumentInt(long long v) : value(v) {}
        /** Integer value represented by this class. */
        long long value;
    };

    /**
    * @class ArgumentRaw
    * @brief For storing string arguments.
    */
    class ArgumentRaw : public ArgumentBaseType
    {
    public:
        /** String Constructor */
        ArgumentRaw(std::string v) : value(v) {}
        /** String value represented by this class. */
        std::string value;
    };

    ArgParser(const int argc, char **argv);

    void parse(const int argc, char **argv);

    void set_key(std::string key, ArgumentBaseType *value);

    bool has_key(const std::string &name);

    long long get_int(const std::string &name) const;

    std::string get_raw(const std::string &name) const;

    bool get_bool(const std::string &name) const;

    const int get_argc() const;

    const char** get_argv() const;

private:

    /** Parsed arguments. */
    std::map<std::string, ArgumentBaseType *> args;

    /** The number of arguments passed for parsing. */
    int argc;

    /** An array of char* that each point to an argument. */
    char **argv;

};

#endif /* ARGPARSER_H */
