#include <cstdlib>
#include <iostream>
#include <string>

#include "MyArray.h"
#include "Date.h"

using namespace std;

/** Fetch the size of the array. 
@return The size of the array.
*/
template <typename ArrayType>
size_t
MyArray<ArrayType>::size() const
{
    return sz;
}

/** Dump the state of the object to console. */
template <typename ArrayType>
void
MyArray<ArrayType>::console_dump(std::string desc) const
{
    std::cout << desc << " Size: " << size() << std::endl;
    for (size_t i = 0; i < size(); ++i)
    {
        std::cout << "\tElem #" << i << ": " << data[i] << std::endl;
    }
}

/** Allow an initializer list to be used for for this array class. */
template <typename ArrayType>
MyArray<ArrayType>::MyArray(std::initializer_list<ArrayType> list)
    : sz(list.size()), data(list)
{

}

/** Construct array with explicit size. 
@param size - The size of the array.
*/
template <typename ArrayType>
MyArray<ArrayType>::MyArray(size_t size) : sz(size)
{
    for (size_t i = 0; i < size; ++i)
    {
        data.push_back(ArrayType());
    }
}

/** Overload the index operator to allow standard array indexing. 
@param index - The index of the array to return reference for.
*/
template <typename ArrayType>
ArrayType &
MyArray<ArrayType>::operator[](size_t index)
{
    if (index >= size())
    {
        throw std::out_of_range("Attempted index out of range.");
    }

    return data[index];
}

// Create the MyArray class definitions for the following types.
template class MyArray<int>;
template class MyArray<float>;
template class MyArray<string>;
template class MyArray<Date>;