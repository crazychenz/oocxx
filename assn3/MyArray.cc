#include <iostream>
#include <cstdlib>

#include "MyArray.h"

using namespace std;

/**
* Destructor.
*/
MyArray::~MyArray()
{
	delete data;
	data = nullptr;
}

/**
* Copy Constructor.
* @param obj Object to copy.
*/
MyArray::MyArray(const MyArray &obj)
{
	if (obj.size == 0)
	{
		// Nothing to copy.
		return;
	}

	size = obj.size;
	data = new int[size];

	// Copy the data
	for (int i = 0; i < size; ++i)
	{
		data[i] = obj.data[i];
	}
}

/**
* Explicit Constructor.
* @param sz Size of integer array to allocate.
*/
MyArray::MyArray(const int sz)
{
	size = sz;
	data = new int[size];
}

/**
* Default Constructor.
*/
MyArray::MyArray()
{
	// Initializing values in Class with C++11 fancy-ness.
}

/**
* Function to create random sample data to avoid seeing all zeros.
*/
void MyArray::createSample()
{
	for (int i = 0; i < size; ++i)
	{
		data[i] = rand() % 80 + 10;
	}
}

/**
* Function to visualize that the new object is a copy and not a pointer.
*/
void MyArray::dumpArray() const
{
	cout << "data Pointer: " << data << endl;
	cout << "size: " << size << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}
