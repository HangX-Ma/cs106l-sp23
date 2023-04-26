#include "dynamic_array.h"

int main(int argc, char* argv[]) {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    if (size < 0) {
        throw std::invalid_argument("The array size needs to be positive.");
    }

    DynamicArray dynArray(size);
    dynArray.Display();

    return 0;
}