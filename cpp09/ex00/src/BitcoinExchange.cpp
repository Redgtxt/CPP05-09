#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchangeError::BitcoinExchangeError(Type type) : _type(type) {}

const char *BitcoinExchange::BitcoinExchangeError::what() const throw()
{
    switch (_type)
    {
        case FileDoesNotExist:     return "Error: File does not exist.";
        case FileIsEmpty:          return "Error: File is empty";
        default:                   return "Error: unknown.";
    }
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::CheckFile(const char *argv)
{
    std::ifstream file(argv,std::ios::in);
    if(!file)
      throw BitcoinExchange::BitcoinExchangeError(BitcoinExchange::BitcoinExchangeError::FileDoesNotExist);

    
    std::string content;
    if (!std::getline(file, content))
        throw BitcoinExchange::BitcoinExchangeError(BitcoinExchange::BitcoinExchangeError::FileIsEmpty);

    std::string key;
    while (std::getline(file,content))
    {
        std::size_t pos = content.find(',');

        std::cout << "line: " << content << std::endl;
        std::cout << "comma pos: " << pos << std::endl;

        key = content.substr(0, pos);
        std::cout << "key: " << key << std::endl;

        this->_bd[key];
    }
    
    
    file.close();
}