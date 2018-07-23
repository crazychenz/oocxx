#include <sstream>
#include <string>

#include "Date.h"

using namespace std;

Date::Date()
{
}

Date::Date(int month, int date, int year)
    : month(month), date(date), year(year)
{
}

int
Date::get_month() const
{
    return month;
}

int
Date::get_date() const
{
    return date;
}

int
Date::get_year() const
{
    return year;
}

string
Date::to_string() const
{
    stringstream ss;
    ss << get_month() << "/" << get_date() << "/" << get_year();
    return ss.str();
}

std::ostream&
operator<<(std::ostream& stream, const Date& d)
{
    stream << d.to_string();
    return stream;
}