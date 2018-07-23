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