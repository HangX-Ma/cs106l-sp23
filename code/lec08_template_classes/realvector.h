#ifndef RealVector_H
#define RealVector_H

#include <string>
#include <algorithm>
#include <stdexcept>

template<typename T>
class RealVector {
public:
    using value_type        = T;
    using size_type         = size_t;
    using reference         = value_type&;
    using const_reference   = const value_type&;
    using iterator          = value_type*;
    using const_iterator    = const value_type*;

    const size_type kInitialSize = 2; 

    RealVector();
    RealVector(size_type size, const_reference value);
    ~RealVector();

    /* Element access */
    reference operator[](size_type pos);
    const_reference operator[](size_type pos) const;

    reference at(size_type pos);
    const_reference at(size_type pos) const;

    reference front();
    const_reference front() const;

    reference back();
    const_reference back() const;

    /* Iterators */
    iterator begin() noexcept;
    const_iterator begin() const noexcept;

    iterator end() noexcept;
    const_iterator end() const noexcept;

    /* Capacity */
    bool empty() const noexcept;
    size_type size() const noexcept;
    size_type capacity() const noexcept;

    /* Modifier */
    void clear() noexcept;

    iterator insert(const_iterator pos, const_reference value);
    iterator insert(const_iterator pos, value_type&& value);
    iterator insert(const_iterator pos, size_type count, const_reference value);

    void push_back(const_reference value);
    void push_back(value_type&& value);

    void pop_back();

    iterator erase(const_iterator pos);
    iterator erase(const_iterator first, const_iterator last);

private:
    void grow();
    //array where we store our elements
    iterator m_elems;
    //number of elements in our vector
    size_t m_logical_size;
    //total capacity of underlying array
    size_t m_array_size;
};

// Important: For template classes, include the .cpp at the bottom of the .h instead of including the .h in the top of the .cpp
#include "realvector.cpp"

#endif // RealVector_H