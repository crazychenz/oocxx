#include <string>
#include <iostream>

/**
* @class Date
* @brief A class representing a Date with month, day/date, and year.
*/
class Date
{
public:
    Date();

    Date(int month, int date, int year);

    int
    get_month() const;

    int
    get_date() const;

    int
    get_year() const;

    std::string
    to_string() const;

private:
    /** Default month to Jan. */
    int month = 1;
    /** Default day of month to 1. */
    int date = 1;
    /** Default year to 1 anno domini. */
    int year = 1;
};

std::ostream&
operator<<(std::ostream& stream, const Date& d);