
/**
* @class MyArray
* @brief MyArray class.
*/
class MyArray
{
private:

	/** Pointer that stores allocated integer array. */
	int *data = nullptr;

	/** Number of elements in integer array. */
	int size = 0;

public:

	/**
	* Destructor.
	*/
	~MyArray();

	/**
	* Copy Constructor.
	* @param obj Object to copy.
	*/
	MyArray(const MyArray &obj);

	/**
	* Explicit Constructor.
	* @param sz Size of integer array to allocate.
	*/
	MyArray(int sz);

	/**
	* Default Constructor.
	*/
	MyArray();

	/**
	* Function to create random sample data to avoid seeing all zeros.
	*/
	void createSample();

	/**
	* Function to visualize that the new object is a copy and not a pointer.
	*/
	void dumpArray() const;
};