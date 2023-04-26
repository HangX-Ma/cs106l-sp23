#include "strvector_soln.h"

// Constructor #1
StrVector::StrVector() :
    logicalSize(0), allocatedSize(kInitialSize)
{
    elems = new std::string[allocatedSize];
}

// Constructor #2 
StrVector::StrVector(size_type n, const std::string &val) :
    logicalSize(n), allocatedSize(2*n)
{
    elems = new std::string[allocatedSize];
    std::fill(begin(), end(), val);
}

// Destructor
StrVector::~StrVector() {
    delete[] elems;
}

// Get an iterator to the start of our vector
StrVector::iterator StrVector::begin() {
    return elems;
}

// Get an iterator for the end of our vector
StrVector::iterator StrVector::end() {
    return elems + size();
}

// How many elements in our vector?
StrVector::size_type StrVector::size() const {
    return logicalSize;
}

// Is our vector empty?
bool StrVector::empty() const {
    return size() == 0;
}

// I want to get the element at index 5. Ex. v[5]
std::string& StrVector::operator[](size_type index) {
    return *(begin() + index);
}

// I want to get the element at index 5 but with bounds checking
std::string& StrVector::at(size_type index) {
    if(index >= size()) {
        throw std::out_of_range("Out of bounds access of vector");
    }
    return *(begin() + index);
}

// Private method: Used to resize our vector when we run out of space
void StrVector::grow() {
    iterator new_elems = new std::string[2*allocatedSize];
    std::copy(begin(), end(), new_elems);
    delete[] elems;
    allocatedSize *= 2;
    elems = new_elems;
}

// I want to insert an element at a specific location
StrVector::iterator StrVector::insert(iterator pos, const std::string &elem) {
    size_type indx = pos - begin();
    if(size() == allocatedSize) {
        grow();
    }
    /*
      * If we grew, we need pos to point to the new array
      * since the previous address of pos would be invalid
      */
    pos = begin() + indx;
    std::copy_backward(pos, end(), end() + 1);
    *pos = elem;
    ++logicalSize;
    return pos;
}

// I want to add a new element at the end of my vector 
void StrVector::push_back(const std::string &elem) {
    insert(end(), elem);
}
