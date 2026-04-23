#include "Span.hpp"

int main()
{
    try
    {
        srand(time(0));
        Span span(10);

        for (size_t i = 0; i < 10; i++)
        {
            span.addNumber(rand());
        }
        
        span.printVec();

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n" << std::endl;


    try
    {
        srand(time(0));
        Span span(6);
        std::vector <int> test;
        span.printVec();

        for (size_t i = 0; i < 6; i++)
        {
            test.push_back(rand());
        }

        span.addRange(test.begin(),test.end());
        
        
        std::cout << "I'm a banana " << std::endl;
        span.printVec();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}