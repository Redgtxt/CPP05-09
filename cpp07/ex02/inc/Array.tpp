#include "Array.hpp"

//Constructor no args
template <typename T>
Array<T>::Array() : _size(0)
{
    if(_size == 0)
        _arr = NULL;
}

//Constructor with args
template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    if(_size == 0)
        _arr = NULL;
    else
        _arr =  new T[_size]();//Inicializa tudo a 0
}

template <typename T>
Array<T>::Array(const Array<T> &obj)
{
    _arr = NULL;
    *this = obj;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T>& other)
{
    if(this !=  &other)
    {
        delete[] _arr;
        _arr = new T[other._size];

        _size = other._size;
        for (size_t i = 0; i < other._size; i++)
        {
            _arr[i] = other._arr[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if(index >= this->_size)
    {
        throw(std::out_of_range("Index is out of bounds"));
    }
    return this->_arr[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if(index >= this->_size)
    {
        throw(std::out_of_range("Index is out of bounds"));
    }
    return this->_arr[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return(_size);
}

template <typename T>
Array<T>::~Array()
{
   delete[] _arr;
}
