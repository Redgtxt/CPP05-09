#include "ScalarConverter.hpp"

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        std::cout << "Not enough arguments" << std::endl;
        return 1;
    }
    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}