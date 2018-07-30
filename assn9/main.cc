
#include <queue>
#include <stdexcept>
#include <iostream>
#include <string>

#include "Ship.h"

int main()
{
    // Create the priority queue object
    std::priority_queue<Ship> ship_q;

    // Add some ships with different (out of order) priorities.
    ship_q.push(Ship("Aurora", 3));
    ship_q.push(Ship("USS Eldridge", 10));
    ship_q.push(Ship("Titanic", 1));
    ship_q.push(Ship("Black Pearl", 5));

    // Pop each ship off queue, showing their name and priority.
    // Note: They should come out of the queue prioritized highest
    //       to lowest.
    while (ship_q.size())
    {
        const Ship &ship = ship_q.top();
        std::cout << ship.get_name() << ": " << ship.get_priority() << std::endl;
        ship_q.pop();
    }

    // Wait for use to press key.
    std::cout << "Press any key to exit." << std::endl;
    getchar();

    return 0;
}