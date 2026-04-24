#include "Span.hpp"

int main()
{
    //Will print Error because size is bigger than the vecSIZE
    try
    {
        size_t size = 100;
        srand(time(0));
        Span span(size);

        for (size_t i = 0; i < size + 20; i++)
        {
            span.addNumber(rand());
        }
        
        span.printVec();

        std::cout << "Shortest Span is: " << span.shortestSpan() << std::endl;
        std::cout << "Longest Span is: " << span.logestSpan() << std::endl;
    

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    //Test with small nums
    try
    {
        size_t size = 10;
        srand(time(0));
        Span span(size);

        for (size_t i = 0; i < size; i++)
        {
            span.addNumber(rand());
        }
        
        span.printVec();

        std::cout << "Shortest Span is: " << span.shortestSpan() << std::endl;
        std::cout << "Longest Span is: " << span.logestSpan() << std::endl;
    

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n" << std::endl;


    //Test with big Nums
    try
    {
        size_t size = 6;
        srand(time(0));
        Span span(size);
        std::vector <int> test;
        span.printVec();

        for (size_t i = 0; i < size; i++)
        {
            test.push_back(rand());
        }

        span.addRange(test.begin(),test.end());
        
        span.printVec();

        std::cout << "Shortest Span is: " << span.shortestSpan() << std::endl;
        std::cout << "Longest Span is: " << span.logestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}