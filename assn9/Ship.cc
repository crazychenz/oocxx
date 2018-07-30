#include <stdexcept>
#include <string>

#include "Ship.h"

/**
* A Ship constructor.
* @param name - The name of the ship (as a string)
* @param priority - The priority of the cargo. 1 (highest) thru 10 (lowest).
*/
Ship::Ship(std::string name, int priority)
{
    if (priority < 1 || priority > 10)
    {
        std::string msg = "Ship priority must be between 1 and 10 inclusive.";
        throw std::invalid_argument(msg);
    }
    this->name = name;
    cargo_priority = priority;
}

/**
* Fetch the cargo priority of the Ship.
* @returns the cargo priority as an int.
*/
int
Ship::get_priority() const
{
    return cargo_priority;
}

/**
* Fetch the name of the Ship.
* @returns the name as a string.
*/
std::string
Ship::get_name() const
{
    return name;
}

/**
* Compare the priority of this ship to another.
* @param ship - Reference to the other ship to compare to.
* @returns True if this ship has higher priority.
*/
bool
Ship::operator<(const Ship& ship) const
{
    return get_priority() > ship.get_priority();
}