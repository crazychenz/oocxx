#include <sstream>
#include <string>
#include <stdexcept>

#include "Date.h"

using namespace std;

/** Default constructor. Using C++11 initializers, so does nothing. */
Date::Date()
{
}

/** Explicity constructor. Mostly sanity checks inputs.
* @param month - The month of the year. (Can be 1 thru 12 inclusive.)
* @param date - The date of the month. (Follows Julian calendar rules.)
* @param year - The year in anno domini. (<0 and >=0 years allowed.)
*/
Date::Date(int month, int date, int year)
    : month(month), date(date), year(year)
{
    // Sanity check month input.
    if (month < 1 || month > 12)
    {
        throw invalid_argument("Invalid month argument");
    }

    // Sanity check date lower bound.
    if (date < 1)
    {
        string msg = "Date must be greater than 0.";
        throw invalid_argument(msg);
    }

    // Handle the leap year mess and the alternating month ending.
    if (month == 2)
    {
        if (year % 4 == 0)
        {
            if (year % 100 == 0)
            {
                if (year % 400 == 0)
                {
                    if (date > 29)
                    {
                        string msg = "Feb only has 29 days every leap year.";
                        throw invalid_argument(msg);
                    }
                }
                else if (date > 28)
                {
                    string msg = "Feb only has 28 days every 100th year.";
                    throw invalid_argument(msg);
                }
            }
            else if (date > 29)
            {
                string msg = "Feb only has 29 days every leap year.";
                throw invalid_argument(msg);
            }
        }
        else if (date > 28)
        {
            string msg = "Feb only has 28 days every non-leap year.";
            throw invalid_argument(msg);
        }
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 ||
             month == 8 || month == 10 || month == 12)
    {
        if (date > 31)
        {
            string msg = "Given month only has 31 days.";
            throw invalid_argument(msg);
        }
    }
    else if (date > 30)
    {
        string msg = "Given month only has 30 days.";
        throw invalid_argument(msg);
    }
}

/**
* Get the month value.
* @return The month value returned as an int.
*/
int
Date::get_month() const
{
    return month;
}

/**
* Get the date of the month value.
* @return The date value returned as an int.
*/
int
Date::get_date() const
{
    return date;
}

/**
* Get the year value.
* @return The year value returned as an int.
*/
int
Date::get_year() const
{
    return year;
}

/**
* Get the date as a string value.
* @return The date as a string value.
*/
string
Date::to_string() const
{
    stringstream ss;
    ss << get_month() << "/" << get_date() << "/" << get_year();
    return ss.str();
}

/**
* Stream operator overloader for Date.
*
* @param stream - The stream object Date is being pushed into.
* @param d - The date object being streamed.
* @return Returns the reference to the stream passed in.
*
* @note This method doesn't need to be friended because it uses
*       the public to_string() method.
*/
std::ostream&
operator<<(std::ostream& stream, const Date& d)
{
    stream << d.to_string();
    return stream;
}