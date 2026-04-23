#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
private:
    unsigned int _n;
public:
    class OffLimits : public std::exception {
        public:
            const char* what() const throw();
    };
    Span();
    Span(unsigned int size);
    Span(const Span &obj);
    Span& operator=(const Span& other);
    unsigned int getN() const;
    void addNumber(unsigned int num);
    ~Span();
};




#endif