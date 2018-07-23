#include <string>
#include <iostream>

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
    int month = 1;
    int date = 1;
    int year = 1;
};

std::ostream&
operator<<(std::ostream& stream, const Date& d);