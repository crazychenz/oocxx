#include <stdexcept>
#include <iostream>
#include <string>

#include "MyArray.h"
#include "MyArrayTester.h"
#include "Date.h"

using namespace std;

void
MyArrayTester<int>::run_tests()
{
    // Blank Array
    MyArray<int> intArray(3);
    intArray.console_dump("Blank Integer (int) Array");

    // Performing some assignment on the given values
    intArray[0] = 1134;
    intArray[1] = 1729;
    intArray[2] = -9;
    intArray.console_dump("Runtime Assigned Integer (int) Array");

    // Attempting to index out of range.
    try {
        intArray[3] = 0;
    }
    catch (out_of_range &oor)
    {
        cout << oor.what() << endl;
    }

    // Creating an array initialization list
    MyArray<int> intArray2 = { -2, -1, 0, 1, 2 };
    intArray2.console_dump("Initialized Integer (int) Array");
}

void
MyArrayTester<float>::run_tests()
{
    // Blank Array
    MyArray<float> floatArray(3);
    floatArray.console_dump("Blank Float Array");

    // Performing some assignment on the given values
    floatArray[0] = 3.14f;
    floatArray[1] = 0.1f;
    floatArray[2] = 0.0f;
    floatArray.console_dump("Runtime Assigned Float Array");

    // Attempting to index out of range.
    try {
        floatArray[3] = 0;
    }
    catch (out_of_range &oor)
    {
        cout << oor.what() << endl;
    }

    // Creating an array initialization list
    MyArray<float> floatArray2 = { -2.0f, -1.0f, 0.0f, 1.0f, 2.0f };
    floatArray2.console_dump("Initialized Float Array");
}

void
MyArrayTester<string>::run_tests()
{
    // Quotes from http://pun.me/pages/funny-quotes.php (July 2018)

    // Blank Array
    MyArray<string> strArray(3);
    strArray.console_dump("Blank String Array");

    // Performing some assignment on the given values
    strArray[0] = "If two wrongs don't make a right, try three.";
    strArray[1] = "I am not lazy, I am on energy saving mode.";
    strArray[2] = "Life is short, smile while you still have teeth.";
    strArray.console_dump("Runtime Assigned String Array");

    // Attempting to index out of range.
    try {
        strArray[3] = "";
    }
    catch (out_of_range &oor)
    {
        cout << oor.what() << endl;
    }

    // Creating an array initialization list
    MyArray<string> strArray2 = { 
        "A balanced diet means a cupcake in each hand.",
        "I'm sorry, if you were right, I'd agree with you.",
        "Sorry for the mean, awful, accurate things I said.",
        "Your life can't fall apart if you never had it together!"
    };
    strArray2.console_dump("Initialized String Array");
}

void
MyArrayTester<Date>::run_tests()
{
    // Blank Array
    MyArray<Date> dateArray(3);
    dateArray.console_dump("Blank Date Array");

    // Performing some assignment on the given values
    dateArray[0] = Date(7, 20, 1984);
    dateArray[1] = Date(7, 24, 2018);
    dateArray[2] = Date(12, 25, 2019);
    dateArray.console_dump("Runtime Assigned Float Array");

    // Attempting to index out of range.
    try {
        dateArray[3] = Date();
    }
    catch (out_of_range &oor)
    {
        cout << oor.what() << endl;
    }

    // Creating an array initialization list
    MyArray<Date> dateArray2 = { 
        Date(1, 1, 1601),
        Date(12, 31, 1840),
        Date(12, 31, 1899),
        Date(1, 1, 1970),
        Date(1, 1, 2000),
    };
    dateArray2.console_dump("Initialized Float Array");
}