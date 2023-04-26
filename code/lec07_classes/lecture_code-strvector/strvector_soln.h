#ifndef STRVECTOR_H
#define STRVECTOR_H

#include <string>
#include <algorithm>


class StrVector {
public:
    // Creating alias
    using iterator = std::string*;
    using size_type = size_t;

    // Default size of our array
    const size_type kInitialSize = 2;

    // Constructors and Destructor
    StrVector();
    StrVector(size_type n, const std::string& val);
    ~StrVector();

    // Simple Methods to reveal state of vector
    size_type size() const;
    bool empty() const;

    // Accessing data at a specific position
    std::string& operator[](size_type indx);
    const std::string& operator[](size_type indx) const;
    std::string& at(size_type indx);

    // Adding data at a specific position
    iterator insert(iterator pos, const std::string& elem);
    void push_back(const std::string& elem);

    // ITERATORS :)
    iterator begin();
    iterator end();

private:
    // Used to grow our vector when we run out of space
    void grow();

    // Variables to track the state of our vector
    std::string* elems;
    size_type logicalSize;
    size_type allocatedSize;
};
#endif // STRVECTOR_H


