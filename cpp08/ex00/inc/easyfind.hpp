#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <stdexcept>
#include <iostream>

/*
    A first easy exercise is the way to start off on the right foot.
    Write a function template easyfind that accepts a type T. It takes two parameters:
    the first one is of type T, and the second one is an integer.
    Assuming T is a container of integers, this function has to find the first occurrence
    of the second parameter in the first parameter.
    If no occurrence is found, you can either throw an exception or return an error value
    of your choice. If you need some inspiration, analyze how standard containers behave.
*/



template <typename T>
typename T::iterator easyfind(T &container, int num)
{
    typename T::iterator firstOccurence = std::find(container.begin(), container.end(), num);
    if (firstOccurence == container.end())
    {
        throw std::runtime_error("value not found");
    }
    return firstOccurence;
}

#endif