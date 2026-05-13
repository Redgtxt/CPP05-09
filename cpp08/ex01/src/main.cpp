#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


int main() {
    std::srand(std::time(NULL));

    // -------------------------------------------------------------------------
    //  SUBJECT EXAMPLE TEST
    // -------------------------------------------------------------------------

    std::cout << "--- 1. Subject Example Test ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << " (Expected: 14)" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // -------------------------------------------------------------------------
    // EXCEPTION TESTING
    // -------------------------------------------------------------------------

    std::cout << "--- 2. Exception Testing ---" << std::endl;
    try {
        std::cout << "[Attempting to find span on empty Span]" << std::endl;
        Span emptySpan(5);
        emptySpan.shortestSpan();
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "[Attempting to add elements beyond capacity]" << std::endl;
        Span tinySpan(2);
        tinySpan.addNumber(1);
        tinySpan.addNumber(2);
        tinySpan.addNumber(3); // Should throw here
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // -------------------------------------------------------------------------
    // RANGE ITERATOR FILL & 10,000+ ELEMENTS TEST
    // -------------------------------------------------------------------------

    std::cout << "--- 3. Large Range Test (15,000 elements) ---" << std::endl;
    try {
        Span largeSpan(15000);
        std::vector<int> randomNumbers;

        // Generating 15,000 random integers
        for (int i = 0; i < 15000; ++i)
        {
            randomNumbers.push_back(std::rand());
        }

        //Inserting the numbers
        largeSpan.addRange(randomNumbers.begin(), randomNumbers.end());
        std::cout << "Successfully added 15,000 elements using iterator range." << std::endl;

        std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << largeSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}