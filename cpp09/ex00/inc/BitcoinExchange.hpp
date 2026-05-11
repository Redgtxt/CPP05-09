#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <algorithm>
#include <exception>
#include <map>
#include <fstream>
#include <string>
class BitcoinExchange
{
private:
    std::map<std::string,int> _bd;

public:
    BitcoinExchange();
    ~BitcoinExchange();

    void CheckFile(const char *argv);

    class BitcoinExchangeError : public std::exception
    {
    public:
        enum Type {FileDoesNotExist,FileIsEmpty};
        explicit BitcoinExchangeError(Type type);
        virtual const char *what() const throw();
    private:
        Type _type;
    };
};

#endif