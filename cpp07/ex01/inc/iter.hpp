#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

/*
first parameter: address of an array
second parameter: len of a array must be const
third parameter: function that will be called in every element of the array
*/
template <typename T,typename T_function>
void iter(T &arr,const size_t len, T_function func)
{
    for (size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
}

#endif