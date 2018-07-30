#include <string>

/**
* @class Ship
* @brief A ship class with a name and cargo priority.
*/
class Ship
{
public:
    Ship(std::string name, int priority);

    int get_priority() const;

    std::string get_name() const;

    bool operator<(const Ship& ship) const;

private:
    /** 1 (highest) to 10 (lowest) priority. */
    int cargo_priority = 10;

    /** The name of the ship. */
    std::string name;
};
