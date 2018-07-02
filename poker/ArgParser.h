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
    class ArgumentBaseType
    {
    };

    class ArgumentBool : public ArgumentBaseType
    {
    public:
        ArgumentBool(bool v) : value(v) {}
        bool value;
    };

    class ArgumentInt : public ArgumentBaseType
    {
    public:
        ArgumentInt(long long v) : value(v) {}
        long long value;
    };

    class ArgumentRaw : public ArgumentBaseType
    {
    public:
        ArgumentRaw(std::string v) : value(v) {}
        std::string value;
    };

    ArgParser(const int argc, char **argv)
    {
        parse(argc, argv);
    }
    
    void parse(const int argc, char **argv)
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
    
    void set_key(std::string key, ArgumentBaseType *value)
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

    bool has_key(const std::string &name)
    {
        std::map<std::string, ArgumentBaseType *>::iterator it = args.find(name);
        if(it != args.end())
        {
           return true;
        }
        return false;
    }

    long long get_int(const std::string &name) const
    {
        return ((ArgumentInt *)(args.find(name)->second))->value;
    }
    
    std::string get_raw(const std::string &name) const
    {
        return ((ArgumentRaw *)(args.find(name)->second))->value;
    }
    
    bool get_bool(const std::string &name) const
    {
        return ((ArgumentBool *)(args.find(name)->second))->value;
    }

private:

    std::map<std::string, ArgumentBaseType *> args;

};

#endif /* ARGPARSER_H */
