#include <string>
#include <map>

using namespace std;

#include "ArgParser.h"

/**
* Primary constructor.
* @param argc Number of arguments passed to the main() entry point.
* @param argv The argument 'vector' passed to the main() entry point.
*/
ArgParser::ArgParser(const int argc, char **argv)
{
    parse(argc, argv);
}

/**
* Interprets the argc/argv parameters into a argument key/value table.
* @param argc Number of arguments passed to the main() entry point.
* @param argv The argument 'vector' passed to the main() entry point.
*/
void ArgParser::parse(const int argc, char **argv)
{
    // Setup defaults
    set_key("help", new ArgumentBool(false));
    set_key("seed", new ArgumentInt(1));

    // Look for user defined values
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--help") {
            set_key("help", new ArgumentBool(true));
        } else if (std::string(argv[i]) == "--seed") {
            if (argc - 1 == i)
            {
                // We're out of arguments and we still need one more.
                // TODO: Throw exception.
            }
            // TODO: Use ConsoleUI stoll helper code.
            set_key("seed", new ArgumentInt(atoi(argv[i + 1])));
        }
    }
}

/**
* Adds a key/value pair to the key/value args table.
* @param key The key part of the key/value pair.
* @param value A ArgumentBaseType as the value part of the key/value pair.
*/
void ArgParser::set_key(std::string key, ArgumentBaseType *value)
{
    std::map<std::string, ArgumentBaseType *>::iterator it = args.find(key);
    if(it != args.end())
    {
        // First delete the value object memory.
        delete args[key];
        // Finally remove map entry.
        args.erase(it);
    }
    if (value)
    {
        // Only create new key if value is not NULL.
        args[key] = value;
    }
}

/**
* Determines if an entry with a given key exists.
* @param key The key part of the entry to look for.
* @return true if the key exists, false if no key found.
*/
bool ArgParser::has_key(const std::string &key)
{
    std::map<std::string, ArgumentBaseType *>::iterator it = args.find(key);
    if(it != args.end())
    {
        return true;
    }
    return false;
}

/**
* Fetch the value of a key/value pair as a integer.
* @param key The key part of the entry to look for.
* @return value of entry as a (signed) long long
*/
long long ArgParser::get_int(const std::string &key) const
{
    return ((ArgumentInt *)(args.find(key)->second))->value;
}

/**
* Fetch the value of a key/value pair as a string.
* @param key The key part of the entry to look for.
* @return value of entry as a string
*/
std::string ArgParser::get_raw(const std::string &key) const
{
    return ((ArgumentRaw *)(args.find(key)->second))->value;
}

/**
* Fetch the value of a key/value pair as a boolean.
* @param key The key part of the entry to look for.
* @return value of entry as a bool
*/
bool ArgParser::get_bool(const std::string &key) const
{
    return ((ArgumentBool *)(args.find(key)->second))->value;
}