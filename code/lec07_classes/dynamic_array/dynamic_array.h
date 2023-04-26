#include <iostream>
#include <string>

class DynamicArray {
public:
    using item_type = int32_t;

    explicit DynamicArray(int size);
    ~DynamicArray();

    void Display() const;

private:
    void square();
    item_type* array;
    int size;
};