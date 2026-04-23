#include "Span.hpp"
#include <vector>

Span::Span() : _n(0)
{
}

Span::Span(unsigned int size) : _n(size)
{
}

Span::Span(const Span &obj)
{
    std::cout << "Span Copy constructor called" << std::endl;
    *this = obj;
}

Span& Span::operator=(const Span& other)
{
    std::cout << "Copy assignment Span operator called" << std::endl;

    if(this != &other)
    {
        _n = other.getN();
    }
    return *this;
}


/*
This class will have a member function called addNumber() to add a single number
to the Span.
It will be used in order to fill it. Any attempt to add a new element if there
are already N elements stored should throw an exception.

Last but not least, it would be wonderful to fill your Span using a range of iterators.
Making thousands of calls to addNumber() is so annoying. Implement a member function
to add multiple numbers to your Span in a single call.
*/

const char* Span::OffLimits::what() const throw()
{
    return "Error should be already full";
}

void Span::addNumber(unsigned int num)
{
    std::vector<int> span;
    if(span.size() > this->_n)
        throw(OffLimits());

    
    span.push_back(num);
    for(size_t i = 0;i < span.size();i++)
        std::cout <<span[i] << " ";
    
}

unsigned int Span::getN() const
{
    return this->_n;
}

Span::~Span()
{
}