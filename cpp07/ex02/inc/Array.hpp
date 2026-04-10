#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>


template <typename T>
class Array
{
private:
    T *_arr;
    unsigned int _size;
public:
    Array();
    Array(unsigned int n);
    Array(const Array<T> &obj);
    Array<T>&operator=(const Array<T>&);
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
    unsigned int size() const;


    ~Array();
};
#include "Array.tpp"


#endif
