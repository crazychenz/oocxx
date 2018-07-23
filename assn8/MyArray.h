#include <stdexcept>
#include <vector>
#include <string>
#include <type_traits>
#include <cstdlib>
#include <cstdint>

template <typename ArrayType>
class MyArray
{
    static_assert(
        std::is_same<std::size_t, std::vector<int>::size_type>::value,
        "MyArray requires that vector<int>::size_type be same as size_t.");

public:
    MyArray(std::initializer_list<ArrayType> list);

    MyArray(size_t size);

    ArrayType &
    operator[](size_t index);

    size_t
    size() const;

    void
    console_dump(std::string desc) const;

private:
    size_t sz = 0;
    std::vector<ArrayType> data;
};


