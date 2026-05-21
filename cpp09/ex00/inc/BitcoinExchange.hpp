#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <algorithm>
#include <exception>
#include <map>
#include <fstream>
#include <string>
#include <cstdlib> 

class BitcoinExchange
{
    private:
        std::map<std::string,float> _bd;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& obj);
        BitcoinExchange& operator=(const BitcoinExchange& obj);
        ~BitcoinExchange();

        void PopulateDb(const char *argv,std::map<std::string,float>& _map);
        void CheckInputFile(const char *filename);
        void ValidateFiles(const char *filename);

        class BitcoinExchangeError : public std::exception
        {
        public:
            enum Type {FileDoesNotExist,FileIsEmpty,InputFirstLineMissing};
            explicit BitcoinExchangeError(Type type);
            virtual const char *what() const throw();
        private:
            Type _type;
        };
};

#endif