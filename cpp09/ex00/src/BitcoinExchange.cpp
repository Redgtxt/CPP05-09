#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchangeError::BitcoinExchangeError(Type type) : _type(type) {}

const char *BitcoinExchange::BitcoinExchangeError::what() const throw()
{
    switch (_type)
    {
        case FileDoesNotExist:                          return "Error: File does not exist.";
        case FileIsEmpty:                               return "Error: File is empty";
        case InputFirstLineMissing:                     return "Error: Input File should have date | value in the first line";
        default:                                        return "Error: unknown.";
    }
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}


void BitcoinExchange::PopulateDb(const char *argv,std::map<std::string,float>& _map)
{
    std::ifstream file(argv,std::ios::in);
    if(!file)
        throw BitcoinExchange::BitcoinExchangeError(BitcoinExchange::BitcoinExchangeError::FileDoesNotExist);

    
    std::string content;
    if (!std::getline(file, content))
        throw BitcoinExchange::BitcoinExchangeError(BitcoinExchange::BitcoinExchangeError::FileIsEmpty);

    std::string key;
    std::string value;
    float val;
    while (std::getline(file,content))
    {
        std::size_t pos = content.find(',');

        //std::cout << "line: " << content << std::endl;
        //std::cout << "comma pos: " << pos << std::endl;
        key = content.substr(0, pos);
        //std::cout << "key: " << key << std::endl;
        value = content.substr(pos + 1);
        //std::cout << "value: " << value << std::endl;
        val = std::strtof(value.c_str(),NULL);
        _map[key];
        _map[key] = val;
    }
    
    
    file.close();
}

bool isLeapYear(int year) {
    // A leap year is divisible by 4, but not by 100, unless it is also divisible by 400
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool checkFind(std::string content,size_t pos)
{
    if(pos == std::string::npos)
    {
        std::cerr << "Error: bad input => " << content << std::endl;
        return false;
    }
    return true;
}

bool isValidDate(const std::string& date)
{

    //YYYY-01-01
    if(date.length() != 10)
        return false;
    
    if(date[4] != '-' || date[7] != '-')
        return false;
    
    //Checking if all are digits
    for (size_t i = 0; i < date.length(); i++)
    {
        //Bypass -
       if(i == 4 || i == 7)
            continue;
        if(!std::isdigit(date[i]))
            return false;
    }
    
    int year = std::atoi(date.substr(0,4).c_str());
    int month = std::atoi(date.substr(5,2).c_str());
    int day = std::atoi(date.substr(8,2).c_str());
    
    //bitcoin didn't exist before 2009
    if(year < 2009)
        return false;
    
    if(month < 1 || month > 12)
        return false;
    
    if(day < 1 || day > 31)
        return false;

    //Months that have 30 days
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return false;
    }

    if (month == 2) {
        if (isLeapYear(year))
        {
            if (day > 29)
                return false;
        } else
        {
            if (day > 28)
                return false;
        }
    }

    return true;

}

bool isValidValue(const std::string& valueStr,float& outValue)
{
    if(valueStr.empty())
    {
        std::cerr << "Error: bad input => empty value." << std::endl;
        return false;
    }

    //Let's convert the string to float
    char *endptr;
    outValue = std::strtof(valueStr.c_str(),&endptr);

    //If pointer does not point to the null byte something was found 
    if(*endptr != '\0')
    {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return false;
    }

    if(outValue < 0.0f)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    if (outValue > 1000.0f)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::CheckInputFile(const char *filename)
{
    std::ifstream file(filename,std::ios::in);
    if(!file)
        throw BitcoinExchange::BitcoinExchangeError(BitcoinExchange::BitcoinExchangeError::FileDoesNotExist);

    std::string content;
    if (!std::getline(file, content))
        throw BitcoinExchange::BitcoinExchangeError(BitcoinExchange::BitcoinExchangeError::FileIsEmpty);

    if(content != "date | value")
        throw BitcoinExchange::BitcoinExchangeError(BitcoinExchange::BitcoinExchangeError::InputFirstLineMissing);
    

    std::string key;
    std::string value;
    while (std::getline(file,content))
    {
        std::size_t pos = content.find(" | ");

        if(!checkFind(content,pos))
            continue;
        
        key = content.substr(0,pos);
        value = content.substr(pos + 3);
        //std::cout << "key: " << key << std::endl;
        //Dar parse ao valor para ver se a data e valida
        
       // std::cout << "value: " << value << std::endl;
        if(!isValidDate(key))
        {
            std ::cerr << "Error: bad input => " << key << std::endl;
            continue;
        }

        float bitcoinAmount = 0.0f;
        if(!isValidValue(value,bitcoinAmount))
        {
            continue;
        }

        //Fazer a multiplicaçao

        /*
        Lowerbound vai returnar um iterador para o primeiro elemento que e maior ou igual a chave que foi pedida

        pode aconter 3 casos
        Caso 1
        >=
        a data existe ou seja vai returnar a data pois e maior ou igual
        Caso 2
        Data esta no meio mas nao existe
        Vai returnar a data mais proxima ou seja temos de decrementar o iterador 
        --it
        Caso 3
        A data e mais antiga que TUDO na database

        */

        std::map<std::string, float>::iterator it = _bd.lower_bound(key);
        if(it != _bd.end() && it->first == key)
        {
            //Data correta nao preciso de fazer nada pois o iterador ja esta no sitio correto
        }else if(it == _bd.begin())
        {
            std::cerr << "Error: bad input => no data for date earlier than DB start." << std::endl;
            continue;
        }else{
            --it;
        }

        std::cout << key << " => " << bitcoinAmount << " = " << (bitcoinAmount * it->second) << std::endl;
    }
    
    
    file.close();
}

void BitcoinExchange::ValidateFiles(const char *filename)
{

    PopulateDb("data.csv", this->_bd);
    //printMap(this->_bd);
    CheckInputFile(filename);
    //CheckFile(filename, this->_bd);
}