#include "Span.hpp"
#include <vector>

Span::Span() : _n(0)
{
    std::cout << "Default constructor without parameters called" << std::endl;
}

Span::Span(unsigned int size) : _n(size)
{
    std::cout << "Constructor with parameters called" << std::endl;
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
        _vec = other._vec;
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

    std::cout << "--- Printing the vec ---" << std::endl;
    for(size_t i = 0;i < this->_vec.size();i++)
        std::cout << this->_vec[i] << " ";
    std::cout << "\n";
}

long Span::logestSpan()
{
    if(2 > this->_vec.size())
        throw (Span::ToSmall());
    long minElement = *std::min_element(this->_vec.begin(), this->_vec.end());
    long maxElement = *std::max_element(this->_vec.begin(), this->_vec.end());
    return maxElement - minElement;
}
long Span::shortestSpan()
{
    if(2 > this->_vec.size())
        throw (Span::ToSmall());
    long shortest = INT_MAX;

    std::vector<int> sortedVec = this->_vec;
    std::sort(sortedVec.begin(),sortedVec.end());

    for (size_t i = 1; i < sortedVec.size(); i++)
    {
        if(sortedVec[i] - sortedVec[i - 1] < shortest)
            shortest = sortedVec[i] - sortedVec[i - 1];
    }

    return shortest;
}
void Span::addNumber(unsigned int num)
{
    if(this->_vec.size() >= this->_n)
        throw(OffLimits());
    this->_vec.push_back(num);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if(this->_vec.size() + std::distance(begin,end) > this->_n)
        throw(OffLimits());
    this->_vec.insert(_vec.end(),begin,end);
}

unsigned int Span::getN() const
{
    return this->_n;
}

Span::~Span()
{
    std::cout << "Destructor called bye bye" << std::endl;
}