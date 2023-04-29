#include "realvector.h"
#include <stdexcept>

template<typename T>
RealVector<T>::RealVector() : 
    m_logical_size(0), m_array_size(kInitialSize)
{
    m_elems = new value_type[kInitialSize];
}

template<typename T>
RealVector<T>::RealVector(size_type size, const_reference value) :
    m_logical_size(size), m_array_size(size * 2)
{
    m_elems = new value_type[size];
    std::fill(begin(), end(), value);
}

template<typename T>
RealVector<T>::~RealVector() {
    delete[] m_elems;
}

template<typename T>
typename RealVector<T>::reference RealVector<T>::operator[](size_type pos) {
    return *(begin() + pos);
}

template<typename T>
typename RealVector<T>::const_reference RealVector<T>::operator[](size_type pos) const {
    return static_cast<const_reference>(
        const_cast<RealVector<T>*>(this)->operator[](pos));
}

template<typename T>
typename RealVector<T>::reference RealVector<T>::at(size_type pos) {
    if (pos >= size()) {
        throw std::out_of_range("Index out of range");
    }
    return operator[](pos);
}

template<typename T>
typename RealVector<T>::const_reference RealVector<T>::at(size_type pos) const {
    return static_cast<const_reference>(const_cast<RealVector<T>*>(this)->at(pos));
}

template<typename T>
typename RealVector<T>::reference RealVector<T>::front() {
    return *m_elems;
}

template<typename T>
typename RealVector<T>::const_reference RealVector<T>::front() const {
    return static_cast<const_reference>(const_cast<RealVector<T>*>(this)->front());
}

template<typename T>
typename RealVector<T>::reference RealVector<T>::back() {
    return *(end() - 1);
}

template<typename T>
typename RealVector<T>::const_reference RealVector<T>::back() const {
    return static_cast<const_reference>(const_cast<RealVector<T>*>(this)->back());
}

/* Iterators */
template<typename T>
typename RealVector<T>::iterator RealVector<T>::begin() noexcept {
    return m_elems;
}

template<typename T>
typename RealVector<T>::const_iterator RealVector<T>::begin() const noexcept {
    return static_cast<const_iterator>(const_cast<RealVector<T>*>(this)->begin());
}

template<typename T>
typename RealVector<T>::iterator RealVector<T>::end() noexcept {
    return m_elems + size();
}

template<typename T>
typename RealVector<T>::const_iterator RealVector<T>::end() const noexcept {
    return static_cast<const_iterator>(const_cast<RealVector<T>*>(this)->end());
}

/* Capacity */
template<typename T>
bool RealVector<T>::empty() const noexcept {
    return begin() == end();
}

template<typename T>
typename RealVector<T>::size_type RealVector<T>::size() const noexcept {
    return m_logical_size;
}

template<typename T>
typename RealVector<T>::size_type RealVector<T>::capacity() const noexcept {
    return m_array_size;
}

/* Modifier */
template<typename T>
void RealVector<T>::clear() noexcept {
    this->erase(begin(), end());
}

template<typename T>
typename RealVector<T>::iterator RealVector<T>::insert(const_iterator pos, const_reference value) {
    /* We need to calculate the diff before we grow the vector capacity.
       Otherwise, the addresses will be inconsistent. */
    size_type diff = pos - begin();

    while (size() >= m_array_size) {
        grow();
    }

    iterator insert_pos = begin() + diff;
    if (insert_pos < begin() || insert_pos > end()) {
        std::logic_error e("Invalid input.");
        throw std::exception(e);
    }

    std::copy(insert_pos, end(), insert_pos + 1);
    *insert_pos = value;
    m_logical_size++;

    return insert_pos;
}

template<typename T>
typename RealVector<T>::iterator RealVector<T>::insert(const_iterator pos, value_type&& value) {
    /* We need to calculate the diff before we grow the vector capacity.
       Otherwise, the addresses will be inconsistent. */
    size_type diff = pos - begin();

    while (size() >= m_array_size) {
        grow();
    }

    iterator insert_pos = begin() + diff;
    if (insert_pos < begin() || insert_pos > end()) {
        std::logic_error e("Invalid input.");
        throw std::exception(e);
    }

    std::copy(insert_pos, end(), insert_pos + 1);
    *insert_pos = std::forward<value_type>(value);
    m_logical_size++;

    return insert_pos;
}

template<typename T>
typename RealVector<T>::iterator RealVector<T>::insert(
    const_iterator pos, size_type count, const_reference value)
{
    /* We need to calculate the diff before we grow the vector capacity.
       Otherwise, the addresses will be inconsistent. */
    size_type diff = pos - begin();

    while (size() + count >= m_array_size) {
        grow();
    }

    iterator insert_start = begin() + diff;
    if (count == 0) {
        return insert_start;
    }

    if (insert_start < begin() || insert_start > end()) {
        std::logic_error e("Invalid input.");
        throw std::exception(e);
    }

    std::copy(insert_start, end(), insert_start + count);
    m_logical_size += count;
    while (count--) {
        *(insert_start + count) = value;
    }
    
    return insert_start;
}

template<typename T>
void RealVector<T>::push_back(const_reference value) {
    if (size() == m_array_size) {
        grow();
    }
    *end() = value;
    m_logical_size++;
}

template<typename T>
void RealVector<T>::push_back(value_type&& value) {
    if (size() == m_array_size) {
        grow();
    }
    *end() = std::forward<value_type>(value);
    m_logical_size++;
}

template<typename T>
void RealVector<T>::pop_back() {
    if (size() == 0) {
        return;
    }
    std::destroy_at(end());
    m_logical_size--;
}

template<typename T>
typename RealVector<T>::iterator RealVector<T>::erase(const_iterator pos) {
    size_type diff = pos - begin();
    iterator erase_start = begin() + diff;

    if (pos == end()) {
        return end();
    } else if (pos + 1 != end()) {
        std::copy(erase_start + 1, end(), erase_start);
    }
    std::destroy_at(end());
    m_logical_size--;

    return erase_start;
}

template<typename T>
typename RealVector<T>::iterator RealVector<T>::erase(const_iterator first, const_iterator last) {
    if (first < begin() || last > end()) {
        std::logic_error e("Invalid input.");
        throw std::exception(e);
    }
    
    /* empty range */
    if (first == last) {
        return const_cast<iterator>(last);
    }

    size_type diff = first - begin();
    size_type len = last - first;
    iterator erase_start = begin() + diff;
    iterator erase_end = erase_start + len;
    if (erase_end == end()) {
        ; // last == end(), then the updated end() iterator is returned
    } else if (erase_end + 1 != end()) {
        std::copy(erase_end + 1, end(), erase_start);
    }
    std::destroy(end() - len, end());
    m_logical_size -= len;

    return erase_end;
}

template<typename T>
void RealVector<T>::grow(){
    value_type *newElems = new value_type[m_array_size * 2];
    std::copy(begin(), end(), newElems);
    delete [] m_elems;
    m_array_size *= 2;
    m_elems = newElems;
}