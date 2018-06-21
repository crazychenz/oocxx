#include <iostream>
#include <climits>
#include <cstdlib>
#include <cassert>

using namespace std;

// Swap x and y if (y < x) (by address)
void swap_p(ssize_t *x, ssize_t *y)
{

    // Sanity check pointers before dereferencing.
    assert(x != NULL);
    assert(y != NULL);

    if (*y < *x) {
        // Perform XOR swap to spice things up a bit
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}

// Swap x and y if (y < x) (by reference)
void swap_r(ssize_t &x, ssize_t &y)
{
    if (y < x) {
        // Perform XOR swap to spice things up a bit
        x ^= y;
        y ^= x;
        x ^= y;
    }
}

int main()
{

    // Simple struct to store limit table entries.
    struct entry {
        string label;
        size_t max;
        ssize_t min;
        size_t len;
    };

    // Initialization of the limit table.
    struct entry entries[] = { 
        {"Character", CHAR_MAX, CHAR_MIN, sizeof(char)},
        {"Unsigned Character", UCHAR_MAX, 0, sizeof(unsigned char)},
        {"Short", SHRT_MAX, SHRT_MIN, sizeof(short)},
        {"Unsigned Short", USHRT_MAX, 0, sizeof(unsigned short)},
        {"Integer", INT_MAX, INT_MIN, sizeof(int)}, 
        {"Unsigned Integer", UINT_MAX, 0, sizeof(unsigned int)},
        {"Long", LONG_MAX, LONG_MIN, sizeof(long)},
        {"Unsigned Long", ULONG_MAX, 0, sizeof(unsigned long)},
        {"Long Long", LLONG_MAX, LLONG_MIN, sizeof(long long)},
        {"Unsigned Long Long", ULLONG_MAX, 0, sizeof(unsigned long long)}
    };

    // Dump of the limit table entries to console.
    for (int i = 0; i < (sizeof(entries)/sizeof(entries[0])); ++i)
    {
        struct entry entry = entries[i];
        cout << entry.label << " Max: " << entry.max << endl;
        cout << entry.label << " Min: " << entry.min << endl;
        cout << entry.label << " Len: " << entry.len << endl << endl;
    }

    // Test: Swap by address.
    ssize_t x = 12;
    ssize_t y = 6;
    cout << "Test: Swap by address." << endl;
    cout << "X (before): " << x << endl;
    cout << "Y (before): " << y << endl;
    swap_p(&x, &y);
    cout << "X (after): " << x << endl;
    cout << "Y (after): " << y << endl << endl;

    // Test: No swap by address.
    x = 100;
    y = 300;
    cout << "Test: No swap by address." << endl;
    cout << "X (before): " << x << endl;
    cout << "Y (before): " << y << endl;
    swap_p(&x, &y);
    cout << "X (after): " << x << endl;
    cout << "Y (after): " << y << endl << endl;

    // Test: Swap by reference.
    ssize_t a = 15;
    ssize_t b = 3;
    cout << "Test: Swap by reference." << endl;
    cout << "A (before): " << a << endl;
    cout << "B (before): " << b << endl;
    swap_r(a, b);
    cout << "A (after): " << a << endl;
    cout << "B (after): " << b << endl << endl;

    // Test: No swap by reference.
    a = 50;
    b = 400;
    cout << "Test: No swap by reference." << endl;
    cout << "A (before): " << a << endl;
    cout << "B (before): " << b << endl;
    swap_r(a, b);
    cout << "A (after): " << a << endl;
    cout << "B (after): " << b << endl << endl;

    return 0;
}
