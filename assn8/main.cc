/**

@mainpage Assignment #8: Templates

 Description
=============
Earlier in the semester we demonstrated the development of an integer array class. Develop
a template class for an array in which various types of arrays could be handled. Write a
program that creates and displays arrays of integers, floats, strings, and Date objects (where
Date objects model a date using integer month, day, year attributes).
Submit source code and a screen capture of your executing program.

 Breakdown
===========

There are 2 template classes and 1 real class in this implementation. 
The 1 real class is the Date class as described above (For use in the 
array class). 

The Date class will default to 1/1/1, but can be constructed with any
valid date. A to_string() method is provided and called when the Date
object is used with a stream operator. Note: Negative years are considered
valid.

One of the template classes is the MyArray class. This class mainly
uses a vector in encapsulation to make initializer_list easier to
implement and to prevent re-doing any of the stuff that the STL already
provides for us.

There is a second template class called the MyArrayTester which is for 
testing the MyArray class. MyArrayTester uses specialization to make a 
single MyArrayTester call more scalable.

*/

#include <cstdio>
#include <iostream>

#include "MyArrayTester.h"
#include "Date.h"

using namespace std;

int main()
{
    MyArrayTester<int>::run_tests();

    MyArrayTester<float>::run_tests();

    MyArrayTester<string>::run_tests();
    
    MyArrayTester<Date>::run_tests();

    cout << "Press any key to exit." << endl;
    getchar();
    return 0;
}