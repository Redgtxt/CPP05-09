#include <iostream>
#include "Array.hpp"

#define MAX_VAL 7

int main()
{
    // Test Construction and Size
    Array<int> numbers(MAX_VAL);
    Array<int> empty;

    std::cout << "Empty array size: " << empty.size() << std::endl;
    std::cout << "Numbers array size: " << numbers.size() << std::endl;

    // Test Assignment and Indexing
    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;

    std::cout << "Numbers content: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << "\n" << std::endl;

    // Test Deep Copy (Copy Constructor & Assignment)
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        tmp[0] = 999; // Change copy
        std::cout << "Original [0]: " << numbers[0] << " (Should be 0)" << std::endl;
        std::cout << "Copy [0]:     " << tmp[0] << " (Should be 999)" << std::endl;
    }

    // Test Bounds Checking (Exceptions)
    std::cout << "\nTesting Out of Bounds:" << std::endl;
    try {
        std::cout << numbers[-1] << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "Caught: " << e.what() << " (Negative index)" << std::endl;
    }

    try {
        std::cout << numbers[MAX_VAL] << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "Caught: " << e.what() << " (Index >= size)" << std::endl;
    }

    return 0;
}