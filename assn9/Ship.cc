#include <stdexcept>
#include <string>

#include "Ship.h"

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

int
Ship::get_priority() const
{
    return cargo_priority;
}

std::string
Ship::get_name() const
{
    return name;
}

bool
Ship::operator<(const Ship& ship) const
{
    return get_priority() > ship.get_priority();
}