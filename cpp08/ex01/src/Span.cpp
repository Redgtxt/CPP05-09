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
Making thousands of calls to addNumber() is so annoying.
Implement a member function to add multiple numbers to your Span in a single call.
*/

const char* Span::OffLimits::what() const throw()
{
    return "Error should be already full";
}

const char* Span::ToSmall::what() const throw()
{
    return "Not enough numbers";
}

void Span::printVec()
{
    for(size_t i = 0;i < this->_span.size();i++)
        std::cout << this->_span[i] << " ";

}

long Span::logestSpan()
{
    if(2 > this->_span.size())
        throw (Span::ToSmall());
    return *std::max_element(this->_span.begin(),this->_span.end() - *std::min_element(this->_span.begin(),this->_span.end()));
}
long Span::shortestSpan()
{
    if(2 > this->_span.size())
        throw (Span::ToSmall());
    long shortest = INT_MAX;

    std::vector<int> sortedVec = this->_span;
    std::sort(sortedVec.begin(),sortedVec.end());

    for (size_t i = 0; i < sortedVec.size(); i++)
    {
        if(sortedVec[i] - sortedVec[i - 1] < shortest)
            shortest = sortedVec[i] - sortedVec[i - 1];
    }

    return shortest;
}
void Span::addNumber(unsigned int num)
{
    if(this->_span.size() > this->_n)
        throw(OffLimits());
    this->_span.push_back(num);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if(this->_span.size() + std::distance(begin,end) > this->_n)
        throw(OffLimits());
    this->_span.insert(_span.end(),begin,end);
}

unsigned int Span::getN() const
{
    return this->_n;
}

Span::~Span()
{
}