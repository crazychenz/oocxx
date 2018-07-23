#include <stdexcept>
#include <vector>
#include <string>
#include <type_traits>
#include <cstdlib>
#include <cstdint>

/**
  @class MyArray
  @brief A simple (templated) array class.
*/
template <typename ArrayType>
class MyArray
{
    // Sanity check that the vector::size_type is compatible with the
    // size_t that is used in this class as the index type.
    static_assert(
        std::is_same<std::size_t, std::vector<int>::size_type>::value,
        "MyArray requires that vector<int>::size_type be same as size_t.");

public:
    MyArray(std::initializer_list<ArrayType> list);

    MyArray(std::size_t size);

    ArrayType &
    operator[](std::size_t index);

    std::size_t
    size() const;

    void
    console_dump(std::string desc) const;

private:
    /** Default size to 0. */
    std::size_t sz = 0;

    /** The main structure that backs this array class. */
    std::vector<ArrayType> data;
};


