#include "dynamic_array.h"

DynamicArray::DynamicArray(int size) {
    this->size = size;
    array = new DynamicArray::item_type[size];
    square();
}

DynamicArray::~DynamicArray() {
    delete[] array;
}

void DynamicArray::Display() const {
    std::cout << "Array elements:";
    for (int idx = 0; idx < this->size; idx++) {
        std::cout << " " << array[idx];
    }
    std::cout << "\n";
}

void DynamicArray::square() {
    for (int idx = 0; idx < this->size; idx++) {
        array[idx] = idx * idx;
    }
}