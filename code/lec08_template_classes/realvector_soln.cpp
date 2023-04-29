#include "realvector_soln.h"
#include <stdexcept>

//constructors
template<class valueType>
RealVector<valueType>::RealVector() : logical_size(0), array_size(kInitialSize) {
    elems = new valueType[kInitialSize];
}

template<class valueType>
RealVector<valueType>::RealVector(size_t n, const valueType& val) : logical_size(n), array_size(n * 2){
    elems = new valueType[array_size];
    std::fill(begin(), end(), val);
}


//destructor
template<class valueType>
RealVector<valueType>::~RealVector() {
    delete [] elems;
}

template<class valueType>
size_t RealVector<valueType>::size() const{
    return logical_size;
}

template<class valueType>
bool RealVector<valueType>::empty() const{
    return size() == 0;
}

template<class valueType>
typename RealVector<valueType>::iterator RealVector<valueType>::begin() {
    return elems;
}

template<class valueType>
typename RealVector<valueType>::const_iterator RealVector<valueType>::begin() const{
    return static_cast<const_iterator>(const_cast<RealVector<valueType>*>(this)->begin());
}


template<class valueType>
typename RealVector<valueType>::iterator RealVector<valueType>::end() {
    return begin() + size();
} 

template<class valueType>
typename RealVector<valueType>::const_iterator RealVector<valueType>::end() const {
    return static_cast<const_iterator>(const_cast<RealVector<valueType>*>(this)->end());
} 

template<class valueType>
valueType& RealVector<valueType>::operator[](size_t index) {
    return *(begin() + index);
}

template<class valueType>
valueType& RealVector<valueType>::at(size_t index) {
    if (index >= logical_size) {
        throw std::out_of_range("Out of range.");
    }

    return operator[](index); 
}

template<class valueType>
void RealVector<valueType>::grow(){
    valueType *newElems = new valueType[array_size*2];
    std::copy(begin(), end(), newElems);
    delete [] elems;
    array_size*=2;
    elems = newElems;
}

template<class valueType>
void RealVector<valueType>::push_back(const valueType &elem) {
    if (array_size == size()) {
        grow();
    }
    *end() = elem;
    logical_size++;
}
