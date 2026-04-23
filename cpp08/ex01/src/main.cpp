#include "Span.hpp"

int main()
{
    try
    {
        Span span(2);

        span.addNumber(2);
        span.addNumber(3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}