#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
class Span
{
private:
    unsigned int _n;//Size que o vector pode ter
    std::vector<int> _vec;
public:
    class OffLimits : public std::exception {
        public:
            const char* what() const throw();
    };

        class ToSmall : public std::exception {
        public:
            const char* what() const throw();
    };
    
    Span();
    Span(unsigned int size);
    Span(const Span &obj);
    Span& operator=(const Span& other);


    unsigned int getN() const;


    long logestSpan();
    long shortestSpan();
    void addNumber(unsigned int num);
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void printVec();

    
    ~Span();
};




#endif