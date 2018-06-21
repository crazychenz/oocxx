#include <iostream>

#include "MyArray.h" 

using namespace std;

int main()
{
	try
	{
		// Declare and initialize a MyArray object with 4 integers.
		MyArray existingObj = MyArray(4);
		// Setup object with random data (which is better than undefined data).
		existingObj.createSample();
		// Dump the state of the object to console.
		existingObj.dumpArray();

		// Declare and initialize a MyArray objects as a copy.
		MyArray newObj = existingObj;
		// Dump the state of the object to console.
		newObj.dumpArray();
	}
	catch (std::bad_alloc& ba)
	{
		// Let the user know why initialization/execution failed. 
		cerr << "Not enough memory. Terminating execution. (" << ba.what() << ")" << endl;
	}

	return 0;
}